#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#define T 3



int main()
{
    char nombreCompleto[T][50];
    char sexo[T];
    char opcion;
    int edad[T];
    int legajo[T];
    int nota1[T];
    int nota2[T];
    int nota3[T];
    int numeroAlumno=0;
    float promedio[T];

    inicializarvector(nombreCompleto, sexo, edad, legajo, nota1, nota2, nota3, promedio);
    do{
        printf("1.Datos ingresados\n2.Modificar\n3.Informe de datos\n4.Informe detallado de promedios\n5.Ordenar por nombre\n6.Ordenar por sexo\n7.mostrar juanes\n8.mostrar P\n9.mostrar grafico de edades\n10.salir\nSeleccion: ");
        fflush(stdin);
        scanf("%c",&opcion);
        opcion=toupper(opcion);
        system("cls");

        switch(opcion)
        {
            case '1':
                if(numeroAlumno<=T)
                {
                    numeroAlumno=cargarAlumnos(nombreCompleto,sexo, edad,legajo,nota1, nota2, nota3,numeroAlumno, promedio);
                }else
                {
                    printf("listado lleno\n");
                    system("pause");
                }
                break;

            case '2':
                if(numeroAlumno!=0)
                {
                    seleccionDatos(nombreCompleto, sexo, edad, legajo, nota1, nota2, nota3, numeroAlumno, promedio);
                }else
                {
                    printf("Aun no se a ingresado ningun dato\n");
                    system("pause");
                }
                break;

            case '3':
                if(numeroAlumno!=0)
                {
                    cargarDatos(nombreCompleto, sexo, edad, legajo, nota1, nota2, nota3, numeroAlumno, promedio);
                }else
                {
                    printf("Aun no se a ingresado ningun dato\n");
                    system("pause");
                }
                break;
            case '4':
                if(numeroAlumno!=0)
                {
                    calculoDePromedios(nombreCompleto, legajo, numeroAlumno, promedio);
                }else
                {
                    printf("Aun no se a ingresado ningun dato\n");
                    system("pause");
                }
                break;

            case '5':
                if(numeroAlumno!=0)
                {
                ordenarNombre(nombreCompleto, sexo, edad, legajo, nota1, nota2, nota3, numeroAlumno, promedio);
                }else
                {
                    printf("Aun no se a ingresado ningun dato\n");
                    system("pause");
                }
                break;

            case '6':
                if(numeroAlumno!=0)
                {
                ordenarSexo(nombreCompleto, sexo, edad, legajo, nota1, nota2, nota3, numeroAlumno, promedio);
                }else
                {
                    printf("Aun no se a ingresado ningun dato\n");
                    system("pause");
                }
                break;

            case '7':
                if(numeroAlumno!=0)
                {
                mostrarJuanes(nombreCompleto, sexo, edad, legajo, nota1, nota2, nota3, numeroAlumno, promedio);
                }else
                {
                    printf("Aun no se a ingresado ningun dato\n");
                    system("pause");
                }
                break;

            case '8':
                if(numeroAlumno!=0)
                {
                mostrarP(nombreCompleto, sexo, edad, legajo, nota1, nota2, nota3, numeroAlumno, promedio);
                }else
                {
                    printf("Aun no se a ingresado ningun dato\n");
                    system("pause");
                }
                break;

            case '9':
                if(numeroAlumno!=0)
                {
                porcentajeEdad(edad, numeroAlumno);
                }else
                {
                    printf("Aun no se a ingresado ningun dato\n");
                    system("pause");
                }
                break;

            case 'S':
                printf("Que tenga un buen dia...");
                system("pause");

                break;

            default:
                printf("ERROR\n");
                system("pause");

                break;
        }
        system("cls");

    }while(opcion!='S');


    return 0;
}


