USE ejemplo_stored_procedure;

-- Sintaxis stored procedures
DELIMITER //
CREATE PROCEDURE sp_nombre_procedimiento (IN parametroEntrada INT, OUT parametroSalida INT)
BEGIN
	-- Cuerpo del procedimiento
    
END;
//
DELIMITER ;

-- Información sobre los procedimientos almacenados disponibles
SHOW PROCEDURE STATUS;

-- Ver procedimientos de determinada bd
SHOW PROCEDURE STATUS 
WHERE db = 'ejemplo_stored_procedure';

-- Ver determinado procedimiento
SHOW CREATE PROCEDURE listar_estudiantes;

-- Ejemplo procedimiento sin parámetros
DELIMITER //
CREATE PROCEDURE listar_estudiantes()
BEGIN
    SELECT *
    FROM estudiante;
END //
DELIMITER ;

CALL listar_estudiantes();

DROP procedure listar_estudiantes;
DROP procedure listar_estudiantes_carrera;
DROP procedure obtener_materias_aprobadas;

-- Ejemplo procedimiento con parámetro de entrada
DELIMITER //
CREATE PROCEDURE listar_estudiantes_carrera(IN p_id_carrera INT)
BEGIN
    SELECT e.id_estudiante, e.nombre, e.apellido, e.email, c.nombre_carrera, i.fecha_inscripcion
    FROM estudiante e
    INNER JOIN inscripcion i ON e.id_estudiante = i.id_estudiante
    INNER JOIN carrera c ON i.id_carrera = c.id_carrera
    WHERE c.id_carrera = p_id_carrera
    ORDER BY e.apellido, e.nombre;
END //
DELIMITER ;

CALL listar_estudiantes_carrera(1);

-- Ejemplo procedimiento con parámetro de salida
DELIMITER //
CREATE PROCEDURE obtener_cantidad_estudiantes(OUT p_cantidad INT)
BEGIN
    SELECT COUNT(*)
    INTO p_cantidad
    FROM estudiante;
END //
DELIMITER ;
DROP procedure obtener_cantidad_estudiantes;

SET @cantidad = 0;
CALL obtener_cantidad_estudiantes(@cantidad);
SELECT @cantidad;

-- Ejemplo procedimiento con parámetros de entrada y salida
DELIMITER //
CREATE PROCEDURE obtener_materias_aprobadas(IN p_id_estudiante INT,OUT p_cantidad_aprobadas INT)
BEGIN
    SELECT COUNT(*)
    INTO p_cantidad_aprobadas
    FROM cursada
    WHERE id_estudiante = p_id_estudiante AND nota >= 4;
END //
DELIMITER ;

SET @cantidad = 0;
CALL obtener_materias_aprobadas(1, @cantidad);
SELECT @cantidad;

-- Ejemplo procedimiento con parámetro de entrada y salida (INOUT)
DELIMITER //
CREATE PROCEDURE validar_nota_final(INOUT p_nota DECIMAL(4,2))
BEGIN
    IF p_nota < 0 THEN
        SET p_nota = 0;
    ELSEIF p_nota > 10 THEN
        SET p_nota = 10;
    END IF;
END //
DELIMITER ;

SET @nota = 17;
CALL validar_nota_final(@nota);
SELECT @nota;


DELIMITER //
CREATE PROCEDURE registrar_cursada(IN p_id_estudiante INT,IN p_id_materia INT,IN p_anio YEAR,IN p_nota DECIMAL(4,2))
BEGIN
    -- Variable que será modificada por el procedimiento validar_nota_final
    DECLARE v_nota DECIMAL(4,2);
    -- Asignamos el valor de la nota recibida
    SET v_nota = p_nota;
    -- Llamamos al procedimiento que valida la nota
    CALL validar_nota_final(v_nota);
    -- Registramos la cursada con la nota validada
    INSERT INTO cursada (id_estudiante,id_materia,año,nota)
    VALUES (p_id_estudiante,p_id_materia,p_anio,v_nota);
END //
DELIMITER ;

CALL registrar_cursada(1,2, 2026,8.50);
CALL registrar_cursada(1,2, 2026,12);