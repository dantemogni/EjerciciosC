#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "entidadEquipos.h"
#include "EntidadJugadores.h"
#include "entidadReferis.h"
#include "entidadPartidos.h"
#define CANTIDAD_DATOS 5

void menuEntidades(eEquipos[], eJugadores[], eReferi[], ePartido[], int);


int main()
{
    eEquipos equipos[CANTIDAD_DATOS];
    eJugadores jugadores[CANTIDAD_DATOS];
    eReferi referis[CANTIDAD_DATOS];
    ePartido partidos[CANTIDAD_DATOS];
    menuEntidades(equipos, jugadores, referis, partidos, CANTIDAD_DATOS);
    return 0;
}

