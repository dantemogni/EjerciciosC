#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char id[20];
    char nombre[20];
    char horasTrabajadas[20];
    Employee* emp;
    ll_add(pArrayListEmployee,emp);
    fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas); //lectura fantasma
    while(!feof(pFile))
    {
    fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas);
    ll_add(pArrayListEmployee,emp);
    emp = employee_newParametros(id,nombre,horasTrabajadas);
    }
    return 1;
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

    return 1;
}
