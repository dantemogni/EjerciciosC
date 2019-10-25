#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "Funciones.h"
#include "funcionesAlmuerzo.h"
#include "funcionesEmpleados.h"
#include "funcionesFechaDeIngreso.h"
#include "funcionesMenu.h"
#include "funcionesSector.h"

#define MAX 21


int initEmpleados(eEmpleado list[], int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {

        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        };
    }
    else
    {
        ret = -1;
    };

    return ret;
};


int findEmpty(eEmpleado list[],int len)
{
    int index = -1;
    for(int i=0; i< len ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        };
    };
    return index ;
};

int findEmployeeById(eEmpleado list[],int len, int id)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {

        if( list[i].id == id && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;

};


int addEmployee(eEmpleado list[], int len)
{
    eEmpleado nuevoEmpleado;


    int legajo;
    int index;
    char auxiliarApellido[31];
    char auxiliarNombre[31];
    char auxiliarSexo[31];
    char auxiliarSalario[31];
    char auxiliarDia[5];
    char auxiliarMes[5];
    char auxiliarAnio[10];
    char auxiliarIdSector[10];
    int idSector;
    int isEmpty=0;
    int ret;


    if(list != NULL && MAX>0)
    {
        system("cls");
        fflush(stdin);
        index = findEmpty(list,len);

        printf("--------------ALTA EMPLEADO---------------\n\n");

        if(index == -1)
        {
            printf("NO HAY ESPACIO EN EL SISTEMA!!!!\n\n");
            ret = -1;
            system("pause");
        }
        else
        {
            index++;
            printf("Nuevo Empleado, ID numero %d \n\n",index);
            nuevoEmpleado.legajoEmpleado = index;
            while(funcion_getStringLetras("Ingrese el apellido: ",auxiliarApellido))
            {
                printf("El apellido solo debe tener letras.\n\n") ;
                system("pause");
                system("cls");
            }
            while(funcion_getStringLetras("Ingrese el nombre: ",auxiliarNombre))
            {
                printf("El nombre solo debe tener letras.\n\n") ;
                system("pause");
                system("cls");
            }
            while(funcion_getStringLetras("Ingrese el sexo: ",auxiliarSexo))
            {
                printf("El sexo solo debe tener letras.\n\n") ;
                system("pause");
                system("cls");
            }
            while(funcion_getStringNumerosFlotantes("Ingrese el salario: ",auxiliarSalario))
            {
                printf("El salario solo debe tener numeros.\n\n") ;
                system("pause");
                system("cls");
            }
            while(funcion_getStringNumeros("Ingrese el dia de ingreso: ",auxiliarDia))
            {
                printf("El dia solo debe tener numeros.\n\n") ;
                system("pause");
                system("cls");
            }
            while(funcion_getStringNumeros("Ingrese el mes de ingreso: ",auxiliarMes))
            {
                printf("El mes solo debe tener numeros.\n\n") ;
                system("pause");
                system("cls");
            }
            while(funcion_getStringNumeros("Ingrese el daño de ingreso: ",auxiliarAnio))
            {
                printf("El año solo debe tener numeros.\n\n") ;
                system("pause");
                system("cls");
            }
            while(funcion_getStringNumeros("Ingrese el id del sector: ",auxiliarIdSector))
            {
                printf("El id del sector solo debe tener numeros.\n\n") ;
                system("pause");
                system("cls");
            }
        }




    }



}
