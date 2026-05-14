-- Ciudades que acaban por ‘s’
select city
from sakila.city
where city like "%s";
-- - Ciudades con nombres compuestos
select city
from sakila.city
where city like "% %";
-- Películas con una duración entre 80 y 100
select title, length as duracion
from sakila.film
where length >= 80 and length <= 100;
-- Peliculas con un rental_rate entre 1 y 3
select title, rental_rate
from sakila.film
where rental_rate >= 1 and rental_rate <= 3;
-- Películas con un titulo de más de 12 letras
select title , length(title) as cantLetrasTitulo
from sakila.film
where length(title) > 12;
-- Peliculas con un rating de PG o G
select title, rating
from sakila.film
where rating = "PG" or rating = "G" 
order by rating;
-- Película con menor duración.
select min(length) as peliculaConMenorDuracion
from sakila.film;