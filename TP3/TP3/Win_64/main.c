#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int len;
    Employee* aux;
    LinkedList* listaEmpleados = ll_newLinkedList();

    Employee* emp1 = employee_newParametros("100","Maria","10");
    //employee_setSueldo()
    emp1->sueldo = 1000;
    Employee* emp2 = employee_newParametros("90","Pedro","8");
    //employee_setSueldo()
    emp2->sueldo = 99;
    Employee* emp3 = employee_newParametros("150","Julia","14");
    //employee_setSueldo()
    emp3->sueldo = 1500;
    Employee* emp4 = employee_newParametros("99","Oscar","5");
    //employee_setSueldo()
    emp4->sueldo = 1800;

    ll_add(listaEmpleados,emp1);//crea un nodo, hacer en el parser
    ll_add(listaEmpleados,emp2);//crea un nodo, hacer en el parser
    ll_add(listaEmpleados,emp3);//crea un nodo, hacer en el parser
    ll_add(listaEmpleados,emp4);//crea un nodo, hacer en el parser

    len = ll_len(listaEmpleados);
    printf("Hay %d empleados cargados...\n", len);
    for(int i=0; i<len; i++)
    {
        aux = (Employee*) ll_get(listaEmpleados,i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
    }

    ll_sort(listaEmpleados, compararPorNombre, 1); //compararPorNombre es la direccion de memoria de la funcion, no el llamado
    //el 1 es el criterio de ordenamiento (1 asc, 0 desc)
    len = ll_len(listaEmpleados);
    printf("Listado ordenado...\n");
    for(int i=0; i<len; i++)
    {
        aux = (Employee*) ll_get(listaEmpleados,i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
    }

    /*******************************/
    /*

    printf("\nQuito 1:\n");
    aux = ll_pop(listaEmpleados, 1);
    printf("Empleado borrado: %d--%s--%d--%d\n",aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
    ll_remove(listaEmpleados,1);
    len = ll_len(listaEmpleados);
     printf("Hay %d empleados cargados...\n", len);
    for(int i=0; i<len; i++)
    {
        aux = (Employee*) ll_get(listaEmpleados,i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
    }

    ll_clear(listaEmpleados);
    printf("\nVacio");
    if(ll_isEmpty(listaEmpleados))
    {
        printf("\nNo hay elementos");
    } else
    {
    len = ll_len(listaEmpleados);
     printf("Hay %d empleados cargados...\n", len);
    for(int i=0; i<len; i++)
    {
        aux = (Employee*) ll_get(listaEmpleados,i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
    }
    }
    */
    /**************************************/
    /* scanf("%d", &option);
     do{
         switch(option)
         {
             case 1:
                 controller_loadFromText("data.csv",listaEmpleados);
                 break;
         }
     }while(option != 10);*/
    return 0;
}
