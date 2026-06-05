use `garciaignaciojoaquin_46940086`;

-- ALBUMES
INSERT ignore INTO Albumes VALUES
(1,'Mundial 2022','2022-01-01 00:00:00','Panini',670,'Album Qatar 2022'),
(2,'Copa America 2024','2024-01-01 00:00:00','Panini',500,'Album USA 2024'),
(3,'Eurocopa 1984','1984-01-01','Panini',260,'Album oficial Eurocopa 1984'),
(4,'Mundial México 1986','1986-01-01','Panini',427,'Album oficial Copa Mundial FIFA México 1986'),
(5,'Copa América 1987','1987-01-01','Panini',220,'Album oficial Copa América 1987'),
(6,'Mundial Italia 1990','1990-01-01','Panini',448,'Album oficial Copa Mundial FIFA Italia 1990'),
(7,'Eurocopa 1992','1992-01-01','Panini',280,'Album oficial Eurocopa 1992'),
(8,'Mundial USA 1994','1994-01-01','Panini',561,'Album oficial Copa Mundial FIFA USA 1994'),
(9,'Copa América 1995','1995-01-01','Panini',250,'Album oficial Copa América 1995'),
(10,'Mundial Francia 1998','1998-01-01','Panini',561,'Album oficial Copa Mundial FIFA Francia 1998'),
(11,'Eurocopa 2000','2000-01-01','Panini',350,'Album oficial Eurocopa 2000'),
(12,'Mundial Corea-Japón 2002','2002-01-01','Panini',576,'Album oficial Copa Mundial FIFA 2002'),
(13,'Copa América 2004','2004-01-01','Panini',280,'Album oficial Copa América 2004'),
(14,'Mundial Alemania 2006','2006-01-01','Panini',596,'Album oficial Copa Mundial FIFA Alemania 2006'),
(15,'Eurocopa 2008','2008-01-01','Panini',535,'Album oficial Eurocopa 2008'),
(16,'Mundial Sudáfrica 2010','2010-01-01','Panini',638,'Album oficial Copa Mundial FIFA Sudáfrica 2010'),
(17,'Copa América 2011','2011-01-01','Panini',300,'Album oficial Copa América Argentina 2011'),
(18,'Mundial Brasil 2014','2014-01-01','Panini',640,'Album oficial Copa Mundial FIFA Brasil 2014'),
(19,'Eurocopa 2016','2016-01-01','Panini',680,'Album oficial Eurocopa Francia 2016'),
(20,'Mundial Rusia 2018','2018-01-01','Panini',682,'Album oficial Copa Mundial FIFA Rusia 2018'),
(21,'Copa América 2019','2019-01-01','Panini',350,'Album oficial Copa América Brasil 2019'),
(22,'Eurocopa 2020','2020-01-01','Panini',678,'Album oficial Eurocopa 2020'),
(23,'Eurocopa 1980','1980-01-01','Panini',250,'Album oficial Eurocopa 1980'),
(24,'Mundial España 1982','1982-01-01','Panini',427,'Album oficial Copa Mundial FIFA España 1982');


-- PERSONAS
INSERT ignore INTO Personas VALUES
(1,'Lionel','Messi','111111111',30111222),
(2,'Emiliano','Martinez','222222222',32111222),
(3,'Kylian','Mbappe','333333333',40111222),
(4,'Julian','Alvarez','444444444',42111222),
(5,'Ignacio','Garcia','555555555',46940086),
(6,'Juan','Perez','666666666',40123456),
(7,'Maria','Lopez','777777777',38987654),
(8,'Neymar','Junior','888888888',35111222),
(9,'Vinicius','Junior','999999999',37111222),
(10,'Antoine','Griezmann','101010101',34111222),
(11,'Olivier','Giroud','111111112',33111222);

-- SELECCIONES
INSERT ignore INTO Selecciones VALUES
(1,'Argentina','ARG','America','C','Lionel Scaloni','arg.png'),
(2,'Francia','FRA','Europa','D','Didier Deschamps','fra.png'),
(3,'Brasil','BRA','America','G','Dorival Junior','bra.png');

-- JUGADORES
INSERT ignore INTO Jugadores VALUES
(1,'messi.jpg','Delantero','Inter Miami',1,1,1),
(2,'dibu.jpg','Arquero','Aston Villa',0,2,1),
(3,'mbappe.jpg','Delantero','Real Madrid',1,3,2),
(4,'julian.jpg','Delantero','Atletico Madrid',0,4,1),
(5,'neymar.jpg','Delantero','Santos',1,8,3),
(6,'vinicius.jpg','Delantero','Real Madrid',0,9,3),
(7,'griezmann.jpg','Mediocampista','Atletico Madrid',0,10,2),
(8,'giroud.jpg','Delantero','Los Angeles FC',0,11,2);

-- FIGURITAS
INSERT ignore INTO Figuritas VALUES
(1,10,'Jugador',5,'Argentina','Lionel Messi',1,1),
(2,11,'Jugador',4,'Argentina','Emiliano Martinez',2,1),
(3,120,'Jugador',5,'Francia','Kylian Mbappe',3,1),
(4,15,'Jugador',4,'Argentina','Julian Alvarez',4,1),
(5,16,'Jugador',4,'Brasil','Neymar Jr',5,1),
(6,17,'Jugador',3,'Brasil','Vinicius Jr',6,1),
(7,121,'Jugador',4,'Francia','Antoine Griezmann',7,1),
(8,122,'Jugador',3,'Francia','Olivier Giroud',8,1),
(9,1,'Jugador',5,'Argentina','Lionel Messi',1,2),
(10,2,'Jugador',4,'Argentina','Emiliano Martinez',2,2),
(11,3,'Jugador',4,'Argentina','Julian Alvarez',4,2),
(12,50,'Jugador',5,'Brasil','Neymar Jr',5,2),
(13,51,'Jugador',4,'Brasil','Vinicius Jr',6,2),
(14,670,'Escudo',5,'Argentina','Escudo Seleccion Argentina',1,1),
(15,671,'Leyenda',5,'Argentina','Capitan Campeon del Mundo',1,1),
(16,500,'Escudo',5,'Brasil','Escudo Seleccion Brasil',5,2);

-- PAQUETES
INSERT ignore INTO Paquetes_de_figuritas VALUES
(1,5,1500,'Paquete clasico','Basico',1),
(2,10,3000,'Paquete premium','Premium',1),
(3,5,1800,'Paquete Copa America','Basico',2);

-- USUARIOS
INSERT ignore INTO Usuarios VALUES
(5,'2025-01-10 10:00:00'),
(6,'2025-01-12 11:00:00'),
(7,'2025-01-15 12:00:00');

-- ALBUMES_HAS_SELECCIONES
INSERT ignore INTO Albumes_has_Selecciones VALUES
(1,1),
(1,2),
(1,3),
(2,1),
(2,3);

-- COLECCIONES
INSERT ignore INTO Colecciones VALUES
(1,1,5),
(2,1,6),
(3,1,7);

-- FIGURITAS_HAS_COLECCION
INSERT ignore INTO Figuritas_has_Coleccion VALUES
(1,1),
(2,1),
(3,2),
(4,3);

-- INTERCAMBIOS
INSERT ignore INTO Intercambios VALUES
(1,'2025-06-01 15:00:00',5,6),
(2,'2025-06-02 18:00:00',6,7);

-- FIGURITAS_HAS_INTERCAMBIOS
INSERT ignore INTO Figuritas_has_Intercambios VALUES
(1,1),
(3,1),
(2,2),
(4,2);