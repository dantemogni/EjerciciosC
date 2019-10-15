#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "entidadEquipos.h"
#include "EntidadJugadores.h"
#include "entidadReferis.h"
#include "entidadPartidos.h"
#include <string.h>

void subMenuListar(eEquipos[], eJugadores[], eReferi[], ePartido[], int);
void listarJugadoresPorEquipo(eEquipos[], eJugadores[], int);
void informarReferi(eReferi[], ePartido[], int);
void ingresarNombre(eJugadores[], eEquipos[], int);
int encontrarNombre(eJugadores[], int, char[]);



void menuEntidades(eEquipos equipos[], eJugadores jugadores[], eReferi referis[], ePartido partidos[], int cantidad)
{
    int opciones;
    do
    {
        printf("\n****BIENVENIDOS****\n");
        printf("\n1 - EQUIPOS\n2 - JUGADOERS\n3 - REFERIS\n4 - PARTIDO\n5 - LISTAR E INFORMAR\n\n");
        scanf("%d", &opciones);
        switch(opciones)
        {
        case 1:
            system("cls");
            subMenuEquipo(equipos, cantidad);
            break;
        case 2:
            system("cls");
            subMenuJugadores(jugadores, cantidad);
            break;
        case 3:
            system("cls");
            subMenuReferis(referis, cantidad);
            break;
        case 4:
            system("cls");
            subMenuPartidos(partidos, cantidad);
            break;
        case 5:
            system("cls");
            subMenuListar(equipos, jugadores, referis, partidos, cantidad);
            break;
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }
    while(opciones!=-1);
    //FALTA INICIALIZAR EN -1 PARA MOSTRAR QUE ESTAN VACIOS
}

void subMenuListar(eEquipos equipos[], eJugadores jugadores[], eReferi referis[], ePartido partidos[], int cantidad)
{
    int opciones;
    printf("\n***LISTAR E INFORMAR***\n");
    printf("1 - LISTAR JUGADORES POR EQUIPO\n2 - INFORMAR EL REFERI QUE MAS PARTIDOS DIRIGIO\n3 - INGRESAR UN NOMBRE Y LISTAR\n");
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
    case 3:
        ingresarNombre(jugadores, equipos, cantidad);
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
void ingresarNombre(eJugadores jugadores[], eEquipos equipos[], int cantidad)
{
    char auxNombre[51];
    printf("Ingrese el nombre del jugador: ");
    fflush(stdin);
    gets(auxNombre);
    int indiceEquipo;
    int indiceJugadores;

    int indiceEncontrarNombre = encontrarNombre(jugadores, cantidad, auxNombre); // TIENE QUE BUSCAR MÁS DE UNA COINDICENCIA


    for(indiceJugadores=0; indiceJugadores<cantidad; indiceJugadores++)
    {
        printf("Jugador: %s %s", jugadores[indiceEncontrarNombre].nombreJugador,
                                 jugadores[indiceEncontrarNombre].apellidoJugador);

        for(indiceEquipo=0; indiceEquipo<cantidad; indiceEquipo++) // ME REPITE LOS EQUIPOS 5 VECES --> MAL
        {
           if(jugadores[indiceEncontrarNombre].codigoEquipo == equipos[indiceEquipo].codigoEquipo)
           printf("\tEquipo: %s\n", equipos[indiceEquipo].nombre);
        }
    }
}

int encontrarNombre(eJugadores jugadores[], int cantidad, char valor[])
{
    for(int i=0; i<cantidad; i++)
    {
        if (strcmp(jugadores[i].nombreJugador, valor)== 0)
            return i;
    }
    return -1;
}
