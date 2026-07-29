# 🚀 Guía de Concurrencia en Go (de Java a Golang)

Este repositorio contiene ejemplos prácticos para entender la concurrencia en Go, comparando con el modelo tradicional de hilos en Java.

El objetivo es pasar de un enfoque basado en **memoria compartida** a uno basado en **comunicación por canales**.

---

## 1. Conceptos básicos

### Goroutines
- Son hilos livianos gestionados por el runtime de Go.
- Consumen pocos recursos en comparación con los threads de Java.
- Se crean con la palabra clave `go`.

Ejemplo:
```go
go miFuncion()
```

---

### Filosofía de Go

> "No comuniques compartiendo memoria; comparte memoria comunicando"

Esto implica:
- Evitar múltiples goroutines accediendo a la misma variable
- Preferir el uso de **channels** para intercambiar datos

---

## 2. Instalación

1. Descargar Go desde: https://go.dev/dl  
2. Instalar siguiendo el asistente  
3. Verificar instalación:

```bash
go version
```

---

## 3. Comandos básicos

| Comando | Descripción |
|--------|------------|
| `go mod init <nombre>` | Inicializa el módulo del proyecto |
| `go run archivo.go` | Ejecuta el programa |
| `go build` | Genera un ejecutable |
| `go fmt ./...` | Formatea el código |
| `go mod tidy` | Limpia dependencias |
| `go run -race archivo.go` | Detecta condiciones de carrera |

---

## 4. Ejecución de los ejemplos

Primero, inicializar el módulo en la raíz del proyecto:

```bash
go mod init ejemplos-concurrencia
```

Luego ejecutar cada ejemplo:

---

### Ejemplo 1: Race Condition
```bash
go run ejemplo_1/concurrencia_basica_unsafe.go
```

---

### Ejemplo 2: Mutex
```bash
go run ejemplo_2/concurrencia_mutex.go
```

---

### Ejemplo 3: Operaciones atómicas
```bash
go run ejemplo_3/concurrencia_atomica.go
```

---

### Ejemplo 4: Comparativa de rendimiento
```bash
go run ejemplo_4/comparativa_rendimiento.go
```

---

### Ejemplo 5: Procesamiento en paralelo
```bash
go run ejemplo_5/procesamiento_paralelo_array.go
```

---

### Ejemplo 6: Channels
```bash
go run ejemplo_6/canales_basico.go
```

---

### Ejemplo 7: Worker Pool
```bash
go run ejemplo_7/worker_pool.go
```

---

## 5. Resumen

- **Mutex:** útil para proteger memoria compartida  
- **Atomic:** eficiente para operaciones simples (ej. contadores)  
- **Channels:** forma idiomática de comunicación en Go  
- **Worker Pool:** patrón para controlar concurrencia  

---

## 6. Recomendaciones

- Usar `-race` para detectar problemas de concurrencia  
- Evitar compartir variables entre goroutines sin sincronización  
- Priorizar channels cuando sea posible  

---

Este repositorio funciona como base práctica para experimentar con concurrencia en Go.