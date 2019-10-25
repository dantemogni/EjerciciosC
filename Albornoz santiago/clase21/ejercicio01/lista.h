#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "persona.h"

typedef struct{
    int size;
    int indice;
    Persona** lista;
}ListaPersona;

#endif // LISTA_H_INCLUDED

ListaPersona* lista_initLista();
