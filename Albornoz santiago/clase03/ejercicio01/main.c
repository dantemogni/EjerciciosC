#include <stdio.h>
#include <stdlib.h>

//REALIZE UNA FUNCION RECURSIVA

//REALIZAR UNA FUNCION DE FACTOREO SIN EL METODO DE RECURSIVIDAD

int factorial(int);
int factorialAuxiliar(int auxiliar);
int validarOpcion(int opcion,int desde, int hasta,char* msjError);
int validarInt(int numero,char* msjError);




int main()
{
    int numero;

    //printf("Ingrese numero a factorear: \n ");
  //  scanf("%d",&numero);
//
    //numero= factorialAuxiliar(numero);

//    printf("El resultado es: %d",numero);

    printf("Ingrese una opcion: \n");
    scanf("%d",&numero);

    if(validarInt(numero,"Error caracter incorrecto\n"))


    if(validarOpcion(numero,1,6,"-ERROR-\n Opcion no valida\n")==1)
        printf("TODO OK\n");

    return 0;
}


int factorial(int auxiliar)
{
    int respuesta;

    if(auxiliar==1)
        return 1;

    respuesta= auxiliar* factorial(auxiliar-1);

    return respuesta;
}


int factorialAuxiliar(int numero)
{
    int factoreo=1,i ;

    for(i=numero;i>0;i--)
    {
        factoreo= factoreo*i;
    }
    return factoreo;
}

int validarOpcion(int opcion,int desde, int hasta,char* msjError)
{
    if(opcion>hasta || opcion<desde)
    {
        printf(msjError);
        return 0;
    }
    return 1;
}

int validarInt(int numero,char* msjError)
{
    if(numero>'9' || numero<'0')
    {
        printf(msjError);
        return 0;
    }
    return 1;
}
