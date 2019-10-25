#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#define RETORNO_OK 1
#define RETORNO_ERROR 0

Employee* employee_new()
{
    Employee* empleado = (Employee*) malloc(sizeof(Employee));

    empleado->id=0;
    strcpy(empleado->nombre,"");
    empleado->horasTrabajadas=0;
    empleado->sueldo=0;

    return empleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* empleado = (Employee*) malloc(sizeof(Employee));

    empleado->id = idStr;
    strcpy(empleado->nombre,nombreStr);
    empleado->horasTrabajadas=horasTrabajadasStr;
    empleado->sueldo = 0;

    return empleado;
}

void employee_delete()
{

}

int employee_setId(Employee* this,int id)
{
    int laR = RETORNO_ERROR;

    if(id > 0 && this != NULL)
    {
        this->id = id;
        laR = RETORNO_OK;
    }

    return laR;
}

int employee_getId(Employee* this,int* id)
{
    int r = RETORNO_ERROR;

    if(this != NULL)
    {
        *id = this->id ;
        r = RETORNO_OK;
    }

    return r;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int r = RETORNO_ERROR;

    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        r = RETORNO_OK;
    }

    return r;
}

int employee_getNombre(Employee* p,char* nombre)
{
    int r = RETORNO_ERROR;

    if(p != NULL)
    {
        strcpy(nombre, p->nombre);
        r = RETORNO_OK;
    }

    return r;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int r = RETORNO_ERROR;

    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        r = RETORNO_OK;
    }

    return r;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int r = RETORNO_ERROR;

    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        r = RETORNO_OK;
    }

    return r;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int r = RETORNO_ERROR;

    if(this != NULL)
    {
        this->sueldo = sueldo;
        r = RETORNO_OK;
    }

    return r;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int r = RETORNO_ERROR;

    if(this != NULL)
    {
        *sueldo = this->sueldo ;
        r = RETORNO_OK;
    }

    return r;
}


void employee_show(Employee* this)
{
    if(this != NULL)
    {
        printf("%4d %s %d %d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
    }
}


/** \brief Devuelve un valor al comparar el campo ID de ambos punteros
 *
 * \param puntero Employee
 * \param puntero Employee
 * \return
 *             0	if both strings are identical (equal)
 *      negative	if the ASCII value of first unmatched character is less than second.
 *      positive    if the ASCII value of first unmatched character is greater than second.
 */

 int employee_sortById(void* employeeA, void* employeeB)
{
    int r;

    if(((Employee*)employeeA)->id > ((Employee*)employeeB)->id)
    {
        r = 1;
    }
    else if(((Employee*)employeeA)->id < ((Employee*)employeeB)->id)
    {
        r = -1;
    }
    else
    {
       r = 0;
    }

    return r;
}

/** \brief Devuelve un valor al comparar el campo Nombre de ambos punteros
 *
 * \param puntero Employee
 * \param puntero Employee
 * \return
 *             0	if both strings are identical (equal)
 *      negative	if the ASCII value of first unmatched character is less than second.
 *      positive    if the ASCII value of first unmatched character is greater than second.
 */
int employee_sortByName(void* employeeA, void* employeeB)
{
    return strcmp(((Employee*)employeeA)->nombre, ((Employee*)employeeB)->nombre);
}

/** \brief Devuelve un valor al comparar el campo Horas Trabajadas de ambos punteros
 *
 * \param puntero Employee
 * \param puntero Employee
 * \return
 *             0	if both strings are identical (equal)
 *      negative	if the ASCII value of first unmatched character is less than second.
 *      positive    if the ASCII value of first unmatched character is greater than second.
 */
int employee_sortByWorkHours(void* employeeA, void* employeeB)
{
     int r;

    if(((Employee*)employeeA)->horasTrabajadas > ((Employee*)employeeB)->horasTrabajadas)
    {
        r = 1;
    }
    else if(((Employee*)employeeA)->horasTrabajadas < ((Employee*)employeeB)->horasTrabajadas)
    {
        r = -1;
    }
    else
    {
       r = 0;
    }

    return r;
}


/** \brief Devuelve un valor al comparar el campo Salario de ambos punteros
 *
 * \param puntero Employee
 * \param puntero Employee
 * \return
 *             0	if both strings are identical (equal)
 *      negative	if the ASCII value of first unmatched character is less than second.
 *      positive    if the ASCII value of first unmatched character is greater than second.
 */
int employee_sortBySalary(void* employeeA, void* employeeB)
{
        int r;

    if(((Employee*)employeeA)->sueldo > ((Employee*)employeeB)->sueldo)
    {
        r = 1;
    }
    else if(((Employee*)employeeA)->sueldo < ((Employee*)employeeB)->sueldo)
    {
        r = -1;
    }
    else
    {
       r = 0;
    }

    return r;
}
