-- Creacion Base de Datos --
create database if not exists clase5_tarea;
use clase5_tarea;

-- Creacion Tablas ---
create table marcas(
	-- Atributos --
	codigo int not null,
    nombre varchar(45) not null,
    pais_origen varchar(45) null,
    -- Primary Key --
    primary key(codigo)
    -- Foreign Key --
    
);
create table aviones(
	-- Atributos --
    matricula varchar(45) not null,
    modelo varchar(45) not null,
    fecha_de_entrada_servicio date not null,
    -- Primary Key --
    primary key(matricula),
    -- Foreign Key --
    fk_marcas_codigo int not null
);
create table ciudades(
	-- Atributos --
	id_ciudad int not null auto_increment,
	nombre varchar(45) not null,
    -- Primary Key --
    primary key(id_ciudad)
    -- Foreign Key --
);
create table aeropuertos(
	-- Atributos --
	codigo_iata int not null,
    nombre varchar(45),
    -- Primary Key --
    primary key(codigo_iata),
    -- Foreign Key --
    fk_ciudades_id_ciudad int not null
);



create table domicilios(
	-- Atributos --
    id_domicilio int not null auto_increment,
    calle varchar(45) not null,
    numero int not null,
    localidad varchar(45) not null,
    provincia varchar(45) not null,
    
    -- Primary Key --
    primary key(id_domicilio)
    -- Foreign Key --
    
);
create table personas(
	-- Atributos --
    id_persona int not null auto_increment,
    apellido varchar(45) not null,
    nombres varchar(45) not null,
    dni int not null unique,
    -- Primary Key --
    primary key(id_persona),
    -- Foreign Key --
    fk_domicilio_id_domicilio int not null
);
create table pilotos(
	-- Atributos --
    cuil int not null,
    fecha_de_ingreso date not null,
    
    -- Primary Key --
    primary key(cuil),
    -- Foreign Key --
    fk_personas_id_persona int not null unique
);
create table vuelos_realizados_por_pilotos(
	id_vuelos_realizados_por_pilotos int not null auto_increment primary key,
	fk_vuelos_realizados_codigo int not null,
    fk_pilotos_cuil int not null
);
create table pasajeros(
	-- Atributos --
    participa_programa_viajeros_frecuentes bool not null,
    -- Primary Key --
    -- Foreign Key --
    fk_personas_id_persona int not null primary key unique

);
create table listado_pasajeros(
	id_listado_pasajeros int not null auto_increment primary key,
	fk_pasajeros_personas_id_persona int not null,
    fk_vuelos_realizados_codigo int not null
);



create table vuelos_realizados(
	-- Atributos --
	codigo int not null,
    fecha_partida date not null,
    hora_partida datetime not null,
    fecha_arribo date not null,
    hora_arribo datetime not null,
    distancia_recorrida varchar(45) not null,
    -- Primary Key --
    primary key(codigo),
    -- Foreign Key --
    fk_aviones_matricula varchar(45) not null,
    fk_origen_codigo_iata int not null,
    fk_destino_codigo_iata int not null
);

-- Creacion Relaciones --
-- Relacion Marcas 1:N Aviones
alter table aviones
add constraint aviones_poseen_una_marca foreign key(fk_marcas_codigo)
references marcas(codigo);

-- Relacion Aviones 1:N Vuelos_Realizados
alter table vuelos_realizados
add constraint vuelos_realizados_posee_un_avion foreign key(fk_aviones_matricula)
references aviones(matricula);

-- Relacion Ciudades 1:N Aeropuertos
alter table aeropuertos
add constraint aeropuertos_estan_en_una_ciudad foreign key(fk_ciudades_id_ciudad)
references ciudades(id_ciudad);

-- Relacion Aeropuertos 1:N Vuelos_Realizados *2(Origen | Destino)
alter table vuelos_realizados
add constraint vuelos_realizados_posee_aeropuerto_origen foreign key(fk_origen_codigo_iata)
references aeropuertos(codigo_iata);

alter table vuelos_realizados
add constraint vuelos_realizados_posee_aeropuerto_destino foreign key(fk_destino_codigo_iata)
references aeropuertos(codigo_iata);

-- Relacion Domicilios 1:N Personas
alter table personas
add constraint personas_poseen_un_domicilio foreign key(fk_domicilio_id_domicilio)
references domicilios(id_domicilio);

-- Relacion Personas 1:1 Pilotos
alter table pilotos
add constraint pilotos_es_una_persona foreign key(fk_personas_id_persona)
references personas(id_persona);

-- Relacion Pilotos 1:N Vuelos_Realizados_por_Pilotos 
alter table vuelos_realizados_por_pilotos
add constraint vuelos_realizados_por_pilotos_posee_un_piloto foreign key(fk_pilotos_cuil)
references pilotos(cuil);

-- Relacion Vuelos_Realizados_por_Pilotos N:1 Vuelos_Realizados
alter table vuelos_realizados_por_pilotos
add constraint vuelos_realizados_por_pilotos_posee_vuelos_realizados foreign key(fk_vuelos_realizados_codigo)
references vuelos_realizados(codigo);

-- Relacion Personas 1:1 Pasajeros
alter table pasajeros
add constraint pasajeros_es_una_persona foreign key(fk_personas_id_persona)
references personas(id_persona);

-- Relacion Pasajeros 1:N Listado_Pasajeros
alter table listado_pasajeros
add constraint listado_pasajeros_posee_pasajeros foreign key(fk_pasajeros_personas_id_persona)
references pasajeros(fk_personas_id_persona);

-- Relacion Listado_Pasajeros N:1 Vuelos_Realizados
alter table listado_pasajeros
add constraint listado_pasajeros_posee_vuelos_realizados foreign key(fk_vuelos_realizados_codigo)
references vuelos_realizados(codigo);


