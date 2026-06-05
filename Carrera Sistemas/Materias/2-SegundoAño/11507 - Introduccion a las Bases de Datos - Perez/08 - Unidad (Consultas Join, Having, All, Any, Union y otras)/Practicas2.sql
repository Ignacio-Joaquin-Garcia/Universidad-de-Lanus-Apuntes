/***************************************************************************************
Intro BD 2020 - Sintaxis básica de dialecto SQL MySQL:
Manual de consulta MySQL: https://dev.mysql.com/doc/refman/8.0/en/
***************************************************************************************/

/***************************************************************************************
Apunte 3-Elementos de SQL 2
***************************************************************************************/

-- Creación de esquema:
create schema if not exists farmacia;

-- Para mostrar los esquemas existentes en la BD:
show schemas;

-- Para eliminar un esquema:
drop schema farmacia;

-- Para establecer el esquema sobre el que trabajamos:
use farmacia;

-- Para consultar cual es el esquema en uso:
select schema();

-- Creamos la tabla obra_social en el esquema activo:
create table obra_social(
	codigo int primary key,
	nombre varchar(45) not null,
	descripcion varchar(100) not null
);

-- Para mostrar la definición de la tabla:
show create table obra_social;

-- para mostrar las tablas definidas en el esquema 
-- activo:
show tables;

-- para eliminar una tabla
drop table obra_social;

-- Para renombrar una tabla:
alter table obra_social rename to obra;
alter table obra rename to obra_social;

-- Para cambiar la columna descripcion a descr
-- (hay que indicar todos los datos de la columna):
alter table obra_social change column descripcion descr varchar(100);
alter table obra_social change column descr descripcion varchar(100);

-- Insertamos datos en la tabla:
insert into obra_social 
	values(1,"PAMI","Programa de Atención Médica Integral");
-- Intentamos insertar con la misma PK:
insert into obra_social 
	values(1,"IOMA","Instituto de Obra Medico Asistencial");

insert into obra_social (codigo, nombre, descripcion) 
	values(2,"IOMA","Instituto de Obra Medico Asistencial");

insert into obra_social (codigo, nombre, descripcion) 
	values(3,"OSECAC","Obra Social de Empleados de Comercio");

-- Consultamos los registos insertados
select * from obra_social;

/***************************************************************************************
Práctica:
Hacer lo mismo para tablas calle, localidad y provincia. 
Agregar en provincia: (1, Buenos Aires) y (2, CABA) 
Agregar en localidad: (1, Lanús), (2, Pompeya), (3, Avellaneda)
Agregar en calles: (1, 9 de Julio) , (2, Hipólito Yrigoyen) , (3, Mitre), (4, Sáenz).
Para cada una  de ellas:
crearla, eliminarla, crearla nuevamente, 
cambiar el nombre y volver a cambiarlo al original.
cambiar el nombre de alguna columna y volver a cambiarlo al original,
agregar los datos especificados, 
consultar y verificar que los datos hayan ingresado.
***************************************************************************************/

/***************************************************************************************
Apunte 4-Elementos de SQL 2
***************************************************************************************/

-- Creamos la tabla cliente:

create table cliente(
	dni int primary key,
	apellido varchar(45) not null,
	nombre varchar(45)not null,
	calle_idcalle int not null,
	localidad_idlocalidad int not null,
	provincia_idprovincia int not null,
    numero_calle int not null,
	foreign key (calle_idcalle) references calle(idcalle),
    foreign key (localidad_idlocalidad) references localidad(idlocalidad),
    foreign key (provincia_idprovincia) references provincia(idprovincia)
);

-- Mostramos definición:
show create table cliente;

-- Agregamos registros:
insert into cliente values(12345678, "Belgrano", "Manuel", 1,1,1,2345);
insert into cliente values(23456789, "Saavedra", "Cornelio",1,1,1,1234); 
insert into cliente values(44444444, "Moreno", "Mariano", 3,3,1,3333);
insert into cliente values(33333333, "Larrea", "Juan", 4,2,2,2345);
insert into cliente values(22222222, "Moreno", "Manuel", 4,2,2,7777);

