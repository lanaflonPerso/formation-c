insert into races set `name`='Pikcahoun';
insert into races set `name`='Tortuninja';
select * from races;
insert into pets set `name`='Sprinter', race_id=1;
insert into pets set `name`='Leonardo', race_id=2;
insert into races set `name`='Rat';
insert into pets set `name`='Splinter', race_id=3;
select * from pets;





select p.id, p.name, r.name as `race` from pets p join races r on p.race_id=r.id;

select * from pets p, races r where p.race_id=r.id;

select * from pets, races;
