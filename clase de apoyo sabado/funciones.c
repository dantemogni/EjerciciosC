#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


void cargarNombresTest(char array[][50], int tamanio)
{
    char aux[][50]={"Alfredo","Rogelio", "Julieta", "Pablo"};
    int i;
    for(i=0; i<tamanio; i++)
    {
     strcpy(array[i],aux[i]);
    }
}
void cargarApellidoTest(char array[][50], int tamanio)
{
    char aux[][50]={"Mercurio","Agua", "Roberto", "McCarteney"};
    int i;
    for(i=0; i<tamanio; i++)
    {
     strcpy(array[i],aux[i]);
    }
}
void cargarEdadesTest(int array[], int tamanio)
{
    int aux[]={22,33,18,55};
    int i;
    for(i=0; i<tamanio; i++)
    {
     array[i]=aux[i];
    }
}
void listado(char nombre[][50], char apellido[][50],int edad[], int tamanio) //tamanio es iguial a cantidad pero aca hay mas elementos
{
    int i;
    for(i=0; i<tamanio; i++)
    {
    printf("Apellido: %s\n", apellido[i]);
    printf("Nombre: %s\n", nombre[i]);
    printf("Edad: %d\n\n", edad[i]);
    }
}
void apellidoNombreMenorEdad(char nombre[][50], char apellido[][50], int edad[], int tamanio)
{
    int i;
    int indice;
    int min;
    for(i=0; i<tamanio; i++)
    {
        if(edad[i]<min || indice==0)
        {
            min = edad[i];
            indice = i;
        }
    }
    printf("\n/----------------------------------------/\n\n");
    printf("El nombre del menor es %s, el apellido %s y la edad %d \n", nombre[indice], apellido[indice], edad[indice]);
    printf("\n/----------------------------------------/\n");

}
void ordenarPorEdades(char nombre[][50], char apellido[][50], int edad[], int tamanio)//tamanio=cantidad de elementos
{
    int i;
    int j;
    int auxEdad; //tengo que poner un auxiliar para guardar el dato
    char auxNombre[tamanio][50];
    char auxApellido[tamanio][50];
    int orden;

    for(i=0;i<tamanio-1;i++)
    {
        for(j=i+1;j<tamanio;j++)
        {
            if(edad[i]>edad[j])
            {
                auxEdad = edad[i];
                edad[i] = edad[j];
                edad[j] = auxEdad;
                strcpy(auxApellido, apellido[i]);
                strcpy(apellido[i], apellido[j]);
                strcpy(apellido[j], auxApellido);
                strcpy(auxNombre, nombre[i]);
                strcpy(nombre[i], nombre[j]);
                strcpy(nombre[j], auxNombre);
            }
        }
    }
    printf("\n\tLISTA ORDENADA DE MENOR A MAYOR:\n\n");
    for(i=0; i<tamanio; i++)
    {
    printf("\tApellido: %s\n", apellido[i]);
    printf("\tNombre: %s\n", nombre[i]);
    printf("\tEdad: %d\n\n", edad[i]);
    }
}