-- Mostramos clientes:
select * from cliente; -- todos los clientes
select dni,apellido from cliente;-- solo dni y apellido

-- Consultamos registros por dni:
select apellido,nombre from cliente where dni=12345678;

-- Consultamos registros por apellido:
select * from cliente where cliente.apellido="Saavedra";

-- Consultamos clientes de la calle 9 de julio
select * from cliente where calle_idcalle=1;

-- Consultamos clientes de la calle 9 de Julio con el número 2345
select * from cliente where calle_idcalle=1 and numero_calle=2345;

-- Consultamos clientes que vivan en la calle 9 de Julio 
-- o en la calle Mitre
select * from cliente where calle_idcalle=1 or calle_idcalle=3;

-- agregamos obras sociales a los clientes
-- creamos la tabla intermedia que representa la relación opcional 1:n entre cliente y obra social 
create table cliente_tiene_obra_social(
	cliente_dni int primary key,
	obra_social_codigo int not null,
	nro_afiliado int not null,
	foreign key (cliente_dni) references cliente(dni),
    foreign key (obra_social_codigo) references obra_social(codigo)
);

-- Insertamos datos en la tabla. El cliente Cornelio Saavedra no tiene obra social
-- por ello no existe un registro con su dni en la misma
insert into cliente_tiene_obra_social values (22222222, 2, 11223344);
insert into cliente_tiene_obra_social values (33333333, 2, 33445566);
insert into cliente_tiene_obra_social values (44444444, 2, 12356987);
insert into cliente_tiene_obra_social values (12345678,  1, 87654321);


-- Consultas más complejas (joins)

-- Consultamos todos los clientes con su calle usando alias de tabla
-- Inner join: todos los registros de una tabla con correlato en la otra
select c.dni, c.apellido, c.nombre, ca.nombre, c.numero_calle from 
cliente c inner join calle ca on c.calle_idcalle=ca.idcalle;

-- igual, definiendo un alias para el campo c.nombre y numero_calle (con as)
select c.dni, c.apellido, c.nombre, ca.nombre as calle, c.numero_calle as numero from cliente c 
	inner join calle ca on c.calle_idcalle=ca.idcalle;

-- inner join con filtro por nombre de localidad
select c.dni, c.apellido, c.nombre, l.nombre as Localidad from cliente c 
	inner join localidad l on c.localidad_idlocalidad=l.idlocalidad
where l.nombre="Avellaneda";

-- Left join: Todos los registros de la izquierda y sólo los de la 
-- derecha que participan en la relación.
select ca.nombre as calle, dni, apellido, c.nombre from calle ca
	left join cliente c on ca.idcalle=c.calle_idcalle;

-- Right join: Todos los registros de la derecha y los de la izquierda que 
-- participan en la relación.
select cos.nro_afiliado, dni, apellido, c.nombre from cliente_tiene_obra_social cos
	right join cliente c on c.dni=cos.cliente_dni;

-- Noten como un right join se puede escribir como un left join y viceversa.
-- esta consulta es similar a la anterior
select cos.nro_afiliado, dni, apellido, c.nombre from cliente c 
	left join cliente_tiene_obra_social cos on c.dni=cos.cliente_dni;

-- Consultas aún más complejas:
-- joins múltiples: Queremos consultar todos los clientes de IOMA:
select c.dni, c.apellido, c.nombre, o.nombre
	from cliente c 
    inner join cliente_tiene_obra_social co on c.dni=co.cliente_dni
	inner join obra_social o on co.obra_social_codigo=o.codigo
	where o.nombre="IOMA";

