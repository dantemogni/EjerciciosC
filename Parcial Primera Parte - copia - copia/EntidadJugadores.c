#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "EntidadJugadores.h"
#include "validaciones.h"


void subMenuJugadores(eJugadores jugadores[], int cantidad)
{
    int opciones;
    char opcionesStr[256];
    do{
    printf("\n***JUGADORES***\n\n");
    printf("1 - Ingresar nuevo jugador\n2 - Listar alfabeticamente los jugadores\n3 - Eliminar jugador\n\n");
    validarStringNumerico(opciones,"Que desea hacer? ", opcionesStr);
    opciones = validarMenu(opciones,1,3, "REINGRESE LA OPCION.\n1 - Ingresar nuevo jugador\n2 - Listar alfabeticamente los jugadores\n3 - Eliminar jugador\n\n", opcionesStr);
    switch(opciones)
    {
    case 1:
        cargaJugadores(jugadores, cantidad);
        mostrarJugadores(jugadores, cantidad);
        break;
    case 2:
        if(jugadores[0].codigoJugador==-1)
        {
            printf("\nERROR. Primero debe ingresar un jugador\n");
            break;
        }
        listarAlfabeticamenteJugadores(jugadores,cantidad);
        mostrarJugadores(jugadores, cantidad);
        break;
    case 3:
        if(jugadores[0].codigoJugador==-1)
        {
            printf("\nERROR. Primero debe ingresar un jugador\n");
            break;
        }
        eliminarJugadores(jugadores, cantidad);
        mostrarJugadores(jugadores, cantidad);
    }
    }while(opciones > 0 && opciones <= 3);
}

void cargaJugadores(eJugadores jugadores[], int cantidad)
{
    int i;
    char hardNombres [][51] = {"Mauricio", "Juan", "Juan", "Juan", "Alejo"};
    char hardApellido [][51] = {"Oca", "Valle", "Gomez", "Lopez", "Valle"};
    char hardSexo = 'm';
    int hardCodigoEquipo [] = {2,4,3,1,2};

    printf("\n// Ingresar el nombre del jugador: ...\n");
    //scanf
    printf("// Ingresar el apellido del jugador: ...\n");
    //scanf
    printf("// Ingresar el sexo del jugador: ...\n\n");
    //scanf

    for(i=0; i<cantidad; i++)
    {
        strcpy(jugadores[i].nombreJugador,hardNombres[i]);
        strcpy(jugadores[i].apellidoJugador,hardApellido[i]);
        jugadores[i].sexo = hardSexo;
        jugadores[i].codigoJugador = i+1;
        jugadores[i].codigoEquipo = hardCodigoEquipo[i];
    }
}

void mostrarJugadores(eJugadores jugadores[], int cantidad)
{
    int i;
    printf("\n\tCODIGO\t\tAPELLIDO\tNOMBRE\t\tSEXO\n");
    for(i=0; i<cantidad; i++)
    {
        if(jugadores[i].codigoJugador!=-1)
        {
            printf("\t%d\t\t%s\t\t%s\t\t%c\n",
                   jugadores[i].codigoJugador,
                   jugadores[i].apellidoJugador,
                   jugadores[i].nombreJugador,
                   jugadores[i].sexo);
        }
    }
}

void listarAlfabeticamenteJugadores(eJugadores jugadores[], int cantidad)
{
    int i;
    int j;
    int auxCodigo;
    char auxNombre[51];
    char auxApellido[51];
    char auxSexo;

    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(strcmp(jugadores[i].apellidoJugador,jugadores[j].apellidoJugador) > 0
                    || (strcmp(jugadores[i].apellidoJugador,jugadores[j].apellidoJugador) == 0
                        && strcmp(jugadores[i].nombreJugador,jugadores[j].nombreJugador) > 0)) // si es -1, quiere decir que es MENOR, ordena de menor a mayor
            {
                auxCodigo = jugadores[i].codigoJugador;
                jugadores[i].codigoJugador = jugadores[j].codigoJugador;
                jugadores[j].codigoJugador = auxCodigo;

                strcpy(auxNombre, jugadores[i].nombreJugador);
                strcpy(jugadores[i].nombreJugador, jugadores[j].nombreJugador);
                strcpy(jugadores[j].nombreJugador, auxNombre);

                strcpy(auxApellido, jugadores[i].apellidoJugador);
                strcpy(jugadores[i].apellidoJugador, jugadores[j].apellidoJugador);
                strcpy(jugadores[j].apellidoJugador, auxApellido);

                auxSexo = jugadores[i].sexo;
                jugadores[i].sexo = jugadores[j].sexo;
                jugadores[j].sexo = auxSexo;
            }
        }
    }

}

int encontrarJugadores(eJugadores jugadores[], int cantidad, int valor)
{
    for(int i=0; i<cantidad; i++)
    {
        if (jugadores[i].codigoJugador==valor)
            return i;
    }
    return -1;
}

void eliminarJugadores(eJugadores jugadores[], int cantidad)
{
    int auxCodigo;
    char auxCodigoStr[256];
    int indiceEncontrarJugador;
    mostrarJugadores(jugadores, cantidad);
    auxCodigo = validarStringNumerico(auxCodigo, "\n\nIngrese el CODIGO del jugador a eliminar: ", auxCodigoStr);
    indiceEncontrarJugador = encontrarJugadores(jugadores, cantidad, auxCodigo);
    jugadores[indiceEncontrarJugador].codigoJugador = -1;
}
