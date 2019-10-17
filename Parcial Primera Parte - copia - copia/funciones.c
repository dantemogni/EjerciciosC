#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "entidadEquipos.h"
#include "EntidadJugadores.h"
#include "entidadReferis.h"
#include "entidadPartidos.h"
#include "validaciones.h"

void menuEntidades(eEquipos[], eJugadores[], eReferi[], ePartido[], int);
void inicializarArrays(eEquipos[], eJugadores[], eReferi[], ePartido[], int, int);


void inicializarArrays(eEquipos equipos[], eJugadores jugadores[], eReferi referi[], ePartido partido[], int cantidad, int valor)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        equipos[i].codigoEquipo=valor;
        jugadores[i].codigoJugador=valor;
        referi[i].codigoReferi=valor;
        partido[i].codigoPartido=valor;
      }
}
void menuEntidades(eEquipos equipos[], eJugadores jugadores[], eReferi referis[], ePartido partidos[], int cantidad)
{
    int opciones;
    char opcionesStr[256];
    do
    {
        printf("\n****BIENVENIDOS****\n");
        validarStringNumerico(opciones,"\n1 - EQUIPOS\n2 - JUGADORES\n3 - REFERIS\n4 - PARTIDO\n5 - LISTAR E INFORMAR\n6 - SALIR\n\n", opcionesStr);
        opciones = validarMenu(opciones, 1, 6, "\nREINGRESE LA OPCION\n1 - EQUIPOS\n2 - JUGADOERS\n3 - REFERIS\n4 - PARTIDO\n5 - LISTAR E INFORMAR\n6 - SALIR\n\n", opcionesStr);

        switch(opciones)
        {
        case 1:
            system("cls");
            subMenuEquipo(equipos, cantidad);
            printf("\n\n");
            system("pause");
            system("cls");

            break;
        case 2:
            system("cls");
            subMenuJugadores(jugadores, cantidad);
            printf("\n\n");
            system("pause");
            system("cls");

            break;
        case 3:
            system("cls");
            subMenuReferis(referis, cantidad);
            printf("\n\n");
            system("pause");
            system("cls");

            break;
        case 4:
            system("cls");
            subMenuPartidos(partidos, cantidad);
            printf("\n\n");
            system("pause");
            system("cls");

            break;
        case 5:
           if((jugadores[0].codigoJugador==-1)&&(partidos[0].codigoPartido==-1)&&(referis[0].codigoReferi==-1)&&(equipos[0].codigoEquipo==-1))
            {
                printf("\nERROR. Primero debe ingresar un dato\n");
                break;
            }
            system("cls");
            subMenuListar(equipos, jugadores, referis, partidos, cantidad);
            printf("\n\n");
            system("pause");
            system("cls");
            break;
        case 6:
            break;
        default:
            printf("\nERROR!!. Opcion Invalida\n");
            break;
        }
    }
    while(opciones>=1&&opciones<=5);
}
