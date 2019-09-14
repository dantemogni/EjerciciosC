#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ejercicio de clase:
/*
int main()
{
    char apellido[15];
    char nombre[15];
    char apellidoNombre[30];
    int i;

    printf("Ingrese el apellido: ");
    gets(apellido);
    printf("Ingrese el nombre: ");
    gets(nombre);
}
*/

int main()
{
    char palabra[10];
    char palabra2[10];
    char todo[50];
    int length;

    printf("Ingrese una palabra: ");

    gets(palabra);

    length = strlen(palabra);

    strcpy(palabra2, "Perro");

    if(stricmp(palabra, palabra2)==0)
    {
        printf("\nSon iguales");
    }
    else
    {
            printf("\nNo son iguales");
    }

    strcpy(todo, palabra); //para sacar el @ que aparecia por el dato basura
    strcat(todo, palabra2);
    strcat(todo, "Chau");
    printf("\nconcatenar: %s", todo);

    printf("\nLa palabra es %s y el largo es %d", palabra, length);
    printf("\nLa palabra 2 es %s", palabra2);
    return 0;
}