/***************************************************************************************
Práctica:
consultar por:
Todos los clientes con la siguiente forma:
dni, apellido,nombre,calle,numero,localidad,provincia :
12345678, Belgrano, Manuel, 9 de julio, 2345, Lanús, Buenos Aires
...etc.

Igual que la anterior pero sólo de la provincia de Buenos Aires
Igual que la primera pero sólo de la calle 9 de julio
Igual que la primera pero sólo el dni 33333333 
Igual que la primera pero sólo de las localidades de avellaneda y lanus (filtrar por "Avellaneda" y "Lanús")
Igual que la primera pero sólo los clientes de PAMI y IOMA (filtrar por "PAMI" y "IOMA")
Igual que la primera pero sólo los clientes de IOMA que vivan en la calle Mitre (filtrar por "PAMI" y "Mitre")


Crear las tablas laboratorio y producto
insertar los siguientes datos:
laboratorio:
codigo, nombre
1, 'Bayer'
2, 'Roemmers'
3, 'Farma'

producto:
codigo, nombre, descripcion, precio, laboratorio_codigo
1, 'Bayaspirina', 'Aspirina por tira de 10 unidades', 10, 1
2, 'Ibuprofeno', 'Ibuprofeno por tira de 6 unidades', 20, 3
3, 'Amoxidal 500', 'Antibiótico de amplio espectro', 300, 2
4, 'Redoxon', 'Complemento vitamínico', 120, '1'
5, 'Atomo', 'Crema desinflamante', 90, 3

Crear tabla venta. Insertar los siguientes datos:
numero, fecha, cliente_dni
1, '18-04-20', 12345678
2, '18-04-20', 33333333
3, '18-04-22', 22222222
4, '18-04-22', 44444444
5, '18-04-22', 12456789
6, '18-04-23', 12345678
***************************************************************************************/


/***************************************************************************************
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


-- Total facturado por día: (inner join, sum, group by)
select v.fecha, sum(precio_unitario*cantidad) as total 
from detalle_venta d
inner join venta v on d.venta_numero=v.numero
group by v.fecha;


-- cantidad de ventas total (count)
select count(*) as cant_ventas from venta;


-- cantidad de ventas por dia total (count con group by)
select fecha, count(*) as cant_ventas from venta
group by fecha;


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
Realizar una consulta que devuelva el total facturado por el
producto 'Amoxidal 500' pero eligiendo el producto por nombre 
(no por código). 

Realizar una consulta que devuelva el total facturado al cliente con dni 
22222222

Realizar una consulta que devuelva la cantidad de ventas realizadas al 
cliente con dni 12345678. Cantidad de ventas es cada ticket emitido, no cada 
producto vendido

Realizar una consulta que devuelva las ventas realizadas a los clientes con apellido
'Belgrano', discriminado venta por venta. La consulta debe mostrar: venta_numero, total

Realizar una consulta que devuelva la cantidad de ventas realizadas a los clientes 
con apellido 'Moreno'. La consulta debe mostrar un campo indicando la cantidad 
de ventas

Traer el total facturado por obra social. Se debe indicar
nombre de obra social, monto total.

Idem a la anterior, pero filtrando desde el 1/1/2020 hasta el 30/8/2020. 

Traer el total facturado a clientes que no tienen obra social

Realizar una consulta que devuelva las ventas realizadas a clientes de la 
calle Sáenz (se debe filtrar por nombre de calle="Sáenz")

Realizar una consulta que devuelva las ventas realizadas a clientes de la 
calle Sáenz (se debe filtrar por nombre de calle="Sáenz", discriminada 
venta por venta (venta_numero, total)

Realizar una consulta que devuelva los productos vendidos. Se debe mostrar cada 
producto una sola vez (Ayuda: hay que agrupar por producto)

Realizar una consulta que devuelva el total de ventas sin detallar realizadas 
a clientes de la obra social IOMA que vivan en la provincia de Buenos Aires. 
Consultar por nombre de obra social y de provincia

Realizar una consulta que devuelva cuántas son las ventas de la consulta anterior

***************************************************************************************/

/***************************************************************************************
Apunte 6-Elementos de SQL 4
***************************************************************************************/

-- Problema con group by en MySQL (consulta incorrecta):
select venta_numero, venta.fecha, sum(precio_unitario*cantidad) as total 
from detalle_venta
inner join venta on venta.numero=detalle_venta.venta_numero;

-- Campos en select con dependencias funcionales con un campo en group by:
select c.dni,sum(precio_unitario*cantidad) as total_facturado, c.nombre, c.apellido
from detalle_venta dv
inner join venta v on dv.venta_numero=v.numero
inner join cliente c on v.cliente_dni=c.dni
group by c.dni;

