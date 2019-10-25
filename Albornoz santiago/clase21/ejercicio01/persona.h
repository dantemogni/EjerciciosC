#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct{
    int edad;
    char nombre[20];
} Persona;

#endif // PERSONA_H_INCLUDED

char preguntarSalir();
Persona* persona_newPersona(void);
void persona_toString(Persona* this);
int persona_setNombre(Persona* this,char* nombre);
char* persona_getNombre(Persona* this);
int persona_setEdad(Persona* this,int edad);
int persona_getEdad(Persona* this);
void persona_initLista(void);
void persona_addPersona(Persona* this);

    int size;
    int indice;
    Persona** lista;
