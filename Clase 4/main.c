#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4

void cargarConDatosEnteros(int array[],int cantidad);
void cargarConDatosConNombres(char array[][50],int cantidad);
void funcionInNombrable(int arrayEdad[],char arrayNombre[][50],int cantidad);

int main()
{
    char nombre[TAM][50];
    int edades[TAM];
    int i;


    /*
        for(i=0;i<TAM;i++)
        {
            printf("Ingrese su edad: ");
            scanf("%d",&edades[i]);
            printf("Ingrese su nombre: ");
            fflush(stdin);
            gets(nombre[i]);
        }
    */
    cargarConDatosEnteros(edades,TAM);
    cargarConDatosConNombres(nombre,TAM);
    funcionInNombrable(edades,nombre,TAM);

    for(i=0; i<TAM; i++)
    {
        printf("Usted  es %s y tiene %d  anios de edad \n",nombre[i],edades[i]);
    }


    return 0;
}
void cargarConDatosEnteros(int array[],int cantidad)
{
    int aux[]= {4,10,8,2};
    int i;
    for(i=0; i<cantidad; i++)
    {
        // array[i]=i*10;
        array[i]= aux[i];
    }

}

void cargarConDatosConNombres(char array[][50],int cantidad)
{
    char aux[4][50]= {"Alfredo","Rogelio","Julieta","Pablo"};
    int i;
    for(i=0; i<cantidad; i++)
    {
        strcpy(array[i],aux[i]);
    }
}

void funcionInNombrable(int arrayEdad[],char arrayNombre[][50],int cantidad)
{
    int i;
    int maxEdad=0;

     for(i=0; i<cantidad; i++)
    {
        if(arrayEdad[i]>maxEdad)
        {
            maxEdad=arrayEdad[i];
        }
    }

    for(i=0; i<cantidad; i++)
        {
            if(arrayEdad[i]==maxEdad)
            {
                {
                    printf("\nEl que tiene mas edad es: %s, teniendo %d anios\n\n",arrayNombre[i],arrayEdad[i]);
                }
            }
        }
}
