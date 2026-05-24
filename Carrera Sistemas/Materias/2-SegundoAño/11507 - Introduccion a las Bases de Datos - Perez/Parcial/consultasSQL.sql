use parcial_virtual;

SELECT * FROM parcial_virtual.peliculas;

-- Carga de datos simple para comprobacion de consultas
insert into peliculas values
(1, "Frozen 1", "Magia", "180", "PG-13"), 
(2, "Avengers (Endgame)", "Accion", 200, "PG-13"),
(3, "Avatar", "Ciencia Ficcion", 210, "PG-13"),
(4, "El Rey Leon", "Animacion", 80, "ATP"),
(5, "Spider-Man - No Way Home", "Accion", 120, "PG-13"),
(6, "Toy Story", "Animacion", 130, "ATP");


-- Consultas SQL
-- 1. Mostrar el título y la duración de todas las películas ordenadas de mayor a menor duración.
select titulo, duracion
from peliculas 
order by duracion desc;

-- 2. Mostrar las películas cuyo título comience con la letra “A” utilizando LIKE
select titulo
from peliculas
where titulo like "A%";

-- 3. Mostrar la película con mayor duración y la de menor duración utilizando MAX y MIN.
-- Consulta para cuando no importa si hay repetidos en los maximos y minimos:
select titulo, duracion
from peliculas
where 
	duracion = (select max(duracion) from peliculas) 
	or 
    duracion = (select min(duracion) from peliculas);
-- Consultas especificas para exactamente un maximo y exactamente 1 minimo:
-- 1 Maximo:
select titulo, duracion as maximo_duracion
from peliculas
where duracion = (select max(duracion) from peliculas)
limit 1;
-- 1 Minimo:
select titulo, duracion as minimo_duracion
from peliculas
where duracion = (select min(duracion) from peliculas)
limit 1;