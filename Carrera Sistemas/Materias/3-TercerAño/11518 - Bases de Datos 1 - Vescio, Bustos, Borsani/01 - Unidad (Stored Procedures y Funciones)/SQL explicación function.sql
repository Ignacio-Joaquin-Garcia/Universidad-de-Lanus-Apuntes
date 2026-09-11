-- Sintaxis function
DELIMITER //
CREATE FUNCTION nombre_funcion(parametro TIPO)
RETURNS TIPO_RETORNO
[NOT] DETERMINISTIC
BEGIN
    -- Instrucciones SQL
    RETURN valor;
END //
DELIMITER ;

DELIMITER //
CREATE FUNCTION promedio_estudiante(p_id_estudiante INT)
RETURNS DECIMAL(4,2)
READS SQL DATA
BEGIN
    DECLARE v_promedio DECIMAL(4,2);
    
    SELECT AVG(nota)
    INTO v_promedio
    FROM cursada
    WHERE id_estudiante = p_id_estudiante;

    RETURN v_promedio;
END //
DELIMITER ;

SELECT id_estudiante, nombre, apellido, promedio_estudiante(id_estudiante) AS promedio
FROM estudiante;

SELECT nombre, apellido, promedio_estudiante(id_estudiante) AS promedio
FROM estudiante
WHERE promedio_estudiante(id_estudiante) >= 7;

-- Ejemplo función no determinista
DELIMITER //
CREATE FUNCTION obtener_fecha_actual()
RETURNS DATE
NOT DETERMINISTIC
BEGIN
    RETURN CURDATE();
END;
//
DELIMITER ;

-- Ejemplo función determinista
DELIMITER //
CREATE FUNCTION nombre_completo(p_nombre VARCHAR(50),p_apellido VARCHAR(50))
RETURNS VARCHAR(101)
DETERMINISTIC
BEGIN
    RETURN CONCAT(p_apellido, ', ', p_nombre);
END //
DELIMITER ;