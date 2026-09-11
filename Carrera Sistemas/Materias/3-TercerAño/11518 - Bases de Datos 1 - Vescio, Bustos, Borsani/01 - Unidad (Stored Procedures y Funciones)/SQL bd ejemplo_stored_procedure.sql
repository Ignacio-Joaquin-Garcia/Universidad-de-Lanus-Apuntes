-- SQL tablas bd ejemplo_stored_procedure

-- Crear base de datos
CREATE DATABASE ejemplo_stored_procedure;
USE ejemplo_stored_procedure;

CREATE TABLE carrera (
    id_carrera INT PRIMARY KEY AUTO_INCREMENT,
    nombre_carrera VARCHAR(100) NOT NULL
);

CREATE TABLE estudiante (
    id_estudiante INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(50),
    apellido VARCHAR(50),
    email VARCHAR(100),
    ciudad VARCHAR(50),
    fecha_ingreso DATE
);

CREATE TABLE inscripcion (
    id_inscripcion INT PRIMARY KEY AUTO_INCREMENT,
    id_estudiante INT,
    id_carrera INT,
    fecha_inscripcion DATE,
    FOREIGN KEY (id_estudiante) REFERENCES estudiante(id_estudiante),
    FOREIGN KEY (id_carrera) REFERENCES carrera(id_carrera)
);

CREATE TABLE materia (
    id_materia INT PRIMARY KEY AUTO_INCREMENT,
    nombre_materia VARCHAR(100),
    id_carrera INT,
    FOREIGN KEY (id_carrera) REFERENCES carrera(id_carrera)
);

CREATE TABLE docente (
    id_docente INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(50),
    apellido VARCHAR(50),
    ciudad VARCHAR(50)
);

CREATE TABLE materia_docente (
    id_materia INT,
    id_docente INT,
    PRIMARY KEY (id_materia, id_docente),
    FOREIGN KEY (id_materia) REFERENCES materia(id_materia),
    FOREIGN KEY (id_docente) REFERENCES docente(id_docente)
);

CREATE TABLE cursada (
    id_cursada INT PRIMARY KEY AUTO_INCREMENT,
    id_estudiante INT,
    id_materia INT,
    año YEAR,
    nota DECIMAL(4,2),
    FOREIGN KEY (id_estudiante) REFERENCES estudiante(id_estudiante),
    FOREIGN KEY (id_materia) REFERENCES materia(id_materia)
);

-- INSERTS 
INSERT INTO carrera (nombre_carrera) VALUES
('Ingeniería en Sistemas de Información'),
('Licenciatura en Sistemas'),
('Ingeniería en Computación'),
('Licenciatura en Ciencia de Datos'),
('Ingeniería Industrial'),
('Licenciatura en Administración'),
('Contador Público'),
('Ingeniería Electrónica'),
('Licenciatura en Economía'),
('Licenciatura en Matemática');

INSERT INTO estudiante 
(nombre, apellido, email, ciudad, fecha_ingreso) 
VALUES
('Sofía', 'Martínez', 'sofia.martinez@gmail.com', 'Buenos Aires', '2024-03-11'),
('Mateo', 'Rodríguez', 'mateo.rodriguez@outlook.com', 'La Plata', '2024-03-18'),
('Valentina', 'Gómez', 'valentina.gomez@gmail.com', 'Rosario', '2025-03-10'),
('Tomás', 'Fernández', 'tomas.fernandez@hotmail.com', 'Córdoba', '2025-03-17'),
('Camila', 'López', 'camila.lopez@gmail.com', 'Mar del Plata', '2023-08-14'),
('Nicolás', 'Sánchez', 'nicolas.sanchez@gmail.com', 'Buenos Aires', '2024-08-05'),
('Julieta', 'Romero', 'julieta.romero@outlook.com', 'Mendoza', '2025-03-12'),
('Franco', 'Díaz', 'franco.diaz@gmail.com', 'San Miguel de Tucumán', '2023-03-20'),
('Martina', 'Torres', 'martina.torres@gmail.com', 'Santa Fe', '2024-03-25'),
('Agustín', 'Vázquez', 'agustin.vazquez@hotmail.com', 'Buenos Aires', '2026-03-09');

INSERT INTO inscripcion 
(id_estudiante, id_carrera, fecha_inscripcion) 
VALUES
(1, 1, '2024-03-11'),
(2, 3, '2024-03-18'),
(3, 4, '2025-03-10'),
(4, 1, '2025-03-17'),
(5, 6, '2023-08-14'),
(6, 2, '2024-08-05'),
(7, 4, '2025-03-12'),
(8, 5, '2023-03-20'),
(9, 8, '2024-03-25'),
(10, 1, '2026-03-09');

INSERT INTO materia 
(nombre_materia, id_carrera) 
VALUES
('Programación I', 1),
('Bases de Datos', 1),
('Programación II', 2),
('Sistemas Operativos', 2),
('Arquitectura de Computadoras', 3),
('Aprendizaje Automático', 4),
('Estadística Aplicada', 4),
('Gestión de Operaciones', 5),
('Contabilidad Financiera', 7),
('Circuitos Electrónicos', 8);

INSERT INTO docente 
(nombre, apellido, ciudad) 
VALUES
('Mariana', 'Suárez', 'Buenos Aires'),
('Pablo', 'Molina', 'La Plata'),
('Carolina', 'Herrera', 'Rosario'),
('Federico', 'Castro', 'Córdoba'),
('Gabriela', 'Navarro', 'Buenos Aires'),
('Diego', 'Ríos', 'Mar del Plata'),
('Laura', 'Pereyra', 'Mendoza'),
('Martín', 'Acosta', 'Santa Fe'),
('Lucía', 'Benítez', 'Tucumán'),
('Andrés', 'Figueroa', 'Buenos Aires');

INSERT INTO materia_docente 
(id_materia, id_docente) 
VALUES
(1, 1),
(1, 3),
(2, 2),
(2, 3),
(3, 1),
(3, 4),
(4, 5),
(5, 6),
(6, 7),
(6, 8),
(7, 7),
(8, 9),
(9, 10),
(10, 6);

INSERT INTO cursada 
(id_estudiante, id_materia, año, nota) 
VALUES
(1, 1, 2024, 8.50),
(1, 2, 2025, 9.00),
(2, 5, 2024, 7.00),
(2, 1, 2025, 6.50),
(3, 6, 2025, 9.25),
(3, 7, 2025, 8.75),
(4, 1, 2025, 5.50),
(5, 9, 2024, 7.80),
(6, 3, 2025, 8.00),
(7, 6, 2026, 9.50);