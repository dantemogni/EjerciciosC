#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
void menu(ePropietario propietarios[], eVehiculo vehiculos[], int cantidad)
{
    int opciones;
    do
    {
        printf("\n****ESTACIONAMIENTO****\n");
        printf("\n1 - INGRESO PERSONAS\n2 - ELIMINAR PERSONAS\n3 - MODIFICAR PERSONAS\n4 - INGRESAR VEHICULO\n5 - EGRESO VEHICULO\n\n");
        scanf("%d", &opciones);
        switch(opciones)
        {
        case 1:
            system("cls");
            printf("\nINGRESO PERSONAS\n");
            cargaPropietarios(propietarios, cantidad);
            mostrarPropietarios(propietarios, cantidad);
            break;
        case 2:
            system("cls");
            printf("\nELIMINAR PERSONAS\n");
            eliminarPersonas(propietarios, cantidad);
            mostrarPropietarios(propietarios, cantidad);
            break;
        case 3:
            system("cls");
            printf("\nMODIFICAR PERSONAS\n");
            modificarPropietario(propietarios, cantidad);
            mostrarPropietarios(propietarios, cantidad);
            break;
        case 4:
            system("cls");
            printf("\nINGRESAR VEHICULO\n");
            ingresoVehiculo(vehiculos, cantidad);
            mostrarVehiculos(vehiculos, cantidad);
            break;
        case 5:
            system("cls");
            printf("\nEGRESO VEHICULO\n");
            egresoVehiculo(vehiculos, cantidad);
            break;
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }
    while(opciones!=-1);
    //FALTA INICIALIZAR EN -1 PARA MOSTRAR QUE ESTAN VACIOS
}

void cargaPropietarios(ePropietario propietarios[], int cantidad)
{
    int i;
    char hardNombres [][20] = {"Dante", "Juan", "Maria"};
    int hardDia[] = {01,17,26};
    int hardMes[] = {02,06,10};
    int hardAnio = 2019;

    printf("// Ingresar un propietario: ...\n");
    //scanf
    printf("// Ingresar fecha de nacimiento: ...\n\n");
    //scanf

    for(i=0; i<cantidad; i++)
    {
        propietarios[i].fechaNacimiento.dia = hardDia[i];
        propietarios[i].fechaNacimiento.mes = hardMes[i];
        propietarios[i].fechaNacimiento.anio = hardAnio;
        strcpy(propietarios[i].nombre,hardNombres[i]);
        propietarios[i].idPropietario = i+1;
    }
}
void mostrarPropietarios(ePropietario propietarios[], int cantidad)
{
    int i;
    printf("\nID\tNOMBRE\tF. DE NACIMIENTO\n");
    for(i=0; i<cantidad; i++)
    {
        if(propietarios[i].idPropietario!=-1)
        {
            printf("%d\t%s\t%d/%d/%d\n",
                   propietarios[i].idPropietario,
                   propietarios[i].nombre,
                   propietarios[i].fechaNacimiento.dia,
                   propietarios[i].fechaNacimiento.mes,
                   propietarios[i].fechaNacimiento.anio);
        }
    }
}

void modificarPropietario(ePropietario propietarios[], int cantidad)
{
    int auxID; // VER DE MODIFICAR PARA QUE SEA MAS ACERTADO
    char auxNombre[10];
    int auxDia;
    int auxMes;
    int auxAnio;
    int menuModificar;
    mostrarPropietarios(propietarios, cantidad);
    printf("\nIngrese el ID del propietario a modificar: ");
    scanf("%d", &auxID);
    auxID = auxID - 1;
    printf("Que desea modificar?\n 1 - NOMBRE\n 2 - FECHA DE NACIMIENTO\n");
    scanf("%d", &menuModificar);
    switch(menuModificar)
    {
    case 1:
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(auxNombre);
        strcpy(propietarios[auxID].nombre, auxNombre);
        break;
    case 2:
        printf("Ingrese el dia: ");
        fflush(stdin);
        scanf("%d", &auxDia);
        printf("Ingrese el mes: ");
        fflush(stdin);
        scanf("%d", &auxMes);
        printf("Ingrese el anio: ");
        fflush(stdin);
        scanf("%d", &auxAnio);
        propietarios[auxID].fechaNacimiento.anio = auxAnio;
        propietarios[auxID].fechaNacimiento.mes = auxMes;
        propietarios[auxID].fechaNacimiento.dia = auxDia;
        break;
    }
}
void eliminarPersonas(ePropietario propietarios[], int cantidad)
{
    int auxID;
    mostrarPropietarios(propietarios, cantidad);
    printf("\n\nIngrese el ID del propietario a eliminar: ");
    scanf("%d", &auxID);
    auxID = auxID - 1; // LO MISMO QUE EN MODIFICAR PERSONAS
    propietarios[auxID].idPropietario = -1;
}
void ingresoVehiculo(eVehiculo vehiculos[], int cantidad)
{
    int i;
    char hardPatente [][10] = {"AAA111", "BBB222", "CCC333"};
    int hardDia[] = {15,6,20};
    int hardMes[] = {3,8,11};
    int hardAnio = 2019;
    int hardHoraIngreso[] = {10,11,15};
    int hardId[] = {1,2,2};
    int hardHoraSalida = {0};
    //int indice;

    printf("// Ingresar una patente: ...\n");
    //scanf
    printf("// Ingresar fecha de entrada: ...\n");
    //scanf
    printf("// Ingresar hora de entrada: ...\n");
    //scanf
    printf("// Ingresar ID del propietario: ...\n");
    //fflush(stdin);
    //scanf("%d", &indice);

    for(i=0; i<cantidad; i++)
    {
        vehiculos[i].fechaIngreso.dia = hardDia[i];
        vehiculos[i].fechaIngreso.mes = hardMes[i];
        vehiculos[i].fechaIngreso.anio = hardAnio;
        vehiculos[i].horaEntrada = hardHoraIngreso[i];
        vehiculos[i].idPropietario.idPropietario = hardId[i];
        strcpy(vehiculos[i].patente,hardPatente[i]);
        vehiculos[i].horaSalida = hardHoraSalida;
    }

}

void egresoVehiculo(eVehiculo vehiculos[], int cantidad)
{
    int i;
    int auxHoraSalida[cantidad];
    char auxPatente[cantidad][10];
    int encontrar;

    printf("// Ingresar una patente: ...\n");
    fflush(stdin);
    gets(auxPatente);


     if(encontrarVehiculo(vehiculos, cantidad, auxPatente) == -1)
        {
            printf("\nERROR\n");
        }  else  {
        printf("// Ingresar hora de salida: ...\n");
        scanf("%d", &auxHoraSalida);
        for(i=0; i<cantidad; i++)
        {
           vehiculos[i].horaSalida = auxHoraSalida[i];
        }
        mostrarVehiculos(vehiculos, cantidad);
    }
}

int encontrarVehiculo(eVehiculo vehiculos[], int cantidad, int valor)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(strcmp(vehiculos[i].patente, valor)==0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
}

void mostrarVehiculos(eVehiculo vehiculos[], int cantidad)
{
    int i;
    printf("\nID\tPATENTE\tF. DE ENTRADA\tH. DE ENTRADA\tH. SALIDA\n");
    for(i=0; i<cantidad; i++)
    {
        printf("%d\t%s\t%d/%d/%d\t%d\t\t%d\n",
               vehiculos[i].idPropietario.idPropietario,
               vehiculos[i].patente,
               vehiculos[i].fechaIngreso.dia,
               vehiculos[i].fechaIngreso.mes,
               vehiculos[i].fechaIngreso.anio,
               vehiculos[i].horaEntrada,
               vehiculos[i].horaSalida);
    }
}

