#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int validarLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


int validarMail(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] != '@') && (str[i] != '.'))
           return 0;
       i++;
   }
   return 1;
}

int pedirInt(char mensaje[])
{
    int aux;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&aux);
    return aux;
}

int pedirString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);

    if(validarLetras(input))
    {
        return 1;
    }
    return 0;
}

int validarNumero(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int pedirStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    pedirString(mensaje,aux);
    if(validarNumero(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int validarStringNumerico(int opcion,char mensaje[], char aux[])
{
  while(!pedirStringNumeros(mensaje,aux))
        {
            printf("\nERROR. Ingrese solo numeros\n");
        }
    opcion = atoi(aux);
    return opcion;
}

int validarMenu(int opcion, int valorA, int valorB, char mensaje[], char aux[])
{
        opcion = atoi(aux);

    while(opcion < valorA || opcion > valorB)
    {
        printf("\nERROR!!. Opcion invalida, solo ingrese el numero dentro de las opciones disponibles\n");
        fflush(stdin);
        while(!pedirStringNumeros(mensaje, aux))
            {
                printf("\nERROR!!! Ingrese solo numeros\n");
            }
        opcion = atoi(aux);
 }
 return opcion;
}
void validarStringLetras(char mensaje[], char aux[])
{
    while(!pedirString(mensaje, aux))
    {
        printf("\nERROR. El dato ingresado debe estar compuesto solo letras\n\n");
    }
}
