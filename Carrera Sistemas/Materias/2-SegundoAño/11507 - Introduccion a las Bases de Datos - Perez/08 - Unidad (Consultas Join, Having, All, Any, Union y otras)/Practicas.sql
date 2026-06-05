/***************************************************************************************
Intro BD 2020 - Sintaxis básica de dialecto SQL MySQL:
Manual de consulta MySQL: https://dev.mysql.com/doc/refman/8.0/en/
Apunte 5-Elementos de SQL 3
***************************************************************************************/

-- creamos la tabla detalle_venta (¿Qué representa esta tabla?)
create table detalle_venta(
	venta_numero int,
	producto_codigo int,
	precio_unitario decimal(10,2),
	cantidad int,
	primary key (venta_numero, producto_codigo),
	foreign key (venta_numero) references venta(numero),
	foreign key (producto_codigo) references producto(codigo)
);

/***************************************************************************************
Práctica:
Agregar el detalle de las ventas en detalle_venta de la siguiente manera:
# venta_numero, producto_codigo, precio_unitario, cantidad
1, 2, 20.00, 3
1, 3, 300.00, 1
2, 1, 10.00, 2
2, 4, 120.00, 1
3, 2, 20.00, 3
3, 5, 90.00, 2
4, 2, 20.00, 2
5, 1, 8.00, 4
5, 5, 70.00, 1
6, 2, 20.00, 2
6, 3, 300.00, 1
6, 4, 120.00, 1

Intentar agregar el siguiente registro y ver que ocurre:
7, 4, 120.00, 2 

Intentar agregar el siguiente registro y ver que ocurre:
4, 2, 20.00, 2
***************************************************************************************/

-- Consultas con operaciones y agregación
-- Total facturado para un item determinado de una venta:
select precio_unitario*cantidad as total from detalle_venta
where venta_numero=1 and producto_codigo=2;


-- Total facturado por la farmacia
select sum(precio_unitario*cantidad) as total from detalle_venta;


-- Total facturado en una venta (sum)
select sum(precio_unitario*cantidad) as total from detalle_venta 
where venta_numero=1;


-- Total facturado discriminado venta por venta (sum con group by):
select venta_numero, sum(precio_unitario*cantidad) as total from detalle_venta
group by venta_numero;


-- cantidad de ventas total (count)
select count(*) as cant_ventas from venta;


-- cantidad de ventas por dia total (count con group by)
select fecha, count(*) as cant_ventas from venta
group by fecha;


-- Total facturado por día: (inner join, sum, group by)
select v.fecha, sum(precio_unitario*cantidad) as total 
from detalle_venta d
inner join venta v on d.venta_numero=v.numero
group by v.fecha;


-- precio promedio de productos vendidos por producto (inner join, avg, group by)
select p.nombre, avg(dv.precio_unitario) as precio_promedio, p.precio as precio_lista 
from producto p 
inner join detalle_venta dv on p.codigo=dv.producto_codigo
group by p.codigo;


-- precio promedio de productos vendidos entre fecha (inner join, avg, group by, between)
select p.nombre, avg(dv.precio_unitario) as precio_promedio, p.precio as precio_lista 
from producto p 
inner join detalle_venta dv on p.codigo=dv.producto_codigo
inner join venta v on dv.venta_numero=v.numero 
where v.fecha between '2020-08-22' and '2020-08-23'
group by p.codigo;


-- precio promedio de productos vendidos entre fecha (inner join, avg, group by, filtro)
select p.nombre, avg(dv.precio_unitario) as precio_promedio, p.precio as precio_lista 
from producto p 
inner join detalle_venta dv on p.codigo=dv.producto_codigo
inner join venta v on dv.venta_numero=v.numero 
where v.fecha >= '2020-08-22' and v.fecha<='2020-08-23'
group by p.codigo;


-- artículos vendidos más baratos que el precio de lista
select v.numero, p.nombre, p.descripcion, p.precio as precio_lista, 
dv.precio_unitario as precio_venta, dv.precio_unitario-p.precio as diferencia
from venta v 
inner join detalle_venta dv on v.numero=dv.venta_numero
inner join producto p on dv.producto_codigo=p.codigo
where dv.precio_unitario-p.precio<0;


-- total facturado en el año (inner join, sum, where)
select year(v.fecha) as año, sum(precio_unitario*cantidad) as total 
from detalle_venta d
inner join venta v on d.venta_numero=v.numero
group by year(v.fecha);

-- también: group by año;

-- Total facturado mayor a $100 (sum con group by y having):
select venta_numero, sum(precio_unitario*cantidad) as total from detalle_venta
group by venta_numero
having total>100;


-- Total facturado mayor a $100 (sum con group by y having, ordenado por total):
select venta_numero, sum(precio_unitario*cantidad) as total from detalle_venta
group by venta_numero
having total>100
order by total;


-- Total facturado mayor a $100 (sum con group by y having, ordenado por total):
select venta_numero, sum(precio_unitario*cantidad) as total from detalle_venta
group by venta_numero
having total>100
order by total desc;


/***************************************************************************************
Práctica:
Realizar una consulta que devuelva el total facturado del
producto 'Amoxidal 500' pero eligiendo el producto por nombre 
(no por código). 

Realizar una consulta que devuelva el total facturado al cliente con dni 
22222222 (dni, total)

Realizar una consulta que devuelva la cantidad de ventas realizadas al 
cliente con dni 12345678. Cantidad de ventas es cada ticket emitido, no cada 
producto vendido. (dni, cantidad)

Realizar una consulta que devuelva las ventas realizadas a los clientes con apellido
'Belgrano', discriminado venta por venta. (apellido, numero de venta, total)

Realizar una consulta que devuelva la cantidad de ventas realizadas a los clientes 
con apellido 'Moreno'. (apellido, cantidad)

Traer el total facturado por obra social. (nombre de obra social, total)

Idem a la anterior, pero filtrando desde el 1/1/2020 hasta el 30/8/2020. 

Traer el total facturado a clientes que no tienen obra social
(sólo mostrar total)

Realizar una consulta que devuelva el total de las ventas realizadas a 
clientes de la calle Sáenz (se debe filtrar por nombre de calle="Sáenz").
(apellido, nombre, total vendido)

Realizar una consulta que devuelva las ventas realizadas a clientes de la 
calle Sáenz (se debe filtrar por nombre de calle="Sáenz", discriminada 
venta por venta (apellido, nombre, venta_numero, total)

Realizar una consulta que devuelva los productos vendidos. Se debe mostrar cada 
producto una sola vez (Ayuda: hay que agrupar por producto)
(código, nombre, descripcion)

Realizar una consulta que devuelva el total de ventas sin detallar realizadas 
a clientes de la obra social IOMA que vivan en la provincia de Buenos Aires. 
Consultar por nombre de obra social y de provincia
(nombre provincia, nombre obra social, total)

Realizar una consulta que devuelva cuántas son las ventas de la consulta anterior
(nombre provincia, nombre obra social, cantidad)
***************************************************************************************/