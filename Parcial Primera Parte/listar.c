#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "entidadEquipos.h"
#include "entidadPartidos.h"
#include "entidadReferis.h"
#include "EntidadJugadores.h"
#include "listar.h"
#include <string.h>

void subMenuListar(eEquipos equipos[], eJugadores jugadores[], eReferi referis[], ePartido partidos[], int cantidad)
{
    int opciones;
    printf("\n***LISTAR E INFORMAR***\n");
    printf("1 - LISTAR JUGADORES POR EQUIPO\n2 - INFORMAR EL REFERI QUE MAS PARTIDOS DIRIGIO\n");
    printf("Que desea hacer? ");
    scanf("%d", &opciones);
    switch(opciones)
    {
    case 1:
        listarJugadoresPorEquipo(equipos, jugadores, cantidad);
        break;
    case 2:
        informarReferi(referis, partidos, cantidad);
        break;
    }

}
void listarJugadoresPorEquipo(eEquipos equipos[], eJugadores jugadores[], int cantidad)
{
    int noHayJugadores;
    int indiceEquipo;
    int indiceJugador;
    for(indiceEquipo=0; indiceEquipo<cantidad; indiceEquipo++)
    {
        noHayJugadores = 1;
        printf("%s:\n", equipos[indiceEquipo].nombre);
        for(indiceJugador=0; indiceJugador<cantidad; indiceJugador++)
        {
            if (jugadores[indiceJugador].codigoEquipo == equipos[indiceEquipo].codigoEquipo)
            {
                printf("\t> %s\n", jugadores[indiceJugador].nombreJugador);
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

