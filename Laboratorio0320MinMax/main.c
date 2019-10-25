#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>//para trabajar con tipos de datos, incluye toupper tolower

//void main(void)
//{
//    int n1;
//    int n2;
//    float resultado;
//
//    n1 = 5;
//    n2 = 2;
//    resultado = n1/n2; //Trunca el resultado a 2 porque el c�lculo y el truncado se realiza antes de la asignaci�n.
//
//    resultado = (float)n1/n2; //Castea moment�neamente n1 como flotante para evitar el truncado. M�todo correcto.
//}

//int main()//La funci�n devuleve un entero, no tiene punteros entre los par�ntesis.
//{
//    int i = 0;//Conviene inicializarlo en cero para poder recorrer vectores.
//
////    while(i < 10)
////    {
////        i++;
////        printf( "%d \n", i);
////
//////        printf( "%d \n", (i+1);//Alternativa.
//////        i++;
////
////
////    do{
////
////        i++;
////        printf( " %d \n", i);
////
////
////    }while(i < 10);//�nica estructura de control que finaliza con punto y coma.
//
//
//    for(i=0; i<10; i++){//Para cuando s� de antemano la cantidad de repeticiones. 1ra vez: i=0; i<10 2da en adelante i++; i<10
//
//            printf( " %d \n", (i+1));
//    }
//
//    return 0;//Retorno de la funci�n, obligado.
//}

int main()//La funci�n devuleve un entero, no tiene punteros entre los par�ntesis.
{
//    Switch s�lo soporta como valores n�meros enteros o caracteres 'a'
//
//    Un contador cuenta ocurrencias (increment�ndose de fomar constante) y debe estar inicializada en 0
//
//    Un acumulador es una suma de variables y debe estar incializado en 0
//
//    En m�ximos y m�nimos las variables no se inicializan y se les asigna la primera ocurrencia.

    int valor, min, max, flag=0;

    char rta;

    do{

        printf("Ingrese un valor:");

        scanf("%d", &valor);

        if(flag == 0 || valor > max){
            max = valor;
        }
        if(flag == 0 || valor < min){
            min = valor;
            flag = 1;
        }

        do{
            printf("Continuar? S / N:");
            fflush(stdin);
            scanf("%c", &rta);
            rta = toupper(rta);//pasa la variable a may{uscula para no tener que contemplar todos los casos.
        }while(rta != 'S' && rta != 'N');

    }while(rta == 'S');

    printf("El maximo es: %d\nEl minimo es: %d", max, min);

    return 0;//Retorno de la funci�n, obligado.
}

//#include <limits.h>//Permite utilizar el valor m�ximo y m�nimo capaz de ser almacenado en el tipo de variable.

//void main(void)
//{
//    int i;
//    int suma = 0;
//    int max = INT_MIN; // constante definida en limits.h
//    int min = INT_MAX; // constante definida en limits.h
//    for(i=0; i<10; i++)
//    {
//        int aux;
//        scanf("%d",&aux);
//        suma=suma+aux;
//        if(aux>max)
//        {
//            max = aux;
//        }
//        if(aux<min)
//        {
//            min = aux;
//        }
//    }
//    printf("la suma es:%d\n",suma);
//    printf("El maximo es:%d\n",max);
//    printf("El minimo es:%d\n",min);
//}
