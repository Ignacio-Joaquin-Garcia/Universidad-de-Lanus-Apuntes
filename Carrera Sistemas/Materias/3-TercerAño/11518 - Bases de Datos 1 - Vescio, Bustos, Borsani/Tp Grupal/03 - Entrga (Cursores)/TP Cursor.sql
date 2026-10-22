DELIMITER // 
CREATE PROCEDURE procesar_venta(IN p_id_venta INT, OUT o_resultado INT, OUT o_mensaje VARCHAR(200))
p_venta: BEGIN
    DECLARE c_id_detalle_venta INT;
	DECLARE c_id_modelo INT;
	DECLARE c_cantidad INT;
    
    DECLARE terminado BOOLEAN DEFAULT FALSE;
    DECLARE n_chasis INT;

    DECLARE cursor_ventas CURSOR FOR
		SELECT id, cantidad, modelo_id 
        FROM detalle_venta
        WHERE venta_id = p_id_venta;
        
	DECLARE CONTINUE HANDLER FOR NOT FOUND
		SET terminado = TRUE;

	SET o_resultado = 0;
	SET o_mensaje = "";
    
	IF (p_id_venta IS NULL) OR NOT EXISTS(SELECT * FROM venta WHERE id = p_id_venta) THEN
		SET o_resultado = -1;
        SET o_mensaje = "ID Venta no Valido";
        LEAVE p_venta;
    ELSEIF (SELECT estado FROM venta WHERE id = p_id_venta) = "Completado" THEN
		SET o_resultado = -1;
        SET o_mensaje = "La venta esta en estado Completado";
        LEAVE p_venta;
    END IF;

	OPEN cursor_ventas;
	bucle: LOOP
		FETCH cursor_ventas INTO c_id_detalle_venta, c_cantidad, c_id_modelo;
        IF terminado THEN
			LEAVE bucle;
		END IF;
        
        IF c_id_detalle_venta IS NULL THEN
			SET o_resultado = -1;
			SET o_mensaje = "No existe Detalle de Venta para la Venta";
			LEAVE bucle;
		END IF;	
		
		WHILE c_cantidad > 0 DO
            REPEAT 
				SET n_chasis = FLOOR(RAND() * (99999999 - 0 + 1)) + 0;
            UNTIL NOT EXISTS(SELECT numero_chasis FROM vehiculo WHERE numero_chasis = n_chasis)
            END REPEAT;
            
            INSERT INTO vehiculo (numero_chasis, modelo_id, detalle_venta_id) VALUES (n_chasis, c_id_modelo, c_id_detalle_venta);
            UPDATE venta SET estado = 1 WHERE id = p_id_venta;
            
            SET c_cantidad = c_cantidad - 1;
		END WHILE;
	END LOOP;
	CLOSE cursor_ventas;
END //
DELIMITER ;

INSERT INTO concecionaria (nombre, direccion) VALUES ("automotor", "pepe");
INSERT INTO venta (fecha_pedido, fecha_entrega_esperada, concecionaria_id, estado) VALUES ("2026-01-01", "2026-01-02", 1, 2);
INSERT INTO modelo (nombre) VALUES ("Nissan");
INSERT INTO detalle_venta (cantidad, venta_id, modelo_id) VALUES (1, 1, 1);
INSERT INTO detalle_venta (cantidad, venta_id, modelo_id) VALUES (2, 1, 1);

SET @resultado = NULL;
SET @mensaje = NULL;

CALL procesar_venta(1, @resultado, @mensaje);

SELECT @resultado, @mensaje;