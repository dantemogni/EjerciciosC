#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>

Employee* employee_new()
{
     Employee* emp = (Employee*) malloc(sizeof(Employee));
     return emp;
}


Employee* employee_newParametros(char* idStr,
                                 char* nombreStr,
                                 char* horasTrabajadasStr)//el sueldo se setea
{
    Employee* empleado;
    empleado = employee_new();
    empleado->id = atoi(idStr);
    strcpy(empleado->nombre, nombreStr);
    empleado->horasTrabajadas = atoi(horasTrabajadasStr);

    return empleado;
}
int compararPorNombre(void* p1, void* p2)
{
    Employee* emp1 = (Employee*) p1;
    Employee* emp2 = (Employee*) p2;

    return strcmp(emp1->nombre, emp2->nombre);
}

int employee_setSueldo(Employee* this,int sueldo){

    int retorno = -1;

    if(this!= NULL && sueldo > 0){
        this->sueldo = sueldo;
        retorno = 0;
    }

    return retorno;
}

