#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "entidadEquipos.h"
#include "EntidadJugadores.h"
#include "entidadReferis.h"
#include "entidadPartidos.h"


void subMenuListar(eEquipos equipos[], eJugadores jugadores[], eReferi referis[], ePartido partidos[], int cantidad)
{
    int opciones;
    char opcionesStr[251];
    do
    {
        printf("\n***LISTAR E INFORMAR***\n\n");
        printf("1 - LISTAR JUGADORES POR EQUIPO\n2 - INFORMAR EL REFERI QUE MAS PARTIDOS DIRIGIO\n3 - INGRESAR UN NOMBRE Y LISTAR\n4 - LISTAR EL EQUIPO CON EL NOMBRE MAS LARGO\n5 - INGRESAR UNA FECHA Y LISTAR\n6 - VOLVER AL MENU PRINCIPAL\n");
        validarStringNumerico(opciones, "\nQue desea hacer? ",opcionesStr);
        opciones = validarMenu(opciones, 1, 6, "\nREINGRESE LA OPCION\n1 - LISTAR JUGADORES POR EQUIPO\n2 - INFORMAR EL REFERI QUE MAS PARTIDOS DIRIGIO\n3 - INGRESAR UN NOMBRE Y LISTAR\n4 - LISTAR EL EQUIPO CON EL NOMBRE MAS LARGO\n5 - INGRESAR UNA FECHA Y LISTAR\n6 - VOLVER AL MENU PRINCIPAL\n", opcionesStr);
        switch(opciones)
        {
        case 1:
            system("cls");
            listarJugadoresPorEquipo(equipos, jugadores, cantidad);
            break;
        case 2:
            system("cls");
            informarReferi(referis, partidos, cantidad);
            break;
        case 3:
            system("cls");
            ingresarNombre(jugadores, equipos, cantidad);
            break;
        case 4:
            equipoLargo(equipos,cantidad);
            break;
        case 5:
            ingresarFecha(partidos,equipos,referis,cantidad);
            break;
        case 6:
            break;
        default:
            printf("ERROR!!! Opcion Invalida");
            break;
        }
    }
    while(opciones > 0 && opciones < 5);
}
void listarJugadoresPorEquipo(eEquipos equipos[], eJugadores jugadores[], int cantidad)
{
    int noHayJugadores;
    int indiceEquipo;
    int indiceJugador;
    for(indiceEquipo=0; indiceEquipo<cantidad; indiceEquipo++)
    {
        noHayJugadores = 1;
        printf("Equipo: %s:", equipos[indiceEquipo].nombre);
        for(indiceJugador=0; indiceJugador<cantidad; indiceJugador++)
        {
            if (jugadores[indiceJugador].codigoEquipo == equipos[indiceEquipo].codigoEquipo)
            {
                printf("\tJugador: %s %s\n", jugadores[indiceJugador].nombreJugador,jugadores[indiceJugador].apellidoJugador);
                noHayJugadores = 0;
            }
        }
        if (noHayJugadores) // 1 = true, no hace falta escribirlo
        {
            printf("\t[No se encontraron jugadores.]");
        }
        printf("\n");
    }
}
void informarReferi(eReferi referis[], ePartido partidos[], int cantidad)
{
    int indiceReferi;
    int indicePartido;
    char nombreReferiMax[31];
    char apellidoReferiMax[31];
    int cantidadPartidosMax=0;
    int cantidadPartidos;
    for(indiceReferi=0; indiceReferi<cantidad; indiceReferi++)
    {
        cantidadPartidos = 0;
        for(indicePartido=0; indicePartido<cantidad; indicePartido++)
        {
            if(partidos[indicePartido].codigoReferi==referis[indiceReferi].codigoReferi)
            {
                cantidadPartidos++;
            }
        }
        if (cantidadPartidos > cantidadPartidosMax)
        {
            cantidadPartidosMax = cantidadPartidos;
            strcpy(nombreReferiMax, referis[indiceReferi].nombreReferi);
            strcpy(apellidoReferiMax, referis[indiceReferi].apellidoReferi);
        }
    }
    printf("\nReferi con mas partidos (%d):\n\t%s %s\n",
           cantidadPartidosMax,
           nombreReferiMax,
           apellidoReferiMax);
}

void ingresarNombre(eJugadores jugadores[], eEquipos equipos[], int cantidad)
{
    char auxNombre[51];
    int indiceEquipo;
    int indiceJugadores;

    validarStringLetras("Ingrese el nombre del jugador: ", auxNombre);
    printf("\n");
    for(indiceJugadores=0; indiceJugadores<cantidad; indiceJugadores++)
    {
        if(strcmp(jugadores[indiceJugadores].nombreJugador, auxNombre) == 0)
        {
            printf("Jugador: %s %s", jugadores[indiceJugadores].nombreJugador,
                   jugadores[indiceJugadores].apellidoJugador);
            for(indiceEquipo=0; indiceEquipo<cantidad; indiceEquipo++)
            {
                if(equipos[indiceEquipo].codigoEquipo==jugadores[indiceJugadores].codigoEquipo)
                {
                    printf("\tEquipo: %s\n", equipos[indiceEquipo].nombre);
                }
            }
        }
    }
}

void equipoLargo(eEquipos equipos[],int cantidad)
{
    char aux[256];
    int i;
    int j;

    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(strlen(equipos[i].nombre)>strlen(equipos[j].nombre))
            {
                strcpy(aux, equipos[i].nombre);
                strcpy(equipos[i].nombre, equipos[j].nombre);
                strcpy(equipos[j].nombre,aux);
            }
        }
    }
    printf("\nEl equipo con el nombre mas largo es: %s", equipos[i].nombre);
}

void ingresarFecha(ePartido partidos[], eEquipos equipos[], eReferi referis[], int cantidad)
{
    int auxDia;
    int auxMes;
    int auxAnio;
    char auxDiaStr[256];
    char auxMesStr[256];
    char auxAnioStr[256];
    int i;
    int j;
    int k;

    auxDia = validarStringNumerico(auxDia,"Ingrese el dia ", auxDiaStr);
    auxMes = validarStringNumerico(auxMes,"Ingrese el mes ", auxMesStr);
    auxAnio = validarStringNumerico(auxAnio,"Ingrese el anio ", auxAnioStr);

    printf("\n");
    for(i=0; i<cantidad; i++)
    {
        if((partidos[i].fechaPartido.dia==auxDia)&&(partidos[i].fechaPartido.mes==auxMes)&&(partidos[i].fechaPartido.anio==auxAnio))
        {
            for(k=0; k<cantidad; k++)
            {
                if(partidos[k].codigoLocal==equipos[i].codigoEquipo || partidos[k].codigoVisitante==equipos[i].codigoEquipo)
                {
                    printf("Equipo: %s", equipos[k].nombre);
                for(int j=0; j<cantidad; j++)
                {
                    if(partidos[j].codigoReferi==referis[k].codigoReferi)
                    {
                        printf("\tReferi: %s\n", referis[k].nombreReferi);
                    }
                }
                }
            }
        }
    }
}
