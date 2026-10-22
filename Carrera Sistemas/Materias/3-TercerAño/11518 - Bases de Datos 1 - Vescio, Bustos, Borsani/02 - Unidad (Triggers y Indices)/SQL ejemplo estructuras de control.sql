DELIMITER //
CREATE PROCEDURE clasificar_estudiante(IN p_materias_aprobadas INT)
BEGIN
    DECLARE v_categoria VARCHAR(30);

    IF p_materias_aprobadas >= 30 THEN
        SET v_categoria = 'Avanzado';
    ELSEIF p_materias_aprobadas >= 20 THEN
        SET v_categoria = 'Intermedio';
    ELSEIF p_materias_aprobadas >= 10 THEN
        SET v_categoria = 'Inicial';
    ELSE
        SET v_categoria = 'Ingresante';
    END IF;
    
    SELECT v_categoria AS categoria;
END //
DELIMITER ;

CALL clasificar_estudiante(21);
DROP procedure clasificar_estudiante;

DELIMITER //
CREATE PROCEDURE ejemplo_bucle_while()
BEGIN
    DECLARE v_contador INT DEFAULT 1;

    WHILE v_contador <= 5 DO
    
        SELECT v_contador AS numero;
        SET v_contador = v_contador + 1;
        
    END WHILE;
    
END //
DELIMITER ;

CALL ejemplo_bucle_while();
DROP procedure ejemplo_bucle_while;

DELIMITER //
CREATE PROCEDURE ejemplo_bucle_repeat()
BEGIN
    DECLARE v_contador INT DEFAULT 1;
    
    REPEAT
    
        SELECT v_contador AS numero;
        SET v_contador = v_contador + 1;
        
    UNTIL v_contador > 5
    END REPEAT;
    
END //
DELIMITER ;

CALL ejemplo_bucle_repeat();
DROP procedure ejemplo_bucle_repeat;

DELIMITER //
CREATE PROCEDURE ejemplo_bucle_loop_leave()
BEGIN
    DECLARE v_contador INT DEFAULT 1;

    ciclo: LOOP
    
        SELECT v_contador AS numero;
        SET v_contador = v_contador + 1;
        
        IF v_contador > 5 THEN
            LEAVE ciclo;
        END IF;

    END LOOP ciclo;
END //
DELIMITER ;

CALL ejemplo_bucle_loop_leave();
DROP procedure ejemplo_bucle_loop_leave;


