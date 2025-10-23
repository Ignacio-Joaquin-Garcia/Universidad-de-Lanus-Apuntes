#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

char comparador(char vec1[], char vec2[]){
    if (strcmp(*vec1, *vec2) >= 0){
        return 'S';
    }
    return 'C';
}

int main(){
    char vec1[]= "Hola";
    char vec2[]= "no me importa";

    char res = comparador(vec1, vec2);
    printf("%c", res);

    return 0;
}
