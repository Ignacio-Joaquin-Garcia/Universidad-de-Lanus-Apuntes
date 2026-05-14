create schema if not exists actividad6_farmacia;
use actividad6_farmacia;

-- Anterior creado para esta actividad
create table if not exists obra_social(
	codigo int primary key,
	nombre varchar(45) not null,
	descripcion varchar(100) not null
);
insert ignore into obra_social 
	values(1,"PAMI","Programa de Atención Médica Integral");
insert ignore into obra_social (codigo, nombre, descripcion) 
	values(2,"IOMA","Instituto de Obra Medico Asistencial");
insert ignore into obra_social (codigo, nombre, descripcion) 
	values(3,"OSECAC","Obra Social de Empleados de Comercio");

-- Tarea en Orden
create table calle(
	id_calle int primary key,
    nombre varchar(45) not null
);
create table localidad(
	id_localidad int primary key,
    nombre varchar(45)
);
create table provincia(
	id_provincia int primary key,
    nombre varchar(45)
);

drop table calle;
drop table localidad;
drop table provincia;

create table calles(
	id_calle int primary key,
    nombre varchar(45) not null
);
create table localidad(
	id_localidad int primary key,
    nombre varchar(45)
);
create table provincia(
	id_provincia int primary key,
    nombre varchar(45)
);

alter table calles rename to calle2;
alter table calle2 rename to calles;

alter table calles change column nombre nombre2 varchar(100) not null;
alter table calles change column nombre2 nombre varchar(45) not null;

insert ignore into provincia
	values(1,'Buenos Aires'), (2, 'CABA');
insert ignore into localidad
	values(1, 'Lanús'),(2, 'Pompeya'), (3, 'Avellaneda');
insert ignore into calles
	values(1, '9 de Julio'), (2, 'Hipólito Yrigoyen'), (3, 'Mitre'), (4, 'Sáenz');

select * from provincia;
select * from localidad;
select * from calles;

