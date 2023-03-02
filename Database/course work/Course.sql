
-- create sequences

create sequence c_secondary_education;
create sequence c_address;
create sequence c_results_zno;
create sequence c_information_applicant;
create sequence c_specialties;
create sequence c_specialization;
create sequence c_group_student;

-- create tables 

create table secondary_education(
	ID_SECONDARY_EDUCATION int primary key default nextval('c_secondary_education'),
	name_institution char(20),
	number_institution int,
	city char(20)
);

create table address (
	ID_ADDRESS int primary key default nextval('c_address'),
	index_address int,
	territory char(40),
	population_point char(40),
	street char(40),
	home_number int,
	phone_number char(14),
	id_information_applicant int references information_applicant(id_information_applicant)
);

create table results_ZNO (
	ID_RESULTS_ZNO int primary key default nextval('c_results_zno'),
	Ukr_language int,
	Eng_language int,
	Ukr_history int,
	Physics int,
	Geography int
);

create table information_applicant (
	ID_INFORMATION_APPLICANT int primary key default nextval('c_information_applicant'),
	registration_number int,
	PIB char(100),
	date_birth date,
	facilities char(50),
	diploma_medal char(40),
	date_expiration date,
	id_secondary_education int references secondary_education(id_secondary_education),
	id_results_zno int references results_ZNO(id_results_zno),
	id_specialization int references specialization(id_specialization)
);

create table specialties (
	ID_SPECIALTIES int primary key default nextval('c_specialties'),
	name_specialties char(40),
	disciplines char(100)
);

create table specialization (
	ID_SPECIALIZATION int primary key default nextval('c_specialization'),
	name_specialization char(40),
	id_specialties int references specialties(id_specialties)
);

create table group_student (
	ID_GROUP_STUDENT int primary key default nextval('c_group_student'),
	group_name char(10),
	student_count int,
	id_information_applicant int references information_applicant(id_information_applicant),
	id_specialization int references specialization(id_specialization)
);

-- insert 

insert into secondary_education (id_secondary_education, name_institution, number_institution, city)
values (1, 'Гімназія', 3, 'Одеса');
insert into secondary_education (id_secondary_education, name_institution, number_institution, city)
values (2, 'ЗОШ', 75, 'Київ');
insert into secondary_education (id_secondary_education, name_institution, number_institution, city)
values (3, 'Гімназія', 1, 'Одеса');
insert into secondary_education (id_secondary_education, name_institution, number_institution, city)
values (4, 'ЗОШ', 89, 'Львів');
insert into secondary_education (id_secondary_education, name_institution, number_institution, city)
values (5, 'Рішельевский ліцей', 1, 'Одеса');

insert into results_zno (id_results_zno, ukr_language, eng_language, ukr_history, physics, geography)
values (1, 160, 150, 130, 119, 143);
insert into results_zno (id_results_zno, ukr_language, eng_language, ukr_history, physics, geography)
values (2, 143, 170, 127, 134, 164);
insert into results_zno (id_results_zno, ukr_language, eng_language, ukr_history, physics, geography)
values (3, 180, 178, 157, 123, 129);
insert into results_zno (id_results_zno, ukr_language, eng_language, ukr_history, physics, geography)
values (4, 160, 150, 130, 141, 167);
insert into results_zno (id_results_zno, ukr_language, eng_language, ukr_history, physics, geography)
values (5, 160, 150, 130, 110, 178);

insert into address (id_address, index_address, territory, population_point, street, home_number, phone_number, id_information_applicant)
values (1, 6245, 'Приморський район', 'Одеса', 'Пастера', 23, '+380663341234', 1);
insert into address (id_address, index_address, territory, population_point, street, home_number, phone_number, id_information_applicant)
values (2, 987, 'Суворовский район', 'Одеса', 'Наливна', 11, '+380697568998', 3);
insert into address (id_address, index_address, territory, population_point, street, home_number, phone_number, id_information_applicant)
values (3, 4576, 'Франковский район', 'Львів', 'Пекарська', 33, '+380952317856', 4);
insert into address (id_address, index_address, territory, population_point, street, home_number, phone_number, id_information_applicant)
values (4, 2155, 'Соломенский район', 'Київ', 'Волинська', 7, '+3809669784523', 2);
insert into address (id_address, index_address, territory, population_point, street, home_number, phone_number, id_information_applicant)
values (5, 9764, 'Приморський район', 'Одеса', 'Пушкінська', 9, '+380952349812', 5);