-- Campos en select sin dependencia funcional con algún campo en group by (incorrecta)
-- debe devolver error, si no es así, verificar sql_mode:
select c.dni,sum(precio_unitario*cantidad) as total_facturado, c.nombre, c.apellido, v.fecha
from detalle_venta dv
inner join venta v on dv.venta_numero=v.numero
inner join cliente c on v.cliente_dni=c.dni
group by c.dni;


-- Campos en select sin dependencia funcional con alguno en group by,
-- pero en función de agregación:
select c.dni,sum(precio_unitario*cantidad) as total_facturado, c.nombre, c.apellido,
max(v.fecha) as fecha_ultima_venta
from detalle_venta dv
inner join venta v on dv.venta_numero=v.numero
right join cliente c on v.cliente_dni=c.dni
left join cliente_tiene_obra_social cos on c.dni=cos.cliente_dni
group by c.dni;

/***************************************************************************************
Modificamos (update) registros
******************************************************************/
-- agregamos 20% al precio de todos los productos
update producto set precio=precio*1.2; 

select * from producto;

-- agregamos 15% al precio de los productos Bayer
update producto set precio=precio*1.15 
	where laboratorio_codigo=1;

select * from producto;

-- agregamos 10% a un producto determinado
update producto set precio=precio*1.1 
	where nombre="Amoxidal 500";

select * from producto;

-- agregamos 10% a los productos cuyo precio sea >150
update producto set precio=precio*1.1 
	where precio>150;

select * from producto;

-- podemos actualizar varios campos a la vez separando con comas.
-- aquí utilizamos una función de MySQL para concatenar dos strings
-- year, sum, count, avg también son funciones. 
-- Listado de funciones de MySQL:
-- https://dev.mysql.com/doc/refman/8.0/en/sql-function-reference.html
update producto set precio=precio*1.1, descripcion=concat(descripcion," nueva fórmula")
	where nombre="Amoxidal 500";

select * from producto;

/***************************************************************************************
Eliminamos (delete) registros
***************************************************************************************/

-- damos de alta una obra social para luego eliminarla
insert into obra_social (codigo, nombre, descripcion) 
	values(4,"OSPAPEL","Obra Social del personal del papel");

select * from obra_social;

-- la eliminamos
delete from obra_social where codigo=4;

select * from obra_social;

-- si no especificamos filtro, podemos borrar todas las 
-- obras sociales
delete from obra_social;
-- Se pudo? Por qué?

/***************************************************************************************
Práctica:

Realizar una consulta que traiga el total de las ventas de un cliente, indicando apellido, 
nombre, dni, localidad y total de ventas.

Realizar una consulta que traiga el total de las ventas por provincia, indicando provincia, 
total de ventas.

Realizar una consulta que devuelva el promedio de precio de venta por producto, mostrando 
producto, precio promedio. El precio de venta es el precio con que se vendió, no el precio 
de lista.

Realizar una consulta que traiga totales de venta por provincia y obra social, indicando
provincia, codigo de obra social, nombre de obra social, descripcion de obra social, 
total venta.

Realizar una consulta que le cambie la obra social al cliente con dni 22222222.

Realizar una consulta que retorne la obra social del cliente con dni 22222222 a la 
original (IOMA).

Realizar las consultas necesarias para retornar los precios de lista de los productos 
a sus valores originales

Realizar una consulta que modifique al cliente Mariano Moreno para que quede sin obra
social

Realizar una consulta que asigne nuevamente al cliente Mariano Moreno su obra social
original y su número de afiliado (IOMA, 12356987)

Crear una venta número 7, de fecha  25/08/2020, al cliente Cornelio Saavedra, con los 
siguientes productos (producto, cantidad):

Amoxidal 500, 3
Bayaspirina, 10
Redoxon, 1

Los precios deben ser los precios de lista

Crear una consulta que Modifique el precio del artículo Redoxon de la venta 7 a $200

Crear las consultas necesarias para eliminar completamente la venta 7, incluyendo su
detalle. 

***************************************************************************************/

