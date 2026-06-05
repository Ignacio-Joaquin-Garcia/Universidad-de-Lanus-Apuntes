use `garciaignaciojoaquin_46940086`;
-- 0. Hacemos Index sobre Personas.nombre para que todas las consultas funcionen más rapido (la memoria no es un problema). 
alter table personas add index (nombre);
-- Ahora las consultas sobre nombres de Personas seran busquedas binarias en vez de for(N)

-- 1. Consulta de todos los Jugadores y sus selecciones
select p.nombre, p.apellido, s.nombre as selecciones
from personas p, jugadores j, selecciones s
where p.id_persona = j.personas_id_persona
and j.selecciones_id_seleccion = s.id_seleccion;

-- Mismas Consultas pero esta vez uniendo las tablas mediante JOIN
select p.nombre, p.apellido, s.nombre
from personas p
inner join jugadores j 
	on p.id_persona = j.Personas_id_persona
inner join selecciones s
	on j.Selecciones_id_seleccion = s.id_seleccion;

/* 
	Si Hubiera nombrado las fk de cada tabla con el mismo nombre que las pk podria usar Join + Using de la siguiente manera:
    
	select p.nombre, p.apellido, s.nombre
	from Personas p
	join Jugadores j USING(id_persona)
	join Selecciones s USING(id_seleccion);
    
    Cabe resaltar que en mi caso no lo hice porque me gusta saber de que tabla vienen las fk
*/

-- 2. Consulta de todos los Jugadores de determinada seleccion
select p.nombre, p.apellido, s.nombre as selecciones
from personas p
inner join jugadores j 
	on p.id_persona = j.Personas_id_persona
inner join selecciones s
	on j.Selecciones_id_seleccion = s.id_seleccion
where s.nombre = "Argentina";


-- 3. Ver las figuritas que le falta a determinado usuario
select f.id_figurita, f.numero, f.descripcion
from figuritas f
where not exists(
		select *
		from Figuritas_has_Coleccion fc
		where fc.Figuritas_id_figurita = f.id_figurita
		and fc.Colecciones_Usuario_Personas_id_persona = 1
    );

-- Misma consulta pero esta vez viendo las figuritas que el usuario posee
select f.id_figurita, f.numero, f.descripcion
from figuritas f
where exists(
		select *
		from Figuritas_has_Coleccion fc
		where fc.Figuritas_id_figurita = f.id_figurita
		and fc.Colecciones_Usuario_Personas_id_persona = 1
	);

-- 4. Cant de figuritas por Paquete y Tipo de Paquete
select a.nombre as album, pf.cantidad_figuritas as cant_figuritas_paquete, pf.tipo
from albumes a
inner join paquetes_de_figuritas pf
	on pf.Albumes_id_album = a.id_album;

-- 5. Cuenta cantidad de figuritas agrupada por album
select a.nombre, count(*) as cantidad_figuritas
from figuritas f
inner join albumes a
	on a.id_album = f.Albumes_id_album
group by a.nombre;

-- 6.
-- Primer consultas la cual da todas las selecciones con sus jugadores
select s.nombre, count(*) as cant_jugadores
from personas p
inner join Jugadores j
	on p.id_persona = j.Personas_id_persona
inner join selecciones s
	on s.id_seleccion = j.Selecciones_id_seleccion
group by s.nombre;

-- Union de la anterior consulta + subconsulta que da la seleccion con mas jugadores = Selecciones con más jugadores
select s.nombre, count(*) as cant_jugadores
from personas p
inner join Jugadores j
	on p.id_persona = j.Personas_id_persona
inner join selecciones s
	on s.id_seleccion = j.Selecciones_id_seleccion
group by s.nombre
having count(*) = (
	select max(cantidad)
    from (
        select count(*) as cantidad
        from Jugadores
        group by Selecciones_id_seleccion
    ) t
);


-- 7. Busqueda de Jugadores por posicion
--  Busqueda Delanteros
select p.nombre, j.posicion
from personas p
inner join jugadores j
	on p.id_persona = j.Personas_id_persona
where posicion = "Delantero";
-- Busqueda posiciones terminadas en "ero" ordenadas por posicion
select p.nombre, j.posicion
from personas p
inner join jugadores j
	on p.id_persona = j.Personas_id_persona
where j.posicion like "%ero"
order by j.posicion;
-- Busqueda de capitanes por seleccion
select s.nombre as seleccion, p.nombre, j.posicion
from personas p
inner join jugadores j
	on p.id_persona = j.Personas_id_persona
inner join selecciones s
	on s.id_seleccion = j.Selecciones_id_seleccion
where es_capitan = True;

-- 8. Promedio de Rareza en Figuritas + Minimo + Maximo en una consulta
select avg(rareza) as promedio_rareza
from figuritas
	union
select min(rareza) as min_rareza
from figuritas
	union
select max(rareza) as min_rareza
from figuritas;

-- 9. Mostrar las figuritas cuyo número es mayor que cualquier número de figurita perteneciente al álbum 'Mundial 2022'.
-- Primero Subconsulta que de los numeros de las figuritas del album 2022
select f.numero
from figuritas f
inner join albumes a
	on a.id_album = f.Albumes_id_album
where a.nombre = "Mundial 2022";
-- Unimos con esta subconsulta + comparacion con el primero numeor que encuentre any
select f.numero, f.descripcion
from figuritas f
where numero > any(
	select f.numero
    from figuritas f
	inner join albumes a
		on a.id_album = f.Albumes_id_album
	where a.nombre = "Mundial 2022"
);
-- Caso con >= ALL para que nos de el numero de figurita maximo
select f.numero, f.descripcion
from figuritas f
where numero >= all(
	select f.numero
    from figuritas f
	inner join albumes a
		on a.id_album = f.Albumes_id_album
	where a.nombre = "Mundial 2022"
);

-- 10. Consulta de Albumes salidos entre 1990 y 2010
select *
from albumes
where anio >= "1990-01-01" and anio <= "2010-12-31";

-- Mejor utilizando between
select *
from albumes
where anio between "1990-01-01" and "2010-12-31";

-- Mejor sumandole la funcion Year
select *
from albumes
where year(anio) between 1990 and 2010;