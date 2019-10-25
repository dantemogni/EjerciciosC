#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "entidad.h"
#include "funcionesGet.h"
#include "controller.h"
#include "parser.h"


int main()
{
    int opcion=0;
    LinkedList* listaEntidad= ll_newLinkedList();

    do
    {
        system("cls");
        opcion=getValidIntOpcion("\tMENU\n\n1-ALTA\n2-BAJA\n3-MODIFICAR\n4-CARGAR\n5-GUARDAR\n6-ORDENAR\n7-LISTAR\n8-SALIR\n","ERROR",1,8);

        switch(opcion)
        {
            case 1:
                system("cls");

                break;

            case 2:
                system("cls");

                break;

            case 3:
                system("cls");

                break;

            case 4:
                system("cls");

                break;

            case 5:
                system("cls");

                break;

            case 6:
                system("cls");

                break;

            case 7:
                system("cls");

                break;
        }


    }while(opcion!=8);

    return 0;
}

