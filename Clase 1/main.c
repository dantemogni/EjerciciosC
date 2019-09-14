#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int edad[50];
    float altura[50];
    char sexo[50];
    int i=0;
    int j=0;
    char opcion;
    int maxEdad=0;
    int minEdad=0;
    float maxAltura=0;
    float minAltura=0;
    int suma=0;
    float promedioEdad=0;
    /*
    printf("La edad es: %d\n\n",edad);
    printf("La edad es: %.2f\n\n",altura);
    printf("Su edad es: %d y su altura es: %.2f\n\n",edad,altura);
    */

    /*
    printf("Ingrese la edad: ");
    scanf("%d",&edad);

    printf("Ingrese la altura: ");
    scanf("%f",&altura);

    printf("Ingrese el sexo: ");
    fflush(stdin);
    scanf("%c",&sexo);

    printf("La edad es: %d, la altura es: %.2f, el sexo es: %c",edad,altura,sexo);

    printf("\n");
    */

    /*
    if(edad<13)
    {
        printf("Es un ninio");
    }else if (edad>=13 && edad<18)
    {
        printf("Es un adolescente");
    }else
    {
        printf("Es un adulto");
    }

    printf("\n");

 ////////////////////////////////////////////////////////////////////////////////////////

    if(sexo=='F')
    {
        printf("Es femenino");
    }
    else if(sexo=='M')
    {
        printf("Es Masculino");
    }else
    {
        printf("Es un helicoptero apache");
    }

     printf("\n");
     */


     do
     {
        do
        {
        printf("Ingrese la edad: ");
        scanf("%d",&edad[i]);
        }while(edad[i]<1 || edad[i]>110 );

        suma=suma+edad[i];

        do
        {
            printf("Ingrese la altura: ");
            scanf("%f",&altura[i]);
        }while(altura[i]<1.40 && altura[i]>2.00);

        do
        {
        printf("Ingrese el sexo: ");
        fflush(stdin);
        scanf("%s",&sexo[i]);
        }while(sexo[i]!='f' && sexo[i]!='m');

        if(edad[i]>maxEdad && sexo[i]=='f')
             {
                 maxEdad=edad[i];
             }

         if(i==0)
        {
          minEdad=edad[i];
          maxAltura=altura[i];
          minAltura=altura[i];
        }

        i++;

        printf("Desea continuar ?: ");
        fflush(stdin);
        scanf("%c",&opcion);

     }while(opcion!='n');

     for(j=0;j<i;j++)
     {

         if(edad[j]>maxEdad && sexo[j]=='f')
             {
                 maxEdad=edad[j];
             }

         if(minEdad>edad[j])
            {
                minEdad=edad[j];
            }

         if(maxAltura<altura[j])
            {
                maxAltura=altura[j];
            }

         if(minAltura>altura[j])
            {
                minAltura=altura[j];
            }

     }

     for(j=0;j<i;j++)
     {
        if(maxEdad==edad[j])
           {
               printf("\n\nLa mujer mas vieja mide: %.2f",altura[j]);
           }
        if(minEdad==edad[j])
           {
               printf("\n\nEl mas joven mide mide: %.2f",altura[j]);
           }
        if(maxAltura==altura[j])
           {
               printf("\n\nEl sexo del mas alto es: %c",sexo[j]);
           }
        if(minAltura==altura[j])
           {
               printf("\n\nLa edad del hombre mas bajo es: %d",edad[j]);
           }
     }

     promedioEdad=suma/5;

     printf("El promedio de las edades es de: %f",promedioEdad);

    return 0;
}
