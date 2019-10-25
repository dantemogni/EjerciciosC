#include "lista.h"

ListaPersona* lista_initLista()
{
    ListaPersona* peopleList = (ListaPersona*)malloc(sizeof(ListaPersona));

    peopleList->indice=0;
    peopleList->size=2;
    peopleList->lista= (Persona**)malloc(sizeof(Persona*)*peopleList->size);

    return peopleList;
}
