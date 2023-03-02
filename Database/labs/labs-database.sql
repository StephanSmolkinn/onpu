
-- Lab 3 (create table, insert, update info)

create table employee_dormitory (
	ID_EMPLOYEE_DORMITORY int primary key,
	PIB char(40),
	position_Employee varchar(10),
	Work_time float,
	Date_birth DATE,
	Experience int
);

create table conditionroom (
	ID_CONDITIONROOM int primary key,
	condition_room char(10),
	condition_furniture char(10),
	condition_techniques char(10)
);


create table room (
	ID_ROOM int primary key,
	view_room varchar(30),
	size_room float,
	count_room int,
	CONDITIONROOM_ID int,
	EMPLOYEE_DORMITORY_ID int,
	foreign key (CONDITIONROOM_ID) references conditionroom (ID_CONDITIONROOM),
	foreign key (EMPLOYEE_DORMITORY_ID) references employee_dormitory (ID_EMPLOYEE_DORMITORY)
);

create table student (
	ID_STUDENT int primary key,
	PIB varchar(40),
	group_student int,
	residence varchar(20),
	phone_number char(10),
	ROOM_ID int,
	foreign key (ROOM_ID) references room (ID_ROOM)
);

create table equipment_rooms (
	ID_EQUIPMENT_ROOMS int primary key,
	name_room char(10),
	category char(10),
	count_equipment int,
	ROOM_ID int,
	foreign key (ROOM_ID) references room (ID_ROOM)
);


insert into employee_dormitory (id_employee_dormitory, pib , position_employee, work_time, date_birth,
								experience) values (1, 'Romanova Maria Genadievna', 'cook', 6, '15-7-92',
													1);
insert into employee_dormitory (id_employee_dormitory, pib , position_employee, work_time, date_birth,
								experience) values (2,'Petrivna Nadia Isakova' , 'janitor', 5,'03-02-89',
													2);

insert into conditionroom (id_conditionroom, condition_room, condition_furniture, condition_techniques) values (
1, 'good','normally','normally');
insert into conditionroom (id_conditionroom, condition_room, condition_furniture, condition_techniques) values (
2, 'normally','normally','badly');
insert into conditionroom (id_conditionroom, condition_room, condition_furniture, condition_techniques) values (
3, 'normally','normally','normally');


insert into room (id_room, view_room, size_room, count_room, conditionroom_id, employee_dormitory_id) 
values (1,'normally',12.0,5,1,2);
insert into room (id_room, view_room, size_room, count_room, conditionroom_id, employee_dormitory_id) 
values (2,'normally',16.0,1,2,1);
insert into room (id_room, view_room, size_room, count_room, conditionroom_id, employee_dormitory_id) 
values (3,'normally',15.0,1,3,2);

insert into equipment_rooms (id_equipment_rooms, name_room, category, count_equipment, room_id)
values (1, 'livingroom','live',5,1);
insert into equipment_rooms (id_equipment_rooms, name_room, category, count_equipment, room_id)
values (2, 'kitchen','eat',1,2);
insert into equipment_rooms (id_equipment_rooms, name_room, category, count_equipment, room_id)
values (3, 'bathroom','wash',1,1);

insert into student (id_student, pib, group_student, residence, phone_number, room_id)
values (1,'Smolkin Stephan Igorovich', 215,'Pastera 29','+38054562',1);
insert into student (id_student, pib, group_student,residence, phone_number, room_id)
values (2,'Romanov Roma Romanovich', 214,'Pyshkina 2','+38078965',1);
insert into student (id_student, pib, group_student,residence, phone_number, room_id)
values (3,'Melnik Igor Igorovich', 216,'Shevchenko 23','+38098756',1);



delete from employee_dormitory 
	where Work_time = 3

delete from conditionroom
	where condition_room = 'good'

delete from room
	where count_room = 4
	
delete from student
	where group_student = 5

delete from equipment_rooms
	where count_equipment = 2

update employee_dormitory
	set work_time = 5
where Work_time = 4

update conditionroom
	set condition_furniture = 'good'
where ID_CONDITIONROOM = 1

update room
	set size_room = 1.5
where ID_ROOM = 1

update student
	set phone_number = '+380465756'
where ID_STUDENT = 1

