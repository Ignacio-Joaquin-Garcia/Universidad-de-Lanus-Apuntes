DELIMITER //

CREATE PROCEDURE registrar_proveedor(IN p_nombre varchar(45), IN p_direccion varchar(45), IN p_telefono varchar(30))
BEGIN
	DECLARE cMensaje varchar(100) DEFAULT  '';
    DECLARE nResultado int DEFAULT  -1;
    DECLARE rRepetido int;
    
    IF (p_nombre IS NOT NULL) AND (p_direccion IS NOT NULL) AND (p_telefono IS NOT NULL) THEN
		SELECT id into rRepetido FROM proveedor
		WHERE (nombre = p_nombre) OR (direccion = p_direccion) OR (telefono = p_telefono) 
		LIMIT 1;
        
		IF rRepetido IS NULL THEN
			INSERT INTO proveedor (nombre, direccion, telefono) 
            values (p_nombre, p_direccion, p_telefono);
            SET nResultado = 0;
		ELSE
			SET cMensaje = CONCAT('ERROR: Algunos o todos los datos ingresados ya pertenecen al registro con ID[', rRepetido, ']');
		END IF;
	ELSE 
		SET cMensaje = 'ERROR: No se pueden ingresar parametros nulos';
    END IF;
    
    SELECT cMensaje, nResultado;
END//

DELIMITER ;

-- DROP PROCEDURE registrar_proveedor;
-- CALL registrar_proveedor('Glass Factory', 'Calle Falsa 123', '+54 9 11 1234-1234');
-- select * from proveedor;

DELIMITER //

CREATE PROCEDURE modificar_proveedor(IN p_id int, IN nuevo_nombre varchar(45), IN nueva_direccion varchar(45), IN nuevo_telefono varchar(30))
BEGIN
	DECLARE cMensaje varchar(100) DEFAULT  '';
    DECLARE nResultado int DEFAULT  -1;
    DECLARE rRepetido int;
    
	IF (p_id IS NULL) OR NOT EXISTS(SELECT * FROM proveedor WHERE id = p_id) THEN
		SET cMensaje = 'ERROR: no se ingreso un id valido';
	ELSE 
		SELECT id into rRepetido FROM proveedor
		WHERE (nombre = nuevo_nombre) OR (direccion = nueva_direccion) OR (telefono = nuevo_telefono) 
		LIMIT 1;
        
        IF rRepetido IS NOT NULL THEN
			SET cMensaje = CONCAT('ERROR: Algunos o todos los nuevos datos ingresados ya pertenecen al registro con ID[', rRepetido, ']');
		ELSE
				UPDATE proveedor SET 
                nombre = COALESCE(nuevo_nombre, nombre),-- si el parametro es NULL usa el valor que tenia antes 
                direccion = COALESCE(nueva_direccion, direccion),
				telefono = COALESCE(nuevo_telefono, telefono) 
                WHERE id = p_id;
                SET nResultado = 0;
        END IF;
	END IF;
    
    SELECT cMensaje, nResultado;
END//

DELIMITER ;

-- DROP PROCEDURE modificar_proveedor;
-- CALL modificar_proveedor(1, NULL, NULL, NULL);
-- select * from proveedor;

DELIMITER //

CREATE PROCEDURE eliminar_proveedor(IN p_id int)
BEGIN
	DECLARE cMensaje varchar(100) DEFAULT  '';
    DECLARE nResultado int DEFAULT  -1;
    
	IF (p_id IS NULL) OR NOT EXISTS(SELECT * FROM proveedor WHERE id = p_id) THEN
		SET cMensaje = 'ERROR: no se ingreso un id valido';
	ELSEIF EXISTS (SELECT * FROM precio_proveedor WHERE proveedor_id = p_id) THEN
		SET cMensaje = 'ERROR: no se puede eliminar un proveedor asociado a un insumo';
    ELSEIF EXISTS (SELECT * FROM pedido WHERE proveedor_id = p_id) THEN
		SET cMensaje = 'ERROR: no se puede eliminar un proveedor asociado a un pedido';
	ELSE
		DELETE FROM proveedor WHERE id = p_id;
        SET nResultado = 0;
	END IF;
    
    SELECT cMensaje, nResultado;
END//

DELIMITER ;

-- DROP PROCEDURE eliminar_proveedor;
-- CALL eliminar_proveedor(1);
-- - SELECT * FROM proveedor;
