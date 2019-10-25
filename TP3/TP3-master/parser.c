#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#define RETORNO_OK 1
#define RETORNO_ERROR 0


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int launch = RETORNO_ERROR;
    int cuality = 0;
    char idFile[4];
    char name[20];
    char helfishFile[8];
    char saltedFile[10];

    if(pFile != NULL)
    {
        do
        {
            cuality = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idFile,name,helfishFile,saltedFile);
            if(cuality!=4)
            {
                printf("\nProblemas para cargar el archivo data.csv\n");
            }
            else
            {
                Employee* retEmployee = employee_new();
                retEmployee->id=atoi(idFile);
                strcpy(retEmployee->nombre,name);
                retEmployee->horasTrabajadas=atoi(helfishFile);
                retEmployee->sueldo=atoi(saltedFile);
                ll_add(pArrayListEmployee,retEmployee);
            }
        }while(!feof(pFile));
        fclose(pFile);
        launch=RETORNO_OK;
    }
    else
    {
        printf("Archivo vacio\n");
    }

    return launch;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int launch = RETORNO_ERROR;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            Employee* retEmployee = employee_new();
            launch = fread(retEmployee,sizeof(Employee),1,pFile);
            if(launch==1)
            {
                ll_add(pArrayListEmployee,retEmployee);
            }
        };
        fclose(pFile);
        launch = RETORNO_OK;
    }
    else
    {
        printf("\nArchivo vacio\n");
    }

    return launch;
}
