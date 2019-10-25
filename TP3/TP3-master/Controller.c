#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"
#include "menu.h"

#define RETORNO_OK 1
#define RETORNO_ERROR 0


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int respuesta = RETORNO_ERROR;
    FILE* pFile = fopen(path,"r");

    if(pFile == NULL)
    {
        printf("\nError, el archivo no existe!\n");
    }
    else
    {
        respuesta = ll_clear(pArrayListEmployee);
        respuesta = parser_EmployeeFromText(pFile, pArrayListEmployee);
    }

    return respuesta;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int respuesta = RETORNO_ERROR;

    FILE* pFile = fopen(path,"rb");

    if(pFile == NULL)
    {
        printf("\nEl archivo no existe!\n");
    }
    else
    {
        respuesta = ll_clear(pArrayListEmployee);
        respuesta = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    }

    return respuesta;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* e = employee_new();
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    int respuesta = RETORNO_ERROR;

    if(pArrayListEmployee == NULL)
    {
        printf("\nError, no hay datos en la lista!\n");
    }
    else
    {
        printf("Ingrese un ID: ");
        scanf("%d", &id);
        respuesta = employee_setId(e,nombre);

        printf("\nIngrese un nombre: ");
        scanf("%s",nombre);
        respuesta = employee_setNombre(e,nombre);

        printf("\nIngrese horas trabajadas: ");
        scanf("%d",&horasTrabajadas);
        respuesta = employee_setHorasTrabajadas(e,horasTrabajadas);

        printf("\nIngrese un sueldo: ");
        scanf("%d",&sueldo);
        respuesta = employee_setSueldo(e,sueldo);

        respuesta = ll_add(pArrayListEmployee,e);
    }

    return respuesta;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int respuesta = RETORNO_ERROR;
    int idEmployee = 0;
    int idEmployeeEdit = 0;
    void* aux = employee_new();
    char name[20];
    int horasTrabajadas = 0;
    int sueldo = 0;


    if(pArrayListEmployee != NULL)
    {
        printf("\nIngrese un Id: \n");
        scanf("%d",&idEmployeeEdit);

        for(int i=0; i<ll_len(pArrayListEmployee);i++)
        {
            aux = ll_get(pArrayListEmployee, i);

            respuesta = employee_getId((Employee*) aux, &idEmployee);

            if(respuesta == RETORNO_OK)
            {
                if(idEmployee == idEmployeeEdit)
                {
                    switch(mostrarMenuEdit())
                    {
                    case 1:
                        printf("Ingrese un nombre: \n");
                        scanf("%s",name);
                        respuesta = employee_setNombre((Employee*)aux,name);
                        break;

                    case 2:
                        do
                        {
                            printf("Ingrese horas trabajadas: \n");
                            scanf("%d",&horasTrabajadas);
                            respuesta = employee_setHorasTrabajadas((Employee*)aux, horasTrabajadas);
                        }while(horasTrabajadas<0);  /// PARA MI ESTO ESTA MAL!!!! Iria horasTrabajadas>0 pero hay que testearlo
                        break;

                    case 3:
                        do
                        {
                            printf("Ingrese sueldo: \n");
                            scanf("%d",&sueldo);
                            respuesta = employee_setSueldo((Employee*) aux, sueldo);
                        }while(sueldo<0);
                        break;

                    default:
                        break;
                    }

                    if(respuesta == RETORNO_ERROR)
                    {
                        printf("Problemas para modificar el campo!!!\n");
                    }

                    respuesta = ll_set(pArrayListEmployee,i,aux);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay datos en la lista!\n");
    }

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int respuesta = RETORNO_ERROR;
    int idEmpleado;
    int idEmpleadoRemove;

    Employee* aux= employee_new();

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese un ID: \n");
        scanf("%d",&idEmpleadoRemove);

        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux = (Employee*) ll_get(pArrayListEmployee,i);
            respuesta = employee_getId(aux,&idEmpleado);

            if(respuesta == RETORNO_OK)
            {
                if(idEmpleado==idEmpleadoRemove)
                {
                    respuesta = ll_remove(pArrayListEmployee,i);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay datos en la lista");
    }

    return respuesta;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int respuesta = RETORNO_ERROR;
    Employee* empleado = employee_new();

    int x = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        printf("ID    Nombre    Horas Trabajadas    Sueldo \n");
        for(int i;i<x;i++)
        {
            empleado = (Employee*) ll_get(pArrayListEmployee,i);
            employee_show(empleado);
        }
    }
    else
    {
        printf("No hay datos en la lista");
    }

    return respuesta;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option;
    int orden;
    int respuesta;

    if(pArrayListEmployee!=NULL)
    {
        printf("No hay datos en la lista");
    }
    else
    {
        option = menuSort();
        orden = menuAscDesc();

        switch(option)
        {
        case 1:
            respuesta = ll_sort(pArrayListEmployee,employee_sortById,orden);
            break;

        case 2:
            respuesta = ll_sort(pArrayListEmployee, employee_sortByName, orden);
            break;

        case 3:
            respuesta = ll_sort(pArrayListEmployee, employee_sortByWorkHours, orden);
            break;

        case 4:
            respuesta = ll_sort(pArrayListEmployee, employee_sortBySalary, orden);
            break;

        }

    }

    return respuesta;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int respuesta = RETORNO_ERROR;
    int longitud;

    if(ll_len(pArrayListEmployee)==0)
    {
        printf("No hay datos en la lista");
    }
    else
    {
        FILE *pFile = fopen(path,"w");
        Employee* pEmployee = employee_new();
        if(pFile!=NULL)
        {
            printf("Archivo inexistente");
        }
        else
        {
            longitud = ll_len(pArrayListEmployee);
            for(int i=0;i<longitud;i++)
            {
                pEmployee = (Employee*) ll_get(pArrayListEmployee,i);

                fprintf(pFile,"%d,%s,%d,%d \n",pEmployee->id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);

            }
            respuesta = RETORNO_OK;
            fclose(pFile);
        }

    }

    return respuesta;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int respuesta = RETORNO_ERROR;
    int cuantiti= 0;
    int longet;

    if(ll_len(pArrayListEmployee)==0)
    {
        printf("No hay datos en la lista");
    }
    else
    {
        FILE *pFile = fopen(path,"wb");
        Employee* pEmployee = employee_new();

        if(pFile==NULL)
        {
            printf("Archivo inexistente\n");
        }
        else
        {
            longet = ll_len(pArrayListEmployee);

            for(int i=0;i<longet;i++)
            {
                pEmployee = (Employee*) ll_get(pArrayListEmployee,i);

                cuantiti = fwrite(pEmployee, sizeof(Employee),1,pFile);

                if(cuantiti != 1)
                {
                    printf("ERROR AL ESCRIBIR EL ARCHIVO");
                }
            }
            respuesta = RETORNO_OK;
            fclose(pFile);
        }
    }
    return respuesta;
}

