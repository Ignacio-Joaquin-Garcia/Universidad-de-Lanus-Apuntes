-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema GarciaIgnacioJoaquin_46940086
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema GarciaIgnacioJoaquin_46940086
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `GarciaIgnacioJoaquin_46940086` DEFAULT CHARACTER SET utf8 ;
USE `GarciaIgnacioJoaquin_46940086` ;

-- -----------------------------------------------------
-- Table `GarciaIgnacioJoaquin_46940086`.`Albumes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GarciaIgnacioJoaquin_46940086`.`Albumes` (
  `id_album` INT NOT NULL,
  `nombre` VARCHAR(45) NOT NULL,
  `anio` DATETIME NOT NULL,
  `editorial` VARCHAR(45) NOT NULL,
  `total_figuritas` INT NOT NULL,
  `descripcion` VARCHAR(45) NULL,
  PRIMARY KEY (`id_album`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `GarciaIgnacioJoaquin_46940086`.`Personas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GarciaIgnacioJoaquin_46940086`.`Personas` (
  `id_persona` INT NOT NULL,
  `nombre` VARCHAR(45) NOT NULL,
  `apellido` VARCHAR(45) NOT NULL,
  `telefono` VARCHAR(45) NULL,
  `DNI` INT NULL,
  PRIMARY KEY (`id_persona`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `GarciaIgnacioJoaquin_46940086`.`Selecciones`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GarciaIgnacioJoaquin_46940086`.`Selecciones` (
  `id_seleccion` INT NOT NULL,
  `nombre` VARCHAR(45) NOT NULL,
  `codigo_fifa` VARCHAR(45) NOT NULL,
  `continente` VARCHAR(45) NOT NULL,
  `grupo` VARCHAR(45) NOT NULL,
  `nombre_dt` VARCHAR(45) NOT NULL,
  `escudo_url` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id_seleccion`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `GarciaIgnacioJoaquin_46940086`.`Jugadores`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GarciaIgnacioJoaquin_46940086`.`Jugadores` (
  `id_jugador` INT NOT NULL,
  `url_foto` VARCHAR(45) NOT NULL,
  `posicion` VARCHAR(45) NOT NULL,
  `club_actual` VARCHAR(45) NOT NULL,
  `es_capitan` TINYINT NOT NULL,
  `Personas_id_persona` INT NOT NULL,
  `Selecciones_id_seleccion` INT NOT NULL,
  PRIMARY KEY (`id_jugador`),
  INDEX `fk_Jugadores_Personas_idx` (`Personas_id_persona` ASC) VISIBLE,
  INDEX `fk_Jugadores_Selecciones1_idx` (`Selecciones_id_seleccion` ASC) VISIBLE,
  CONSTRAINT `fk_Jugadores_Personas`
    FOREIGN KEY (`Personas_id_persona`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Personas` (`id_persona`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Jugadores_Selecciones1`
    FOREIGN KEY (`Selecciones_id_seleccion`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Selecciones` (`id_seleccion`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `GarciaIgnacioJoaquin_46940086`.`Figuritas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GarciaIgnacioJoaquin_46940086`.`Figuritas` (
  `id_figurita` INT NOT NULL,
  `numero` INT NOT NULL,
  `tipo` VARCHAR(45) NOT NULL,
  `rareza` INT NOT NULL,
  `seccion` VARCHAR(45) NOT NULL,
  `descripcion` VARCHAR(45) NULL,
  `Jugadores_id_jugador` INT NOT NULL,
  `Albumes_id_album` INT NOT NULL,
  PRIMARY KEY (`id_figurita`),
  INDEX `fk_Figuritas_Jugadores1_idx` (`Jugadores_id_jugador` ASC) VISIBLE,
  INDEX `fk_Figuritas_Albumes1_idx` (`Albumes_id_album` ASC) VISIBLE,
  CONSTRAINT `fk_Figuritas_Jugadores1`
    FOREIGN KEY (`Jugadores_id_jugador`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Jugadores` (`id_jugador`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Figuritas_Albumes1`
    FOREIGN KEY (`Albumes_id_album`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Albumes` (`id_album`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `GarciaIgnacioJoaquin_46940086`.`Paquetes_de_figuritas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GarciaIgnacioJoaquin_46940086`.`Paquetes_de_figuritas` (
  `id_paquete_de_figurita` INT NOT NULL,
  `cantidad_figuritas` INT NOT NULL,
  `precio` INT NOT NULL,
  `descripcion` VARCHAR(45) NULL,
  `tipo` VARCHAR(45) NOT NULL,
  `Albumes_id_album` INT NOT NULL,
  PRIMARY KEY (`id_paquete_de_figurita`),
  INDEX `fk_Paquetes_de_figuritas_Albumes1_idx` (`Albumes_id_album` ASC) VISIBLE,
  CONSTRAINT `fk_Paquetes_de_figuritas_Albumes1`
    FOREIGN KEY (`Albumes_id_album`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Albumes` (`id_album`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `GarciaIgnacioJoaquin_46940086`.`Usuarios`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GarciaIgnacioJoaquin_46940086`.`Usuarios` (
  `Personas_id_persona` INT NOT NULL,
  `fecha_registro` DATETIME NOT NULL,
  PRIMARY KEY (`Personas_id_persona`),
  INDEX `fk_Coleccionistas_Personas1_idx` (`Personas_id_persona` ASC) VISIBLE,
  CONSTRAINT `fk_Coleccionistas_Personas1`
    FOREIGN KEY (`Personas_id_persona`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Personas` (`id_persona`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `GarciaIgnacioJoaquin_46940086`.`Albumes_has_Selecciones`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GarciaIgnacioJoaquin_46940086`.`Albumes_has_Selecciones` (
  `Albumes_id_album` INT NOT NULL,
  `Selecciones_id_seleccion` INT NOT NULL,
  PRIMARY KEY (`Albumes_id_album`, `Selecciones_id_seleccion`),
  INDEX `fk_Albumes_has_Selecciones_Selecciones1_idx` (`Selecciones_id_seleccion` ASC) VISIBLE,
  INDEX `fk_Albumes_has_Selecciones_Albumes1_idx` (`Albumes_id_album` ASC) VISIBLE,
  CONSTRAINT `fk_Albumes_has_Selecciones_Albumes1`
    FOREIGN KEY (`Albumes_id_album`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Albumes` (`id_album`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Albumes_has_Selecciones_Selecciones1`
    FOREIGN KEY (`Selecciones_id_seleccion`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Selecciones` (`id_seleccion`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `GarciaIgnacioJoaquin_46940086`.`Colecciones`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GarciaIgnacioJoaquin_46940086`.`Colecciones` (
  `id_coleccion` INT NOT NULL,
  `Albumes_id_album` INT NOT NULL,
  `Usuario_Personas_id_persona` INT NOT NULL,
  PRIMARY KEY (`id_coleccion`),
  INDEX `fk_Coleccion_Albumes1_idx` (`Albumes_id_album` ASC) VISIBLE,
  INDEX `fk_Coleccion_Usuario1_idx` (`Usuario_Personas_id_persona` ASC) VISIBLE,
  CONSTRAINT `fk_Coleccion_Albumes1`
    FOREIGN KEY (`Albumes_id_album`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Albumes` (`id_album`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Coleccion_Usuario1`
    FOREIGN KEY (`Usuario_Personas_id_persona`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Usuarios` (`Personas_id_persona`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `GarciaIgnacioJoaquin_46940086`.`Figuritas_has_Coleccion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GarciaIgnacioJoaquin_46940086`.`Figuritas_has_Coleccion` (
  `Figuritas_id_figurita` INT NOT NULL,
  `Colecciones_Usuario_Personas_id_persona` INT NOT NULL,
  PRIMARY KEY (`Figuritas_id_figurita`, `Colecciones_Usuario_Personas_id_persona`),
  INDEX `fk_Figuritas_has_Coleccion_Coleccion1_idx` (`Colecciones_Usuario_Personas_id_persona` ASC) VISIBLE,
  INDEX `fk_Figuritas_has_Coleccion_Figuritas1_idx` (`Figuritas_id_figurita` ASC) VISIBLE,
  CONSTRAINT `fk_Figuritas_has_Coleccion_Figuritas1`
    FOREIGN KEY (`Figuritas_id_figurita`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Figuritas` (`id_figurita`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Figuritas_has_Coleccion_Coleccion1`
    FOREIGN KEY (`Colecciones_Usuario_Personas_id_persona`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Colecciones` (`id_coleccion`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `GarciaIgnacioJoaquin_46940086`.`Intercambios`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GarciaIgnacioJoaquin_46940086`.`Intercambios` (
  `id_intercambio` INT NOT NULL,
  `fecha` DATETIME NOT NULL,
  `Usuario_Personas_id_persona_ofrece` INT NOT NULL,
  `Usuario_Personas_id_persona_recibe` INT NOT NULL,
  PRIMARY KEY (`id_intercambio`),
  INDEX `fk_Intercambios_Usuario1_idx` (`Usuario_Personas_id_persona_ofrece` ASC) VISIBLE,
  INDEX `fk_Intercambios_Usuario2_idx` (`Usuario_Personas_id_persona_recibe` ASC) VISIBLE,
  CONSTRAINT `fk_Intercambios_Usuario1`
    FOREIGN KEY (`Usuario_Personas_id_persona_ofrece`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Usuarios` (`Personas_id_persona`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Intercambios_Usuario2`
    FOREIGN KEY (`Usuario_Personas_id_persona_recibe`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Usuarios` (`Personas_id_persona`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `GarciaIgnacioJoaquin_46940086`.`Figuritas_has_Intercambios`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GarciaIgnacioJoaquin_46940086`.`Figuritas_has_Intercambios` (
  `Figuritas_id_figurita` INT NOT NULL,
  `Intercambios_id_intercambio` INT NOT NULL,
  PRIMARY KEY (`Figuritas_id_figurita`, `Intercambios_id_intercambio`),
  INDEX `fk_Figuritas_has_Intercambios_Intercambios1_idx` (`Intercambios_id_intercambio` ASC) VISIBLE,
  INDEX `fk_Figuritas_has_Intercambios_Figuritas1_idx` (`Figuritas_id_figurita` ASC) VISIBLE,
  CONSTRAINT `fk_Figuritas_has_Intercambios_Figuritas1`
    FOREIGN KEY (`Figuritas_id_figurita`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Figuritas` (`id_figurita`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Figuritas_has_Intercambios_Intercambios1`
    FOREIGN KEY (`Intercambios_id_intercambio`)
    REFERENCES `GarciaIgnacioJoaquin_46940086`.`Intercambios` (`id_intercambio`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
