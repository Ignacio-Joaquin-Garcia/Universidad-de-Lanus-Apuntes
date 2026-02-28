#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1- Crear un menú que permita agregar Productos a un array de Producto definido en el main de 100 elementos, los productos se deben guardar en un archivo con el siguiente formato
133.50;Milanesa
120.00;Tomates
Es decir precio ; nombre
Al iniciar el programa se deben cargar los productos que ya estén en el archivo.

*/

struct Productos{
    float precio;
    char nombreProducto[20];
};
///Productos
struct Productos cargarProductoParametros(struct Productos p, float precio, char nombreProducto[20]);
struct Productos cargarProductoTeclado(struct Productos p);
void mostrarProducto(struct Productos p);
void mostrarProductos(struct Productos p[100]);
void cargarProductosVacios(struct Productos p[100]);
///Archivo
void crearArchivoProductos(char archivo[50], struct Productos p[100]);
void guardarProductos(char archivo[50], struct Productos p[100]);
struct Productos transformarProductoATexto(char producto[100]);
int leerProductos(char archivo[50], struct Productos p[100]);
int existeArchivo(char archivo[50]);

int main()
{
    struct Productos listaProductos[100];
    cargarProductosVacios(listaProductos);

    int n = 0;
    if(!existeArchivo("productos.txt")){
        listaProductos[n] = cargarProductoTeclado(listaProductos[n]);
        crearArchivoProductos("productos.txt", listaProductos);
        n++;
    } else{
        n = leerProductos("productos.txt", listaProductos);
    };
    mostrarProductos(listaProductos);
    int opcion = 0;
    while(opcion !=4){
        printf("\nEliga que hacer, (1-Anadir Productos, 2-Leer Productos Guardados, 3-Guardar Productos Escritos), 4-Salir): ");
        scanf("%d", &opcion);

        if(opcion == 1){
            listaProductos[n] = cargarProductoTeclado(listaProductos[n]);
            n++;
            mostrarProductos(listaProductos);
        }
        if(opcion == 2){
            struct Productos listaProductosLeer[100];
            cargarProductosVacios(listaProductosLeer);
            leerProductos("productos.txt", listaProductosLeer);
            mostrarProductos(listaProductosLeer);
        }
        if(opcion == 3){
            guardarProductos("productos.txt", listaProductos);
        }
    }
    return 0;
}

///Productos
struct Productos cargarProductoParametros(struct Productos p, float precio, char nombreProducto[20]){
    p.precio = precio;
    strcpy(p.nombreProducto, nombreProducto);
    return p;
};
struct Productos cargarProductoTeclado(struct Productos p){
    printf("\nIngresar Precio del Producto a Agregar: ");
    scanf("%f", &p.precio);
    printf("\nIngresar Nombre del Producto a Agregar: ");
    scanf("%s", p.nombreProducto);
    return p;
};
void mostrarProducto(struct Productos p){
    printf("\n---Producto---");
    printf("\n\tPrecio: %.2f", p.precio);
    printf("\n\tNombre del Producto: %s", p.nombreProducto);
    printf("\n");
};
void mostrarProductos(struct Productos p[100]){
    for(int i = 0; i<100;i++){
        if(p[i].precio != -1){
            mostrarProducto(p[i]);
        }
    }
};
void cargarProductosVacios(struct Productos p[100]){
    for(int i = 0; i<100;i++){
        p[i] = cargarProductoParametros(p[0], -1, "VACIO");
    }

};

///Archivo
void crearArchivoProductos(char archivo[50], struct Productos p[100]){
    FILE * archivoProductos = fopen(archivo, "w");
    for(int i = 0; i<100; i++){
        if(p[i].precio != -1){
            fprintf(archivoProductos, "%.2f;%s\n", p[i].precio, p[i].nombreProducto);
        }
    }
    fclose(archivoProductos);
};
void guardarProductos(char archivo[50], struct Productos p[100]){
    FILE * archivoProductos = fopen(archivo, "a");
    for(int i = 0; i<100; i++){
        if(p[i].precio != -1){
            fprintf(archivoProductos, "%.2f;%s", p[i].precio, p[i].nombreProducto);
        }
    }
    fclose(archivoProductos);
};
struct Productos transformarProductoATexto(char producto[100]){
    struct Productos p;
    int i = 0;
    int noEncontrado = 1;
    char numero[20] = "";
    char nombreProducto[20] = "";
    while(i<100 && noEncontrado){
        if(producto[i] != ';'){
            numero[i] = producto[i];
        } else{
            noEncontrado = 0;
        }
        i++;
    };
    numero[i+1] = '\0';
    int j = 0;
    while(i<100 && (producto[i] != '\0')){
        nombreProducto[j] = producto[i];
        i++;
        j++;
    }
    p.precio = atof(numero);
    strcpy(p.nombreProducto, nombreProducto);
    return p;
};
int leerProductos(char archivo[50], struct Productos p[100]){
    FILE * archivoProductos = fopen(archivo, "r");
    int k = 0;
    while(!feof(archivoProductos)){
        char producto[100] = "";
        fgets(producto,100, archivoProductos);
        struct Productos pAux = transformarProductoATexto(producto);
        p[k] = pAux;
        k++;
    }
    fclose(archivoProductos);
    return k;
};
int existeArchivo(char archivo[50]){
    FILE * comprobacionArchivo = fopen("productos.txt", "r");
    if(comprobacionArchivo == NULL){
        return 0;
    } else{
        return 1;
    }
};
