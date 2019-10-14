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
        printf("\n1 - INGRESO PERSONAS\n2 - ELIMINAR PERSONAS\n3 - MODIFICAR PERSONAS\n4 - INGRESAR VEHICULO\n5 - EGRESO VEHICULO\n6 - INFORMAR\n\n");
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
        case 6:
            system("cls");
            printf("\nINFORMAR\n");
            informar(propietarios, vehiculos, cantidad);
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
    char hardNombres [][10] = {"Maria", "Juan", "Dante"};
    int hardDia[] = {31,17,26};
    int hardMes[] = {03,01,10};
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
    int auxID;
    char auxNombre[10];
    int auxDia;
    int auxMes;
    int auxAnio;
    int menuModificar;
    int indiceEncontrarPropietario;

    mostrarPropietarios(propietarios, cantidad);
    printf("\nIngrese el ID del propietario a modificar: ");
    scanf("%d", &auxID);

    indiceEncontrarPropietario = encontrarPropietario(propietarios, cantidad, auxID);

    //auxID = auxID - 1;
    printf("Que desea modificar?\n 1 - NOMBRE\n 2 - FECHA DE NACIMIENTO\n");
    scanf("%d", &menuModificar);
    switch(menuModificar)
    {
    case 1:
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(auxNombre);
        strcpy(propietarios[indiceEncontrarPropietario].nombre, auxNombre);
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
        propietarios[indiceEncontrarPropietario].fechaNacimiento.anio = auxAnio;
        propietarios[indiceEncontrarPropietario].fechaNacimiento.mes = auxMes;
        propietarios[indiceEncontrarPropietario].fechaNacimiento.dia = auxDia;
        break;
    }
}

int encontrarPropietario(ePropietario propietarios[], int cantidad, int valor)
{
    for(int i=0; i<cantidad; i++)
    {
        if (propietarios[i].idPropietario==valor)
            return i;
    }
    return -1;
}


void eliminarPersonas(ePropietario propietarios[], int cantidad)
{
    int auxID;
    int indiceEncontrarPropietario;
    mostrarPropietarios(propietarios, cantidad);
    printf("\n\nIngrese el ID del propietario a eliminar: ");
    scanf("%d", &auxID);
    indiceEncontrarPropietario = encontrarPropietario(propietarios, cantidad, auxID);
    propietarios[indiceEncontrarPropietario].idPropietario = -1;
}
void ingresoVehiculo(eVehiculo vehiculos[], int cantidad)
{
    int i;
    char hardPatente [][10] = {"BBB222", "AAA111", "CCC333"};
    int hardDia[] = {15,6,20};
    int hardMes[] = {3,8,11};
    int hardAnio = 2019;
    int hardHoraIngreso[] = {10,11,15};
    int hardId[] = {1,2,2};
    int hardHoraSalida = {0};

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
        vehiculos[i].idPropietario.idPropietario = hardId[i]; /* PENSAR MEJOR ESTO, DEBE ESTAR MAL */
        strcpy(vehiculos[i].patente,hardPatente[i]);
        vehiculos[i].horaSalida = hardHoraSalida;
    }

}

void egresoVehiculo(eVehiculo vehiculos[], int cantidad)
{
    int auxHoraSalida;
    char auxPatente[10];

    printf("// Ingresar una patente: ...\n");
    fflush(stdin);
    scanf("%s", auxPatente);
    int indiceVehiculoEncontrado = encontrarVehiculo(vehiculos, cantidad, auxPatente);

     if(indiceVehiculoEncontrado == -1)
        {
            printf("\nERROR\n");
        }  else  {
        printf("// Ingresar hora de salida: ...\n");
        scanf("%d", &auxHoraSalida);
        vehiculos[indiceVehiculoEncontrado].horaSalida = auxHoraSalida; // indiceVehiculoEncontrado es el i del vehiculo encontrado
        mostrarVehiculos(vehiculos, cantidad);
    }
}

int encontrarVehiculo(eVehiculo vehiculos[], int cantidad, char valor[10])
{
    for(int i=0; i<cantidad; i++)
    {
        if (strcmp(vehiculos[i].patente, valor)==0)
            return i; // devuelve el valor de i en donde se encontró
    }
    return -1;
}

void mostrarVehiculos(eVehiculo vehiculos[], int cantidad)
{
    printf("\nID\tPATENTE\tF. DE ENTRADA\tH. DE ENTRADA\tH. SALIDA\n"); /* QUE MUESTRE EL DUENIO DEL AUTO !! */
    for(int i=0; i<cantidad; i++)
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
void informar(ePropietario propietarios[], eVehiculo vehiculos[], int cantidad)
{
    int opcion;
    printf("\n1 - Todos las propietarios ordenados por nombre y anio de nacimiento.\n");
    printf("2 - Todos los vehiculos ordenados por duenio y patente.\n");
    printf("3 - Cada auto con el nombre de su duenio.\n");
    printf("4 - Por cada duenio los autos que tiene estacionados.\n");
    printf("5 - Ingresar un duenio y mostrar todos sus autos.\n");
    printf("6 - Mostrar el total de la estadia de cada auto, sabiendo que el valor hora es $100.\n");
    printf("7 - Mostrar cuanto debera pagar cada duenio por todos sus autos estacionados.\n");
    printf("8 - Mostrar el/los duenios con mas autos estacionados.\n\n");
    scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:
        ordenarPropietarios(propietarios, cantidad);
        mostrarPropietarios(propietarios, cantidad);
        break;
    case 2:
        ordenarVehiculos(vehiculos, cantidad);
        mostrarVehiculos(vehiculos, cantidad);
        break;
    case 6:
        valorEstadia(vehiculos,cantidad);
        break;
    }
}

