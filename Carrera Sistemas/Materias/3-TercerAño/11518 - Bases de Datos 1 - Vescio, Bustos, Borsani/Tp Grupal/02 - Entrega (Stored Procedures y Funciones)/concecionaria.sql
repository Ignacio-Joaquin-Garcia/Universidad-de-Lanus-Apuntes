USE 01_trabajo_integrador_bd1;
DROP PROCEDURE IF EXISTS sp_alta_concesionaria;
DROP PROCEDURE IF EXISTS sp_modificar_conce;
DROP PROCEDURE IF EXISTS sp_baja_concesionaria;

DELIMITER //

CREATE PROCEDURE sp_alta_concesionaria ( in p_nombre VARCHAR(45), in p_direccion VARCHAR(45), out p_nResultado INT, out p_cMensaje VARCHAR(255)
)
BEGIN
    DECLARE v_cantidad INT DEFAULT 0;

    SELECT COUNT(*) INTO v_cantidad
    FROM concecionaria
    WHERE nombre = p_nombre;

    IF v_cantidad > 0 THEN
        SET p_nResultado = -1;
        SET p_cMensaje = 'Error! Ya hay una concesionaria con ese nombre';
    ELSE
        INSERT INTO concecionaria (nombre, direccion)
        VALUES (p_nombre, p_direccion);

        SET p_nResultado = 0;
        SET p_cMensaje = '';
    END IF;

END //
DELIMITER ;

DELIMITER //

CREATE PROCEDURE sp_modificar_conce(IN p_id INT, IN p_nombre VARCHAR(45), IN p_direccion VARCHAR(45), OUT p_nResultado INT, OUT p_cMensaje VARCHAR(255)
)
BEGIN
    
    DECLARE v_existe INT DEFAULT 0;
    DECLARE v_duplicado INT DEFAULT 0;


    SELECT COUNT(*) INTO v_existe 
    FROM concecionaria 
    WHERE id = p_id;

    IF v_existe = 0 THEN
        SET p_nResultado = -1;
        SET p_cMensaje = 'Error! La concesionaria que intenta modificar no existe';
    ELSE
   
        SELECT COUNT(*) INTO v_duplicado 
        FROM concecionaria 
        WHERE nombre = p_nombre AND id <> p_id;

        IF v_duplicado > 0 THEN
            SET p_nResultado = -2;
            SET p_cMensaje = 'Error! Ya hay otra concesionaria con ese mismo nombre.';
        ELSE
          
            UPDATE concecionaria 
            SET nombre = p_nombre, 
                direccion = p_direccion 
            WHERE id = p_id;

            SET p_nResultado = 0;
            SET p_cMensaje = '';
        END IF;
    END IF;

END //

DELIMITER ;

DELIMITER //
CREATE PROCEDURE sp_baja_concesionaria (IN p_id INT, OUT p_nResultado INT, OUT p_cMensaje VARCHAR(255)
)
BEGIN
    DECLARE v_existe INT DEFAULT 0;
    DECLARE v_tiene_ventas INT DEFAULT 0;

    SELECT COUNT(*) INTO v_existe 
    FROM concecionaria 
    WHERE id = p_id;

    IF v_existe = 0 THEN
        SET p_nResultado = -1;
        SET p_cMensaje = 'Error: La concesionaria que quiere eliminar no existe';
    ELSE
    
        SELECT COUNT(*) INTO v_tiene_ventas 
        FROM venta 
        WHERE concecionaria_id = p_id;

        IF v_tiene_ventas > 0 THEN
            SET p_nResultado = -2;
            SET p_cMensaje = 'Error: No se puede eliminar la concesionaria porque tiene venta asociadas';
        ELSE

            DELETE FROM concecionaria 
            WHERE id = p_id;

            SET p_nResultado = 0;
            SET p_cMensaje = '';
        END IF;
    END IF;

END //

DELIMITER ;