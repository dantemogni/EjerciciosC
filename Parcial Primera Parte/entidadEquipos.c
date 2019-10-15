#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "entidadEquipos.h"
#include <string.h>

void subMenuEquipo(eEquipos equipos[], int cantidad)
{
    int opciones;
    printf("\n***EQUIPOS***\n\n");
    printf("1 - Ingresar nuevo equipo\n2 - Listar alfabeticamente los equipos\n3 - Modificar Equipo\n4 - Eliminar Equipo\n\n");
    printf("Que desea hacer? ");
    scanf("%d",&opciones);
    switch(opciones)
    {
    case 1:
        cargaEquipos(equipos, cantidad);
        mostrarEquipos(equipos, cantidad);
        break;
    case 2:
        listarAlfabeticamenteEquipos(equipos,cantidad);
        mostrarEquipos(equipos, cantidad);
        break;
    case 3:
        modificarEquipo(equipos, cantidad);
        mostrarEquipos(equipos, cantidad);
        break;
    case 4:
        eliminarEquipo(equipos, cantidad);
        mostrarEquipos(equipos, cantidad);
    }
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

    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
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

}

void modificarEquipo(eEquipos equipos[], int cantidad)
{
    int auxCodigo;
    char auxNombre[51];
    char auxLocalidad[33];
    int menuModificar;
    int indiceEncontrarEquipo;

    mostrarEquipos(equipos, cantidad);
    printf("\nIngrese el CODIGO del equipo a modificar: ");
    scanf("%d", &auxCodigo);

    indiceEncontrarEquipo = encontrarEquipo(equipos, cantidad, auxCodigo);

    printf("Que desea modificar?\n 1 - NOMBRE\n 2 - LOCALIDAD\n");
    scanf("%d", &menuModificar);
    switch(menuModificar)
    {
    case 1:
        printf("Ingrese el nuevo nombre: ");
        fflush(stdin);
        gets(auxNombre);
        strcpy(equipos[indiceEncontrarEquipo].nombre, auxNombre);
        break;
    case 2:
        printf("Ingrese la nueva localidad: ");
        fflush(stdin);
        gets(auxLocalidad);
        strcpy(equipos[indiceEncontrarEquipo].localidad, auxLocalidad);
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
    int indiceEncontrarEquipo;
    mostrarEquipos(equipos, cantidad);
    printf("\n\nIngrese el CODIGO del equipo a eliminar: ");
    scanf("%d", &auxCodigo);
    indiceEncontrarEquipo = encontrarEquipo(equipos, cantidad, auxCodigo);
    equipos[indiceEncontrarEquipo].codigoEquipo = -1;
}
