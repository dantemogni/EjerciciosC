#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define T 4

/*
void cargarNumerosTest(int [], int);
void mostrarNumeros(int [], int);
void cargarPalabrasTest(char [][50], int);
void mostrarPalabrasTest(char [][50], int);
*/



int main()
{
    /*
    int datosNumericos[T];
    char letra;
    char palabra[T];
    char listadoDePalabras[T][50];
    cargarNumerosTest(datosNumericos, T); //el array  de abajo le pasa los datos al datosNumericos
    mostrarNumeros(datosNumericos, T);
    cargarPalabrasTest(listadoDePalabras, T);
    mostrarPalabrasTest(listadoDePalabras,T);
    */
    char nombre[T][50];
    char apellido[T][50];
    int edad[T];
    cargarApellidoTest(apellido, T);
    cargarNombresTest(nombre, T);
    cargarEdadesTest(edad, T);
    listado(nombre, apellido, edad, T);
    apellidoNombreMenorEdad(nombre,apellido, edad, T);
    ordenarPorEdades(nombre, apellido,edad, T);


    return 0;
}
/*
void cargarNumerosTest(int array[], int cantidad)
{
    int i;
    int aux[]= {22,33,44};
    for(i=0; i<cantidad; i++)
        {
            array[i]=aux[i]; //aca le paso la info de aux a array
        }
}

void mostrarNumeros(int array[], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        printf("%d\n", array[i]);
    }
    printf("/-----------------------------------------------/\n");
}
void cargarPalabrasTest(char array[][50], int cantidad)
{
    char aux[][50]={"Perro","Sol", "Arbol"};
    int i;
    for(i=0; i<cantidad; i++)
    {
     strcpy(array[i],aux[i]);
    }
}
void mostrarPalabrasTest(char array[][50], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        printf("%s\n", array[i]);
    }
    printf("/-----------------------------------------------/\n");
}
*/