insert into specialization (id_specialization, name_specialization, id_specialties)
values (1, 'База даних', 3);
insert into specialization (id_specialization, name_specialization, id_specialties)
values (2, 'Комп`ютерні системи', 1);
insert into specialization (id_specialization, name_specialization, id_specialties)
values (3, 'Комп`ютерні компоненти', 2);

insert into group_student (id_group_student, group_name, student_count, id_information_applican, id_specialization)
values (1, 'AI-215', 10, 13, 2);
insert into group_student (id_group_student, group_name, student_count, id_information_applican, id_specialization)
values (2, 'AC-217', 11, 4, 3);
insert into group_student (id_group_student, group_name, student_count, id_information_applican, id_specialization)
values (3, 'AK-211', 9, 9, 1);

-- SELECT

-- Sort applicants by name specialties 

select name_specialties, name_specialization, id_information_applicant, registration_number, pib, date_birth, facilities, diploma_medal, date_expiration, id_secondary_education, id_results_zno 
		from specialties, specialization, information_applicant 
			where
			specialization.id_specialties = specialties.id_specialties and 
			information_applicant.id_specialization = specialization.id_specialization
			order by name_specialties;

-- select define applicant

select * from information_applicant where pib = 'Смолкін Стефан Ігорович'

-- select disciplines from table specialties

select disciplines from specialties

-- select 10 applicant for sort results zno of Ukrainian language

select * from information_applicant, results_zno
	where information_applicant.id_results_zno = results_zno.id_results_zno
	order by results_zno.ukr_language desc
	limit 10
	
-- select applicant without facilities 
	
select * from information_applicant where facilities != 'Немає'

-- select applicant, who are not from Odessa

select * from information_applicant
	where id_information_applicant in
		(select id_information_applicant from address where population_point != 'Одеса');
		

-- Trigger functions
-- add new applicant

create function information_applicant_class()
	returns trigger
as $$ begin
	insert into class(information_applicant) values (new.id_information_applicant);
	return new;
end;$$
language'plpgsql';

create trigger information_applicant
	after insert on information_applicant
	for each row
	execute procedure information_applicant_class();


-- del applicant

create function information_applicant_del()
	returns trigger
as $$ begin
	update address set information_applicant = null 
		where information_applicant = old.id_information_applicant;
	update group_student set information_applicant = null 
		where information_applicant = old.id_information_applicant;
	return old;
end;$$
language'plpgsql';

create trigger information_applicant_del
	before delete on information_applicant
	for each row
	execute procedure information_applicant_del();

-- Functions 
-- Create applicant

create or replace function create_information_applicants (
	registration_number int,
	PIB char(100),
	date_birth date,
	facilities char(50),
	diploma_medal char(40),
	date_expiration date,
	id_secondary_education int,
	id_results_zno int,
	id_specialization int
)
	returns integer
	as $$
	declare
	id_information_applicant information_applicant.id_information_applicant%type;
	begin
		id_information_applicant := nextval('c_information_applicant');
		insert into information_applicant values (id_information_applicant, registration_number, pib, date_birth, facilities, diploma_medal, 
		date_expiration, id_secondary_education, id_results_zno, id_specialization); 
		raise notice 'information_applicant added';
		return id_information_applicant;
	end;$$
	language'plpgsql';
	
select create_information_applicants (347, 'Смолкін Стефан Ігорович', '2003-07-23', 'Немає', 'Немає','2020-06-01', 3, 4, 2);
select create_information_applicants (102, 'Мелнік Ігор Романович', '2001-03-06', 'Немає', 'Золота медаль','2017-06-01', 2, 2, 1);
select create_information_applicants (231, 'Романов Іван Іванович', '2002-08-26', 'Сирота', 'Немає','2018-06-01', 5, 3, 2);
select create_information_applicants (987, 'Орлов Данило Данилович', '2003-01-10', 'Немає', 'Золота медаль','2019-06-01', 4, 1, 3);
select create_information_applicants (762, 'Могильда Кирило Кирилович', '2003-10-04', 'Без батька', 'Немає','2020-06-01', 1, 5, 1);

select * from information_applicant

-- Update applicant

