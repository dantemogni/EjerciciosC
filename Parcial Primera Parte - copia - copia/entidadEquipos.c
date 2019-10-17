#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "entidadEquipos.h"
#include "validaciones.h"


void subMenuEquipo(eEquipos equipos[], int cantidad)
{
    int opcion;
    char opcionesStr[251];
    int i;

    do
    {
        printf("\n***EQUIPOS***\n\n");
        printf("1 - INGRESAR NUEVO EQUIPO\n2 - LISTAR ALFABETICAMENTE LOS EQUIPOS\n3 - MODIFICAR EQUIPO\n4 - ELIMINAR EQUIPO\n5 - VOLVER AL MENU PRINCIPAL\n\n");
        validarStringNumerico(opcion, "Que desea hacer? ", opcionesStr);
        opcion = validarMenu(opcion, 1, 5, "\nREINGRESE LA OPCION\n\n1 - INGRESAR NUEVO EQUIPO\n2 - LISTAR ALFABETICAMENTE LOS EQUIPOS\n3 - MODIFICAR EQUIPO\n4 - ELIMINAR EQUIPO\n5 - VOLVER AL MENU PRINCIPAL\n\n", opcionesStr);

        switch(opcion)
        {
        case 1:
            system("cls");
            cargaEquipos(equipos, cantidad);
            break;
        case 2:
            if(equipos[0].codigoEquipo==-1)
            {
                printf("\nERROR. Primero debe ingresar un jugador\n");
                system("pause");
                break;
            }

            system("cls");
            listarAlfabeticamenteEquipos(equipos,cantidad);
            break;
        case 3:
            if(equipos[0].codigoEquipo==-1)
            {
                printf("\nERROR. Primero debe ingresar un jugador\n");
                system("pause");
                break;
            }
            system("cls");
            modificarEquipo(equipos, cantidad);
            break;
        case 4:
            if(equipos[0].codigoEquipo==-1)
            {
                printf("\nERROR. Primero debe ingresar un jugador\n");
                system("pause");
                break;
            }
            system("cls");
            eliminarEquipo(equipos, cantidad);
        case 5:
            break;
        default:
            printf("\nERROR!! Opcion Invalida\n");
            break;
        }
    }
    while(opcion > 0 && opcion < 5);
}

void cargaEquipos(eEquipos equipos[], int cantidad)
{
    int i;
    char hardNombres [][51] = {"Basta Chicos", "Cer Vantes", "River Plate", "All United", "Los Pepes"};
    char hardLocalidad [][33] = {"Lomas de Zamora", "Glew", "Coburza", "Lanus", "Guernica"};

    printf("\n// Ingresar el nombre del equipo: ...\n");
    //scanf

    printf("// Ingresar la localidad del equipo: ...\n\n");
    //scanf


    for(i=0; i<cantidad; i++)
    {
        strcpy(equipos[i].nombre,hardNombres[i]);
        strcpy(equipos[i].localidad,hardLocalidad[i]);
        equipos[i].codigoEquipo = i+1;
    }
    mostrarEquipos(equipos, cantidad);
}

void mostrarEquipos(eEquipos equipos[], int cantidad)
{
    int i;

    printf("\n\tCODIGO\t\tNOMBRE DE EQUIPO\t\tLOCALIDAD\n");
    for(i=0; i<cantidad; i++)
    {
        if(equipos[i].codigoEquipo!=-1)
        {
            printf("\t%d\t\t%s\t\t\t%s\n",
                   equipos[i].codigoEquipo,
                   equipos[i].nombre,
                   equipos[i].localidad);
        }
    }
}

void listarAlfabeticamenteEquipos(eEquipos equipos[], int cantidad)
{
    int i;
    int j;
    int auxCodigo;
    char auxNombre[51];
    char auxLocalidad[33];

    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(strcmp(equipos[i].nombre,equipos[j].nombre) != -1) // si es -1, quiere decir que es MENOR, ordena de menor a mayor
            {
                auxCodigo = equipos[i].codigoEquipo;
                equipos[i].codigoEquipo = equipos[j].codigoEquipo;
                equipos[j].codigoEquipo = auxCodigo;

                strcpy(auxNombre, equipos[i].nombre);
                strcpy(equipos[i].nombre, equipos[j].nombre);
                strcpy(equipos[j].nombre, auxNombre);

                strcpy(auxLocalidad, equipos[i].localidad);
                strcpy(equipos[i].localidad, equipos[j].localidad);
                strcpy(equipos[j].localidad, auxLocalidad);
            }
        }
    }
    mostrarEquipos(equipos, cantidad);

}

void modificarEquipo(eEquipos equipos[], int cantidad)
{
    int auxCodigo;
    char auxCodigoStr[256];
    char auxNombre[51];
    char auxLocalidad[33];
    int menuModificar;
    char menuModificarStr[256];
    int indiceEncontrarEquipo;

    mostrarEquipos(equipos, cantidad);

    auxCodigo = validarStringNumerico(auxCodigo, "\nIngrese el CODIGO del equipo a modificar: ", auxCodigoStr);
    indiceEncontrarEquipo = encontrarEquipo(equipos, cantidad, auxCodigo);
    validarStringNumerico(menuModificar, "Que desea modificar?\n 1 - NOMBRE\n 2 - LOCALIDAD\n", menuModificarStr);
    menuModificar = validarMenu(menuModificar, 1, 2, "REINGRESE LA OPCION\n 1 - NOMBRE\n 2 - LOCALIDAD\n", menuModificarStr);

    switch(menuModificar)
    {
    case 1:
        validarStringLetras("Ingrese el nuevo nombre: ", auxNombre);
        strcpy(equipos[indiceEncontrarEquipo].nombre, auxNombre);
        mostrarEquipos(equipos, cantidad);
        break;
    case 2:
        validarStringLetras("Ingrese la nueva localidad: ", auxLocalidad);
        strcpy(equipos[indiceEncontrarEquipo].localidad, auxLocalidad);
        mostrarEquipos(equipos, cantidad);
        break;
    }
}

int encontrarEquipo(eEquipos equipos[], int cantidad, int valor)
{
    for(int i=0; i<cantidad; i++)
    {
        if (equipos[i].codigoEquipo==valor)
            return i;
    }
    return -1;
}

void eliminarEquipo(eEquipos equipos[], int cantidad)
{
    int auxCodigo;
    char auxCodigoStr[256];
    int indiceEncontrarEquipo;
    mostrarEquipos(equipos, cantidad);
    auxCodigo = validarStringNumerico(auxCodigo, "\n\nIngrese el CODIGO del equipo a eliminar:", auxCodigoStr);
    indiceEncontrarEquipo = encontrarEquipo(equipos, cantidad, auxCodigo);
    equipos[indiceEncontrarEquipo].codigoEquipo = -1;
    mostrarEquipos(equipos, cantidad);

}
