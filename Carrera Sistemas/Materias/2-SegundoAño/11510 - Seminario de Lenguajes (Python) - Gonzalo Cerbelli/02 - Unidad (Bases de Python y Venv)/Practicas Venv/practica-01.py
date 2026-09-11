from sqlalchemy.orm import declarative_base, sessionmaker
from sqlalchemy import create_engine, Column, Integer, String

## --- Creacion ---
# Crear motor de base de datos (SQLite)
engine = create_engine('sqlite:///igna.db', echo=True) # Echo=True -> Muestra las instrucciones SQL en ejecución por consola

# Declarar la base (Clase base especial usada para declarar tablas. Conexion entre clase y tabla)
Base = declarative_base()

# Crear una tabla (Clase = Tabla) (Atributos = Columna)
class Vehiculo(Base): # Importante el parametro Base!
	__tablename__ = 'vehiculos'
	id = Column(Integer, primary_key=True)
	modelo = Column(String)
	ano = Column(Integer)
	
# Crear las tablas en el archivo si no existen
Base.metadata.create_all(engine)


## --- Consultas ---
# Crear una sesión para interactuar con la base
# Engine  -> Comunicacion con SQLite
# Session -> Trabaja con Objetos / Datos
# Las sesiones sirven para manejar distintos contextos de trabajo con la misma db
Session = sessionmaker(bind=engine) # Crea la fabrica de sesiones para el motor SQLite en la base 'igna.db'
session = Session() # Crea una sesion concreta

# Agregar un vehiculo
nuevo_vehiculo = Vehiculo(modelo="Peugeot", ano=1987)
session.add(nuevo_vehiculo)
session.commit()

# Consultar
for vehiculo in session.query(Vehiculo).all():
	print(vehiculo.modelo, vehiculo.ano)