create or replace function update_information_applicants (
	id_information_applicants int,
	registration_numbers int,
	PIBs char(100),
	date_births date,
	facilitiess char(50),
	diploma_medals char(40),
	date_expirations date,
	id_secondary_educations int,
	id_results_znos int,
	id_specializations int
)
	returns integer
	as $$
	begin
		update information_applicant
		set registration_number = registration_numbers, pib = PIBs,
		date_birth = date_births, facilities = facilitiess,
		diploma_medal = diploma_medals, date_expiration = date_expirations,
		id_secondary_education = id_secondary_educations, id_results_zno = id_results_znos,
		id_specialization = id_specializations
		where information_applicant.id_information_applicant = id_information_applicants;
		raise notice 'information_applicant updated';
		return id_information_applicants;
	end;$$
	language'plpgsql';

select update_information_applicants (4, 1929, 'Орлов Данило Данилович', '2003-12-11', 'Немає', 'Золота медаль','2019-06-01', 4, 1, 3)

-- Create specialties 
	
create or replace function create_specialties (
	name_specialties char(40),
	disciplines char(100)
)
	returns integer
	as $$
	declare
	id_specialties specialties.id_specialties%type;
	begin
		id_specialties := nextval('c_specialties');
		insert into specialties values (id_specialties, name_specialties, disciplines);
		raise notice 'specialties added';
		return id_specialties;
	end;$$
	language'plpgsql';

select create_specialties ('Комп`ютерні науки', 'Укр. мова та літ. , Англ. мова, Історія України');
select create_specialties ('Комп`ютерна інженерія', 'Укр. мова та літ. , Англ. мова, Фізика ');
select create_specialties ('інформаційні технології', 'Укр. мова та літ. , Фізика, Географія');

-- Update specialties 

create or replace function update_specialties (
	id_specialtiess int,
	name_specialtiess char(40),
	discipliness char(100)
)
	returns integer
	as $$
	begin
		update specialties
		set name_specialties = name_specialtiess,
		disciplines = discipliness
		where specialties.id_specialties = id_specialtiess;
		raise notice 'specialties updated';
		return id_specialtiess;
	end;$$
	language'plpgsql';

select update_specialties (3, 'інформаційні технології', 'Укр. мова та літ. , Географія, Фізика');

-- Output spectialties 

create or replace function get_specialties ()
	returns table (
		id_specialties int,
		name_specialties char(40),
		disciplines char(100)
	)
	as $$
	begin
	return query select
	specialties.id_specialties,
	specialties.name_specialties,
	specialties.disciplines
	from specialties order by specialties.id_specialties;
	end;$$
	language'plpgsql';

select get_specialties()

-- Output specialization 

create or replace function get_specialization ()
	returns table (
		id_specialization int,
		name_specialization char(40),
		id_specialties int
	)
	as $$
	begin
	return query select
	specialization.id_specialization,
	specialization.name_specialization,
	specialization.id_specialties
	from specialization;
	end;$$
	language'plpgsql';

select get_specialization()
	
-- Update specialization 	
	
create or replace function update_specialization (
	id_specializations int,
	name_specializations char(40),
	id_specialtiess int
)
	returns integer
	as $$
	begin
		update specialization
		set name_specialization = name_specializations,
		id_specialties = id_specialtiess
		where specialization.id_specialization = id_specializations;
		raise notice 'specialization updated';
		return id_specializations;
	end;$$
	language'plpgsql';

select update_specialization (1, 'База даних БД', 3)
select update_specialization (2, 'Комп`ютерні системи КС', 1)
select update_specialization (3, 'Комп`ютерні компоненти КП', 2)

-- Output information_applicant who have medals or diploma  

create or replace function get_information_applicant_medals ()
	returns table (
		ID_information_applicant int,
		registration_number int,
		PIB char(100),
		date_birth date,
		facilities char(50),
		diploma_medal char(40),
		date_expiration date,
		id_secondary_education int,
		id_results_zno int,
		id_specialization int
	)
	as $$
	begin
	return query select
	information_applicant.id_information_applicant,
	information_applicant.registration_number,
	information_applicant.PIB,
	information_applicant.date_birth,
	information_applicant.facilities,
	information_applicant.diploma_medal,
	information_applicant.date_expiration,
	information_applicant.id_secondary_education,
	information_applicant.id_results_zno,
	information_applicant.id_specialization
	from information_applicant where information_applicant.diploma_medal != 'Немає';
	end;$$
	language'plpgsql';

select get_information_applicant_medals ()


-- create users

create user user_one;
create user user_two;
create user user_third;


grant select, insert on all tables in schema public to user_one;

grant all privileges on all tables in schema public to user_two;

grant select on information_applicant to user_third;


