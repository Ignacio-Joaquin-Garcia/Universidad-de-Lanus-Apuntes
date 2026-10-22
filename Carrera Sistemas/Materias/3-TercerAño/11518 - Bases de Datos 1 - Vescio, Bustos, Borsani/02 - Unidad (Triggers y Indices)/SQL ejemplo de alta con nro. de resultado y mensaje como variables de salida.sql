DELIMITER $$
CREATE PROCEDURE alta_estudiante(IN nombre VARCHAR(50), IN apellido VARCHAR(50), IN p_email VARCHAR(100), IN ciudad VARCHAR(50), IN fecha_ingreso DATE,
    OUT nResultado INT, OUT cMensaje VARCHAR(255)
)
BEGIN
    SET nResultado = 0;
    SET cMensaje = '';

    IF nombre IS NULL OR TRIM(nombre) = '' THEN
        SET nResultado = -1;
        SET cMensaje = 'El nombre del estudiante es obligatorio.';
    ELSEIF apellido IS NULL OR TRIM(apellido) = '' THEN
        SET nResultado = -2;
        SET cMensaje = 'El apellido del estudiante es obligatorio.';
    ELSEIF p_email IS NULL OR TRIM(p_email) = '' THEN
        SET nResultado = -3;
        SET cMensaje = 'El email del estudiante es obligatorio.';
    ELSEIF EXISTS (
        SELECT 1
        FROM estudiante
        WHERE email = p_email
    ) THEN
        SET nResultado = -4;
        SET cMensaje = 'Ya existe un estudiante registrado con ese email.';
    ELSE
        INSERT INTO estudiante(nombre, apellido, email, ciudad, fecha_ingreso)
        VALUES(nombre, apellido, p_email, ciudad, fecha_ingreso);
    END IF;
END$$
DELIMITER ;

SET @resultado = NULL;
SET @mensaje = "";
CALL alta_estudiante('NombreEstudiante','ApellidoEstudiante','estudiante_test2@gmail.com','Bs.As.','2026-03-10', @resultado, @mensaje);

SELECT @resultado AS resultado, @mensaje AS mensaje;

DROP procedure alta_estudiante;

-- EJEMPLO DE COMO GENERAR UN ERROR:
--   SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Stock insuficiente';