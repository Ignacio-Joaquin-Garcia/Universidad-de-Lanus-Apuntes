DELIMITER //
CREATE PROCEDURE registrar_pedido (in p_fecha_pedido datetime, in p_fecha_entrega_estimada datetime, in p_proveedor_id int, out cMensaje varchar(100), out nResultado int)
BEGIN
    SET nResultado = -1;
    SET cMensaje = "";

    IF (p_fecha_pedido IS NULL) OR (p_fecha_entrega_estimada IS NULL) OR (p_proveedor_id IS NULL) THEN
        SET cMensaje = "ERROR: Falta parametros para completar";
    ELSEIF NOT EXISTS (SELECT * FROM proveedor WHERE id = p_proveedor_id) THEN
        SET cMensaje = "ERROR: No existe un proveedor con esa ID";
    ELSEIF p_fecha_entrega_estimada < p_fecha_pedido THEN
        SET cMensaje= "ERROR: Fecha de entrega estimada incorrecta";
    ELSE 
        INSERT INTO pedido (fecha_pedido, fecha_entrega_estimada, proveedor_id)
        VALUES (p_fecha_pedido, p_fecha_entrega_estimada, p_proveedor_id);
        SET nResultado=0;
    END IF;

END //
DELIMITER ;

SET @nResultado = 0;
SET @cMensaje = "";
CALL registrar_pedido ("2026-09-10", "2026-09-15", 1, @cMensaje, @nResultado);
SELECT @cMensaje, @nResultado;
DROP PROCEDURE IF EXISTS registrar_pedido;

DELIMITER //
CREATE PROCEDURE modificar_pedido (in p_id int, in p_fecha_pedido datetime, in p_fecha_entrega_estimada datetime, in p_proveedor_id int, out cMensaje varchar(100), out nResultado int)
BEGIN
	SET nResultado = -1;
    SET cMensaje = "";
    
    IF (p_id IS NULL) OR NOT EXISTS (SELECT * FROM pedido WHERE id = p_id) THEN
		SET cMensaje= "ERROR: No existe el ID de ese pedido";
	ELSEIF p_fecha_entrega_estimada < p_fecha_pedido THEN
        SET cMensaje= "ERROR: Fecha de entrega estimada incorrecta";
	ELSEIF NOT EXISTS (SELECT * FROM proveedor WHERE id = p_proveedor_id) THEN
        SET cMensaje = "ERROR: No existe un proveedor con esa ID";
	ELSE 
		UPDATE pedido SET
        fecha_pedido = p_fecha_pedido,
        fecha_entrega_estimada = p_fecha_entrega_estimada,
        proveedor_id = p_proveedor_id WHERE id=p_id;
        SET nResultado=0;
	END IF;
    
END //
DELIMITER ;

CALL modificar_pedido (2, "2026-09-12","2026-10-05", 1, @cMensaje, @nResultado);
SELECT @cMensaje, @nResultado;
DROP PROCEDURE IF EXISTS modificar_pedido;

DELIMITER //
CREATE PROCEDURE eliminar_pedido (IN p_id INT, OUT cMensaje VARCHAR(100), OUT nResultado INT)
BEGIN
	SET nResultado = -1;
    SET cMensaje = "";
    
    IF (p_id IS NULL) OR NOT EXISTS (SELECT * FROM pedido WHERE id = p_id) THEN
		SET cMensaje= "ERROR: No existe el ID de ese pedido";
    ELSEIF EXISTS (SELECT * FROM detalle_pedido WHERE pedido_id = p_id) THEN 
		SET cMensaje= "ERROR: No se puede eleminar un pedido, cuando ya tiene cosas cargadas";
	ELSE 
		DELETE FROM pedido WHERE id = p_id;
		SET nResultado = 0;
    END IF;
END //
DELIMITER ;

CALL eliminar_pedido (4, @cMensaje, @nResultado);
SELECT @cMensaje, @nResultado;
DROP PROCEDURE IF EXISTS eliminar_pedido;