void ordenarPropietarios(ePropietario propietarios[], int cantidad)
{
    int i;
    int j;
    char auxNombre[10];
    int auxID;
    int auxAnio;
    int auxDia;
    int auxMes;
    //int indiceAuxNombre;

    //for (indiceAuxNombre=0; indiceAuxNombre<cantidad; indiceAuxNombre++) {
    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if((propietarios[i].nombre>propietarios[j].nombre)|| // NO ORDENA POR NOMBRE
               (propietarios[i].fechaNacimiento.anio>propietarios[j].fechaNacimiento.anio)||
               (propietarios[i].fechaNacimiento.mes>propietarios[j].fechaNacimiento.mes)||
               (propietarios[i].fechaNacimiento.dia>propietarios[j].fechaNacimiento.dia))
            {
                auxID = propietarios[i].idPropietario;
                propietarios[i].idPropietario = propietarios[j].idPropietario;
                propietarios[j].idPropietario = auxID;

                auxAnio = propietarios[i].fechaNacimiento.anio;
                propietarios[i].fechaNacimiento.anio = propietarios[j].fechaNacimiento.anio;
                propietarios[j].fechaNacimiento.anio = auxAnio;

                auxDia = propietarios[i].fechaNacimiento.dia;
                propietarios[i].fechaNacimiento.dia = propietarios[j].fechaNacimiento.dia;
                propietarios[j].fechaNacimiento.dia = auxDia;

                auxMes = propietarios[i].fechaNacimiento.mes;
                propietarios[i].fechaNacimiento.mes = propietarios[j].fechaNacimiento.mes;
                propietarios[j].fechaNacimiento.mes = auxMes;

                strcpy(auxNombre, propietarios[i].nombre);
                strcpy(propietarios[i].nombre, propietarios[j].nombre);
                strcpy(propietarios[j].nombre, auxNombre);
            }
        }
    }
    //}
}

void ordenarVehiculos(eVehiculo vehiculos[],int cantidad) /* NO ORDENADO POR DUENIO !!!!! */
{
    int i;
    int j;
    char auxPatente[cantidad][10]; //los auxiliares son temporales para guardar el dato que se esta moviendo
    int auxID;
    int auxAnio;
    int auxDia;
    int auxMes;
    int auxHoraEntrada;
    int auxHoraSalida;

    for(i=0;i<cantidad-1;i++) // cantidad-1 porque cuando se ordenan, el ultimo ya queda ordenado de por si junto con el ordenamiento gral.
    {
        for(j=i+1;j<cantidad;j++)
        {
            if(vehiculos[i].patente>vehiculos[j].patente) // si no se cumple el if, pasa de nuevo a la interacion del FOR
            {
                auxID = vehiculos[i].idPropietario.idPropietario;
                vehiculos[i].idPropietario.idPropietario = vehiculos[j].idPropietario.idPropietario;
                vehiculos[j].idPropietario.idPropietario = auxID;

                auxAnio = vehiculos[i].fechaIngreso.anio;
                vehiculos[i].fechaIngreso.anio = vehiculos[j].fechaIngreso.anio;
                vehiculos[j].fechaIngreso.anio = auxAnio;

                auxDia = vehiculos[i].fechaIngreso.dia;
                vehiculos[i].fechaIngreso.dia = vehiculos[j].fechaIngreso.dia;
                vehiculos[j].fechaIngreso.dia = auxDia;

                auxMes = vehiculos[i].fechaIngreso.mes;
                vehiculos[i].fechaIngreso.mes = vehiculos[j].fechaIngreso.mes;
                vehiculos[j].fechaIngreso.mes = auxMes;

                strcpy(auxPatente, vehiculos[i].patente);
                strcpy(vehiculos[i].patente, vehiculos[j].patente);
                strcpy(vehiculos[j].patente, auxPatente);
            }
        }
    }
}
int diferencia(eVehiculo vehiculos[], int cantidad)
{
    int i;
    int resultado;
    for(i=0;i<cantidad;i++)
    {
        resultado = vehiculos[i].horaSalida - vehiculos[i].horaEntrada;
    }
    return resultado;
}

void valorEstadia(eVehiculo vehiculos[], int cantidad)
{
    int i;
    mostrarVehiculos(vehiculos, cantidad);
    for(i=0; i<cantidad; i++)
    {
        printf("\n%s: %d", vehiculos[i].patente, diferencia(vehiculos, cantidad));
    }
}
