#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int legajo;
    int edad;
    float altura;

}ePersona;
ePersona* new_persona();///constructor por defecto
int mostrarPersona(ePersona*);
int deletePerson(ePersona*);
ePersona* newPersonParameters(int,int,float);
