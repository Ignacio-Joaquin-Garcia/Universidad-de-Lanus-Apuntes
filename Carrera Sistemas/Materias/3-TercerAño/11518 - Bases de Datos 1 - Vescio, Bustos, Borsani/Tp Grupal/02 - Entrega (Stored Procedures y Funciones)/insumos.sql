### ABM Insumos
## ALTAS
DELIMITER //
CREATE PROCEDURE alta_insumo(IN p_nombre VARCHAR(45), IN p_descripcion TINYTEXT, IN p_cantidad_disponible FLOAT, OUT o_resultado INT, OUT o_mensaje VARCHAR(200))
proc_alta: BEGIN
	### -> VARIABLES
    DECLARE v_repetido INT;
    
	
	### -> Si ocurre un error inesperado de MySQL
	DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
		SET o_resultado = -99;
		SET o_mensaje = 'Ocurrió un error inesperado al procesar la operación';
	END;
    
    
    ### -> Reiniciar Variables de Salida
	SET o_resultado = 0;
    SET o_mensaje = '';
    
    
    ### -> Verificaciones
    ## Verificar que el Nombre, Descripcion ni Cant Disponible no sean Nulos (NO NULOS NI VACIOS)
    IF (p_nombre IS NULL) OR (p_descripcion IS NULL) OR (p_cantidad_disponible IS NULL) THEN
		SET o_resultado = -1;
        SET o_mensaje = 'Ocurrió un error, Alguno de los Parametros es Nulo';
        
        LEAVE proc_alta;
	END IF;
    IF (TRIM(p_nombre) = '') OR (TRIM(p_descripcion) = '') THEN
		SET o_resultado = -1;
        SET o_mensaje = 'Ocurrió un error, Alguno de los Parametros es Vacio';
        
        LEAVE proc_alta;
	END IF;
    
    ## Verificar que Cant Disponible no sea negativo (NO NEGATIVOS)
    IF (p_cantidad_disponible < 0) THEN
		SET o_resultado = -2;
        SET o_mensaje = 'Ocurrió un error, La cantidad disponible NO puede ser Negativa';
        
        LEAVE proc_alta;
	END IF;
    
    ## Verificar que Nombre y Descripcion no superen la cantidad maxima de caracteres (NO OVERFLOW)
    IF (CHAR_LENGTH(p_nombre) > 45) OR (CHAR_LENGTH(p_descripcion) > 255) THEN
		SET o_resultado = -3;
        SET o_mensaje = 'Ocurrió un error, Overflow en los parametros pasados';
        
        LEAVE proc_alta;
    END IF;
    
	## Verificar si el Insumo ya existe (Nombre Repetido) (NO REPETIDOS)
    SELECT COUNT(*) INTO v_repetido
    FROM insumo
    WHERE nombre = p_nombre;
	
    IF v_repetido > 0 THEN
		SET o_resultado = -4;
        SET o_mensaje = 'Ocurrió un error, El Insumo a Insertar ya se encuentra en los Insumos';
        
        LEAVE proc_alta;
    END IF;
    
    
	### -> Insercion
    INSERT INTO insumo (nombre, descripcion, cantidad_disponible)
    VALUES(p_nombre, p_descripcion, p_cantidad_disponible);
    
END proc_alta//
DELIMITER ;

SET @o_resultado = 0; # En SET se Infieren el Tipo (Operador Morsa :=)
SET @o_mensaje = ''; 
CALL alta_insumo("Carbon", "Carboncito", 2, @o_resultado, @o_mensaje);
SELECT @o_resultado, @o_mensaje;
DROP PROCEDURE IF EXISTS alta_insumo;

## BAJAS
DELIMITER //
CREATE PROCEDURE baja_insumo(IN p_id INT, OUT o_resultado INT, OUT o_mensaje VARCHAR(200))
proc_baja: BEGIN
	### -> VARIABLES


	### -> Si ocurre un error inesperado de MySQL
	DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
		SET o_resultado = -99;
		SET o_mensaje = 'Ocurrió un error inesperado al procesar la operación';
	END;
    
    
    ### -> Reiniciar Variables de Salida
	SET o_resultado = 0;
    SET o_mensaje = '';

	
    ### -> VALIDACIONES
    ## ID Invalido
	IF p_id < 0 THEN
		SET o_resultado = -1;
		SET o_mensaje = 'Ocurrió un error, El ID ingresado no es valido';
        
        LEAVE proc_baja;
	END IF;
    ## ID Matchea con un Insumo
    IF ((SELECT COUNT(*) FROM insumo WHERE id = p_id) != 1) THEN
		SET o_resultado = -1;
		SET o_mensaje = 'Ocurrió un error, El ID no coincide con un insumo valido';
        
        LEAVE proc_baja;
    END IF;
    ## Insumo No este asociado a otras Tablas
    IF 
		EXISTS (SELECT * FROM precio_proveedor WHERE insumo_id = p_id) OR
		EXISTS (SELECT * FROM detalle_pedido WHERE insumo_id = p_id) OR
        EXISTS (SELECT * FROM receta_modelo WHERE insumo_id = p_id) 
	THEN
		SET o_resultado = -2;
		SET o_mensaje = 'Ocurrió un error, El Insumo esta asociado a otra tabla';
        
        LEAVE proc_baja;
	END IF;
    
    ### -> Borrar Insumo
    DELETE FROM insumo WHERE id = p_id;
    