update equipment_rooms
	set name_room = 'kitchen'
where ID_EQUIPMENT_ROOMS = 1

-- lab 4 (select)

select * from employee_dormitory where experience > 1;

select * from room where size_room < 16;

select avg(size_room) as avg_size_room from room;

select max(count_room) as max_count_room from room;

select * from student where group_student between 215 and 217;

select * from student where residence in ('Pastera 29');

select * from room order by count_room;

select * from student order by group_student;

select count_room,sum(size_room) from room group by count_room;

select count_room,sum(size_room) from room group by count_room 
having sum(size_room) > 14;

create view id_room as
	select view_room, size_room, count_room from room;
	
select p.pib , c.condition_room from employee_dormitory p , conditionroom c
where p.id_employee_dormitory = c.id_conditionroom;

-- lab 5 (double select, condition operators, section WITH)

select employee_dormitory_id, count_room from room
	where size_room = 12
		and exists
		 (select work_time from employee_dormitory where experience > 1);


select condition_room, condition_furniture, condition_techniques from conditionroom
	where id_conditionroom = all
		(select employee_dormitory_id from room
			where employee_dormitory_id = 2);

	
	
select name_room, category from equipment_rooms
	where room_id = 2
		and count_equipment =
			(select count_room from room
						 	where size_room = 16);
	
select view_room, size_room, count_room from room
	where view_room = 
		(select condition_room from conditionroom
			where condition_techniques = 'normally' and condition_room = 'normally');


select pib, group_student from student
	where room_id in
		(select conditionroom_id from room where conditionroom_id = 1);


select pib, position_employee, work_time, date_birth from employee_dormitory
	where id_employee_dormitory in
		(select room_id from student
		 	where room_id in
				(select count_equipment from equipment_rooms 
				 	where count_equipment in
				 		(select count_room from room where count_room = 1)));
		
		 
with students as (
	select pib, group_student, residence, phone_number from student
		where room_id in
			(select id_equipment_rooms from equipment_rooms 
				where room_id in
			 		(select id_room from room
						where size_room < 14))
)
select * from students where group_student > 214;

delete from equipment_rooms
	where room_id in
		(select conditionroom_id from room
			where size_room = 16);
	
-- lab 6 (trigger function, function)

create function student_class()
	returns trigger
as $$ begin 
	insert into class(student) values (new.id_student);
	return new;
end;$$
language'plpgsql';

create trigger student_class
	after insert on student
	for each row
	execute procedure student_class();
	
	
create function employee_del()
 	returns trigger
as $$ begin
	update room set employee = null where employee = old.id_employee_dormitory;
	return old;
end;$$
language'plpgsql';

create trigger employee_del
	before delete on employee_dormitory 
	for each row
	execute procedure employee_del();
	

create function student_group()
	returns trigger
as $$ begin
	update student set group_student = 213 where phone_number like '%5';
	return student;
end;$$
language'plpgsql';
	
create trigger student_update
	after update on student
	for each row
	execute procedure student_group();
	

	
create or replace function student_create (
	PIB varchar(40),
	group_student int,
	residence varchar(20),
	phone_number char(10)
)
	returns integer
	as $$
	declare
	id_student student.id_student%type;
	id_room room.id_room%type;
	begin
		id_student := 5;
		id_room := 1;
		insert into student values (id_student, pib, group_student,residence, phone_number, id_room);
		raise notice 'Student added';
		return id_student;
	end;$$
	language'plpgsql';

select student_create ('Gyrzui Kirill Kirillovich', 213, 'Konna 11', '+38053345');

select * from student;

delete from employee_dormitory 
	where Work_time = 23.4
	
-- lab 7 (users)

SELECT rolname FROM pg_roles;

create user user1;
create user user2;
create user user3;

grant update (pib, group_student, residence) on student to user1;

grant select on all tables in schema public to public;

grant insert, update on employee_dormitory to user2 with grant option;

grant all privileges on all tables in schema public to user3;

revoke insert on conditionroom from user3;

create view roles
as select pib, group_student
from student;

grant all on roles to user1;

grant select on all tables in schema public to user1;

grant update (view_room, size_room, count_room) on room to user2;

grant update , delete , references on equipment_rooms to user3;

set role user1;

