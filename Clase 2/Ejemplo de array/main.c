#include <stdio.h>
#include <stdlib.h>
#define TAM 6

void mostrarArray(int miarray[], int tamanio);
int maximoDelArray(int maximoArray[], int tamanio);
int minimoDelArray(int minimoArray[], int tamanio);
void inicializarArray(int miarray[],int tamanio);
void cargaDeDatos(int miarray[],int tamanio,char mensaje[]);
float damePromedio(int miarray[],int tamanio);
void ordenamiento(int miarray[],int tamanio);

int main()
{
    int listado[50];
    int maximo=0;
    int minimo=100;
    float promedio=0;

    inicializarArray(listado,TAM);

    cargaDeDatos(listado,TAM,"Ingrese su edad: ");

    mostrarArray(listado,TAM);

    maximo=maximoDelArray(listado,TAM);
    minimo=minimoDelArray(listado,TAM);

    promedio=damePromedio(listado,TAM);

    printf("\nEl maximo es: %d\n",maximo);
    printf("El minimo es: %d\n",minimo);
    printf("El promedio es: %.2f\n",promedio);

    printf("\nNumeros ordenados...\n");

    ordenamiento(listado,TAM);

    mostrarArray(listado,TAM);



    return 0;
}

void mostrarArray(int miarray[],int tamanio)
{
    int i;

    for(i=0; i<tamanio; i++)
    {
        printf("Las edades son: %d\n",miarray[i]);
    }
}

int maximoDelArray(int maximoArray[], int tamanio)
{
    int i;
    int maximo;

    for(i=0; i<TAM; i++)
    {
        if(maximoArray[i]>maximo||i==0)
        {
            maximo=maximoArray[i];
        }
    }

    return maximo;
}

int minimoDelArray(int minimoArray[], int tamanio)
{
    int i;
    int minimo;

    for(i=0; i<TAM; i++)
    {
        if(minimoArray[i]<minimo||i==0)
        {
            minimo=minimoArray[i];
        }
    }

    return minimo;
}

void inicializarArray(int miarray[],int tamanio)
{
    int i;

    for(i=0; i<tamanio; i++)
    {
        miarray[i]=0;
    }
}

void cargaDeDatos(int miarray[],int tamanio,char mensaje[])
{
    int i;
    for(i=0; i<TAM; i++)
    {
        printf(mensaje);
        scanf("%d",&miarray[i]);
    }
    printf("\n");
}

float damePromedio(int miarray[],int tamanio)
{
    float suma=0;
    int i;
    float promedio=0;

    for(i=0; i<tamanio; i++)
    {
        suma=suma+miarray[i];
    }

    promedio=suma/tamanio;

    return promedio;
}

void ordenamiento(int miarray[],int tamanio)
{
    int aux;
    int i;
    int j;

    for(i=0; i<tamanio; i++)
    {
        for(j=i+1; j<tamanio; j++)
        {
            if(miarray[i]>miarray[j])
            {
                aux=miarray[i];
                miarray[i]=miarray[j];
                miarray[j]=aux;
            }
        }
    }
}