END//
DELIMITER ;

INSERT INTO proveedor (nombre, direccion, telefono) VALUES("speedy", "Burzaco", "11111111");
INSERT INTO precio_proveedor (insumo_id, proveedor_id, precio_unitario) VALUES(2, 2, 11111);
CALL baja_insumo(3, @o_resultado, @o_mensaje);
SELECT @o_resultado, @o_mensaje;
DROP PROCEDURE IF EXISTS baja_insumo;


## MODIFICACIONES (TOTAL, No parcial)
DELIMITER //
CREATE PROCEDURE modificar_insumo(IN p_id INT, IN p_nombre VARCHAR(45), IN p_descripcion TINYTEXT, IN p_cantidad_disponible FLOAT, OUT o_resultado INT, OUT o_mensaje VARCHAR(200))
modif_proc: BEGIN
	### -> VARIABLES


	### -> Si ocurre un error inesperado de MySQL
	DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
		SET o_resultado = -99;
		SET o_mensaje = 'Ocurrió un error inesperado al procesar la operación';
	END;
    
    
    ### -> Reiniciar Variables de Salida
	SET o_resultado = 0;
    SET o_mensaje = '';
    
    
    ### -> VALIDACIONES
    ## ID Invalido
	IF p_id < 0 THEN
		SET o_resultado = -1;
		SET o_mensaje = 'Ocurrió un error, El ID ingresado no es valido';
        
        LEAVE modif_proc;
	END IF;
	## ID Matchea con un Insumo
    IF ((SELECT COUNT(*) FROM insumo WHERE id = p_id) != 1) THEN
		SET o_resultado = -1;
		SET o_mensaje = 'Ocurrió un error, El ID no coincide con un insumo valido';

        LEAVE modif_proc;
    END IF;
    ## Parametros a cambiar validos
    IF (p_nombre IS NULL) OR (p_descripcion IS NULL) OR (p_cantidad_disponible IS NULL) THEN
		SET o_resultado = -2;
		SET o_mensaje = 'Ocurrió un error, Alguno de los Parametros es Nulo';
		
        LEAVE modif_proc;
	END IF;
	IF (TRIM(p_nombre) = '') OR (TRIM(p_descripcion) = '') THEN
		SET o_resultado = -2;
		SET o_mensaje = 'Ocurrió un error, Alguno de los Parametros es Vacio';
		
        LEAVE modif_proc;
	END IF;
    IF (p_cantidad_disponible < 0) THEN
		SET o_resultado = -3;
		SET o_mensaje = 'Ocurrió un error, La cantidad disponible no puede ser negativa';
		
        LEAVE modif_proc;
	END IF;
    IF (CHAR_LENGTH(p_nombre) > 45) OR (CHAR_LENGTH(p_descripcion) > 255) THEN
		SET o_resultado = -4;
		SET o_mensaje = 'Ocurrió un error, Overflow en los parametros pasados';
		
        LEAVE modif_proc;
	END IF;
    ## No Debe existir otro nombre igual al que se quiere cambiar
    IF ((SELECT COUNT(*) FROM insumo WHERE nombre = p_nombre AND id != p_id) > 0) THEN
		SET o_resultado = -5;
		SET o_mensaje = 'Ocurrió un error, Ya existe otro insumo con ese nombre';
		
        LEAVE modif_proc;
    END IF;
    
    ### -> MODIFICAR
	UPDATE insumo
    SET nombre = p_nombre, descripcion = p_descripcion, cantidad_disponible = p_cantidad_disponible
    WHERE id = p_id;
END//
DELIMITER ;

CALL modificar_insumo(2, "ME", "ME", 2, @o_resultado, @o_mensaje);
SELECT @o_resultado, @o_mensaje;
DROP PROCEDURE IF EXISTS modificar_insumo;