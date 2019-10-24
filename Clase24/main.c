#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void inicializar(int[], int);
void mostrar(int[], int);
void ordenar(int[], int);
void swap(int*, int*);

int main()
{
    int pos;
    int numeroOrden[50];
    inicializar(numeroOrden,50);

    mostrar(numeroOrden,50);
    pos = 0;
    char opcion;
    do{
        printf("Ingrese Numero de orden: ");
        scanf("%d",&numeroOrden[pos]);

        pos++;
        //printf("\nIngresa Otro?");
        //fflush(stdin);
        //gets(&opcion);

    }while(pos<10);

    mostrar(numeroOrden,50);
    ordenar(numeroOrden,50);
    mostrar(numeroOrden,50);

    return 0;
}

void inicializar(int array[], int tam){

        int i;
        for(i=0;i<tam;i++){
            array[i]=-1;
        }
}

void mostrar(int array[], int tam){

        int i=0;
        for(i=0;i<tam;i++){
                if(array[i]!=-1){
                    printf("%d-%d \n ",i, array[i]);
                }

        }
}

void ordenar(int array[], int tam){
    int i=0;
    int j=0;
    for(i= 0; i< tam -1;i++){
        for(j=i+1;j<tam;j++){
            if(array[i]> array[j])
            {
                int a;
                swap(&array[i], &array[j]);
            }
        }
    }

}
void swap(int* a, int* b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

//********************************************************************
//********************************************************************
//********************************************************************
//#include <stdio.h>
//#include <stdlib.h>
//#define CANTIDAD 50
//
//void menu(int*, int);
//void ingresarNro(int*, int);
//void swap(int*, int* );
//void mostrarNros(int*,int);
//
//
//int main()
//{
//    int numeros[CANTIDAD];
//    menu(numeros, CANTIDAD);
//    return 0;
//}
//
//void inicializar()
//{
//
//}
//
//void menu(int* numeros, int cantidad)
//{
//    int opciones;
//    char rta = 's';
//    do
//    {
//        printf("1 - INGRESAR NRO. DE ORDEN\n2 - ORDENAR\n3 - MOSTRAR\n");
//        scanf("%d", &opciones);
//        switch(opciones)
//        {
//        case 1:
//            system("cls");
//            ingresarNro(numeros);
//            break;
//        case 2:
//            system("cls");
//            ordenarNro(numeros, cantidad);
//            break;
//        case 3:
//            system("cls");
//            mostrarNros(numeros, cantidad);
//            break;
//        }
//        system("cls");
//    }
//    while(opciones!=-1);
//}
//
//void ingresarNro(int* numeros)
//{
//    int i;
//    int numeroOrden;
//    do
//    {
//        printf("\nINGRESE NRO. DE ORDEN: ");
//        fflush(stdin);
//        scanf("%d", &numeroOrden);
//        numeros[i] = numeroOrden;
//        i++;
//        printf("\nDesea continuar? [s/n]");
//        fflush(stdin);
//        scanf("%c", &rta);
//    }
//    while(rta!='s');
//}
//void ordenarNro(int* numeros, int cantidad)
//{
//    int i=0;
//    int j=0;
//    printf("\nNUEMEROS ORDENADOS CON EXITO\n");
//    for(i=0; i<cantidad-1; i++)
//    {
//        for(j=i+1; j<cantidad; j++)
//        {
//            if(*(numeros+i>numeros[j])
//            {
//                swap(&numeros[i], &numeros[j]);
//            }
//        }
//    }
//}
//
//void mostrarNros(int* numeros, int cantidad)
//{
//    int i;
//    for(i=0; i<cantidad; i++)
//    {
//        if(numeros*!=-1)
//        {
//            printf("%d-%d \n ",i, numeros*);
//        }
//    }
//}
//void swap(int* a, int* b)
//{
//    int c;
//    c = *a;
//    *a = *b;
//    *b = c;
//}
