drop procedure if exists creerPets;

delimiter ///

create procedure creerPets(nombre int)
begin
	boucle: loop
		insert into pets set name=concat('toto ', nombre), birth_date=date_sub('2011-01-01', interval nombre day);
        set nombre = nombre - 1;
        if nombre = 0 then
			leave boucle;
        end if;
    end loop;
end

///

delimiter ;