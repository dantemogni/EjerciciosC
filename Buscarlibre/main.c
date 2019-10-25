#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define A 5

void inicializar(int[], int, int);
int buscarLibre(int[], int, int);

int main()
{
    int array[A];
    char seguir;
    int indice;

    inicializar(array, A, -1);
    do{

        indice=buscarLibre(array, A, -1);
        if(indice!=-1)
        {
            printf("Ingrese un numero: ");
            scanf("%d", &array[indice]);
        }else
        {
            printf("sin espacio");
            break;
        }
        printf("desea continuar?(s/n)");
        fflush(stdin);
        seguir=getche();
    }while(seguir=='s');

    return 0;
}
void inicializar(int vector[], int tam, int inic)
{
    int i;
    for(i=0;i<tam;i++)
    {
        vector[i]=-1;
    }
}

int buscarLibre(int vector[], int tam, int valor)//funcion busca vectores vacios

{
    int indice= -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(vector[i]==valor)
        {
            indice= i;
            break;
        }
    }


    return indice;
}
