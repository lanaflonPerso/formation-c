/**
QUESTION 1
*/

/* nombre de villes par pays */
select country.country as 'Pays', count(city.city_id) as 'Nombre de villes' from country left join city
	on country.country_id=city.country_id
    group by country.country_id;

/**
QUESTION 2
*/

/* quels films ont fait participer au moins un acteur dont le nom de famille contient 'SL' */
select
	f.title,
    count(f.film_id) as 'NbActeursMatchant',
    group_concat(concat(a.actor_id, ' ', a.first_name, ' ', a.last_name) separator ', ') as 'liste des acteurs'
from 
	(actor a join film_actor fa on a.actor_id=fa.actor_id)
		join film f on fa.film_id=f.film_id
where a.last_name like '%SL%'
group by f.film_id;

/* combien de films ont fait participer au moins un acteur dont le nom de famille contient 'SL' */
select count(*) as 'NombreDeFilms'
from
	(
		select
			fa.film_id
		from 
			actor a join film_actor fa on a.actor_id=fa.actor_id
		where a.last_name like '%SL%'
		group by fa.film_id
    ) liste_films;

/**
QUESTION 3
*/
    
/* quel est le nombre de films par acteur */
create view nb_films_par_acteur
as
	select
		a.actor_id, a.first_name, a.last_name, count(*) as 'NbFilms'
	from actor a join film_actor fa on a.actor_id=fa.actor_id
	group by a.actor_id;

select * from nb_films_par_acteur;

/* quels acteurs ont participé au plus de films */
/* allez voir cet excellent billet : http://www.lafabriquedecode.com/blog/2013/06/mysql-max/*/
select * from nb_films_par_acteur
where
	NbFilms=(select max(NbFilms) from nb_films_par_acteur);

/**
QUESTION 4
*/

/* quels films ont fait participé le plus d'acteurs */
select *
from
	(
		select 
			f.film_id,
			f.title,
			count(f.film_id) as 'NbActeurs'
		from film f join film_actor fa on f.film_id=fa.film_id
		group by f.film_id
	) fff
where fff.NbActeurs=
	(
		/* Attention, ce n'est pas bien de dupliquer du code !! */
		select max(NbActeurs) from
			(
				select 
					count(f.film_id) as 'NbActeurs'
				from film f join film_actor fa on f.film_id=fa.film_id
				group by f.film_id
            ) nbActeursParFilms
	);
