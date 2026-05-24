-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema parcial_virtual
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema parcial_virtual
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `parcial_virtual` DEFAULT CHARACTER SET utf8 ;
USE `parcial_virtual` ;

-- -----------------------------------------------------
-- Table `parcial_virtual`.`Personas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `parcial_virtual`.`Personas` (
  `id_persona` INT NOT NULL,
  `nombre_completo` VARCHAR(45) NOT NULL,
  `apellido` VARCHAR(45) NOT NULL,
  `DNI` INT NOT NULL,
  PRIMARY KEY (`id_persona`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `parcial_virtual`.`Clientes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `parcial_virtual`.`Clientes` (
  `Personas_id_persona` INT NOT NULL,
  `email` VARCHAR(45) NULL,
  PRIMARY KEY (`Personas_id_persona`),
  CONSTRAINT `fk_Clientes_Personas`
    FOREIGN KEY (`Personas_id_persona`)
    REFERENCES `parcial_virtual`.`Personas` (`id_persona`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `parcial_virtual`.`Paises`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `parcial_virtual`.`Paises` (
  `id_pais` INT NOT NULL,
  `nombre` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id_pais`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `parcial_virtual`.`Provincias`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `parcial_virtual`.`Provincias` (
  `id_provincia` INT NOT NULL,
  `nombre` VARCHAR(45) NOT NULL,
  `Paises_id_pais` INT NOT NULL,
  PRIMARY KEY (`id_provincia`),
  INDEX `fk_Provincias_Paises1_idx` (`Paises_id_pais` ASC) VISIBLE,
  CONSTRAINT `fk_Provincias_Paises1`
    FOREIGN KEY (`Paises_id_pais`)
    REFERENCES `parcial_virtual`.`Paises` (`id_pais`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `parcial_virtual`.`Ciudades`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `parcial_virtual`.`Ciudades` (
  `id_ciudad` INT NOT NULL,
  `nombre` VARCHAR(45) NOT NULL,
  `Provincias_id_provincia` INT NOT NULL,
  PRIMARY KEY (`id_ciudad`),
  INDEX `fk_Ciudades_Provincias1_idx` (`Provincias_id_provincia` ASC) VISIBLE,
  CONSTRAINT `fk_Ciudades_Provincias1`
    FOREIGN KEY (`Provincias_id_provincia`)
    REFERENCES `parcial_virtual`.`Provincias` (`id_provincia`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `parcial_virtual`.`Direcciones`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `parcial_virtual`.`Direcciones` (
  `id_direccion` INT NOT NULL,
  `calle` VARCHAR(45) NOT NULL,
  `numero` INT NOT NULL,
  `codigo_postal` VARCHAR(45) NOT NULL,
  `Ciudades_id_ciudad` INT NOT NULL,
  PRIMARY KEY (`id_direccion`),
  INDEX `fk_Direcciones_Ciudades1_idx` (`Ciudades_id_ciudad` ASC) VISIBLE,
  CONSTRAINT `fk_Direcciones_Ciudades1`
    FOREIGN KEY (`Ciudades_id_ciudad`)
    REFERENCES `parcial_virtual`.`Ciudades` (`id_ciudad`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `parcial_virtual`.`Complejos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `parcial_virtual`.`Complejos` (
  `id_complejo` INT NOT NULL,
  `nombre` VARCHAR(45) NOT NULL,
  `Direcciones_id_direccion` INT NOT NULL,
  PRIMARY KEY (`id_complejo`),
  INDEX `fk_Complejos_Direcciones1_idx` (`Direcciones_id_direccion` ASC) VISIBLE,
  CONSTRAINT `fk_Complejos_Direcciones1`
    FOREIGN KEY (`Direcciones_id_direccion`)
    REFERENCES `parcial_virtual`.`Direcciones` (`id_direccion`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `parcial_virtual`.`Salas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `parcial_virtual`.`Salas` (
  `id_sala` INT NOT NULL,
  `numero_sala` INT NOT NULL,
  `capacidad` INT NOT NULL,
  `Complejos_id_complejos` INT NOT NULL,
  PRIMARY KEY (`id_sala`),
  INDEX `fk_Salas_Complejos1_idx` (`Complejos_id_complejos` ASC) VISIBLE,
  CONSTRAINT `fk_Salas_Complejos1`
    FOREIGN KEY (`Complejos_id_complejos`)
    REFERENCES `parcial_virtual`.`Complejos` (`id_complejo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `parcial_virtual`.`Peliculas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `parcial_virtual`.`Peliculas` (
  `id_pelicula` INT NOT NULL,
  `titulo` VARCHAR(45) NOT NULL,
  `genero` VARCHAR(45) NOT NULL,
  `duracion` INT NOT NULL,
  `clasificacion` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id_pelicula`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `parcial_virtual`.`Funciones`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `parcial_virtual`.`Funciones` (
  `id_funcion` INT NOT NULL,
  `fecha` DATE NOT NULL,
  `horario` DATETIME NOT NULL,
  `Peliculas_id_pelicula` INT NOT NULL,
  `Salas_id_sala` INT NOT NULL,
  PRIMARY KEY (`id_funcion`),
  INDEX `fk_Funciones_Peliculas1_idx` (`Peliculas_id_pelicula` ASC) VISIBLE,
  INDEX `fk_Funciones_Salas1_idx` (`Salas_id_sala` ASC) VISIBLE,
  CONSTRAINT `fk_Funciones_Peliculas1`
    FOREIGN KEY (`Peliculas_id_pelicula`)
    REFERENCES `parcial_virtual`.`Peliculas` (`id_pelicula`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Funciones_Salas1`
    FOREIGN KEY (`Salas_id_sala`)
    REFERENCES `parcial_virtual`.`Salas` (`id_sala`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `parcial_virtual`.`Entradas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `parcial_virtual`.`Entradas` (
  `id_entrada` INT NOT NULL,
  `fecha_compra` DATETIME NOT NULL,
  `asiento` VARCHAR(45) NOT NULL,
  `precio` INT NOT NULL,
  `Funciones_id_funcion` INT NOT NULL,
  PRIMARY KEY (`id_entrada`),
  INDEX `fk_Entradas_Funciones1_idx` (`Funciones_id_funcion` ASC) VISIBLE,
  CONSTRAINT `fk_Entradas_Funciones1`
    FOREIGN KEY (`Funciones_id_funcion`)
    REFERENCES `parcial_virtual`.`Funciones` (`id_funcion`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `parcial_virtual`.`Entradas_por_Clientes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `parcial_virtual`.`Entradas_por_Clientes` (
  `Entradas_id_entrada` INT NOT NULL,
  `Clientes_Personas_id_persona` INT NOT NULL,
  PRIMARY KEY (`Entradas_id_entrada`, `Clientes_Personas_id_persona`),
  INDEX `fk_Entradas_has_Clientes_Clientes1_idx` (`Clientes_Personas_id_persona` ASC) VISIBLE,
  INDEX `fk_Entradas_has_Clientes_Entradas1_idx` (`Entradas_id_entrada` ASC) VISIBLE,
  CONSTRAINT `fk_Entradas_has_Clientes_Entradas1`
    FOREIGN KEY (`Entradas_id_entrada`)
    REFERENCES `parcial_virtual`.`Entradas` (`id_entrada`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Entradas_has_Clientes_Clientes1`
    FOREIGN KEY (`Clientes_Personas_id_persona`)
    REFERENCES `parcial_virtual`.`Clientes` (`Personas_id_persona`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
