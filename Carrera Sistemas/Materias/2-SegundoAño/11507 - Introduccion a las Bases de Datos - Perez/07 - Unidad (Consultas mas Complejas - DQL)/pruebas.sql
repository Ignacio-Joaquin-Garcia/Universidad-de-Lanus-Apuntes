SELECT * FROM sakila.film;

select city
from sakila.city
where city like "%s";

select city
from sakila.city
where city like "% %";

select title, length as duracion
from sakila.film
where length >= 80 and length <= 100;

select title, rental_rate
from sakila.film
where rental_rate >= 1 and rental_rate <= 3;

select title , length(title) as cantLetrasTitulo
from sakila.film
where length(title) > 12;

select title, rating
from sakila.film
where rating = "PG" or rating = "G" 
order by rating;

select min(length) as peliculaConMenorDuracion
from sakila.film;

select count(*)
from(
	select rating 
    from sakila.film 
    group by rating
) as rating;



select rating, promedio
from(
	select rating, avg(length) as promedio
    from sakila.film
    group by rating
) as tablaComparacion
where promedio = (
	select max(promedio)
    FROM (
        SELECT AVG(length) AS promedio
        FROM sakila.film
        GROUP BY rating
    ) AS otra
);

select rating, max(promedio) as mayorPromedio
from(
	select rating, avg(length) as promedio
	from sakila.film
	group by rating
) as tablaComparacion;


select max(avg(length))
from sakila.film;





