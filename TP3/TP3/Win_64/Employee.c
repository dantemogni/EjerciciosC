#include "Employee.h"

Employee* employee_newParametros(char* idStr,
                                 char* nombreStr,
                                 char* horasTrabajadasStr)//el sueldo se setea
{
    Employee* empleado;
    empleado = (Employee*) malloc(sizeof(Employee));
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

