#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"

eAlumno* new_Alumno()
{
    eAlumno* unAlumno = (eAlumno*) malloc(sizeof(eAlumno)); //(eAlumno*) es un casteo, convierte el dato devuelto por malloc a tipo eAlumno. SIEMPRE CASTEAR
    return unAlumno;
}

eAlumno* new_Alumno_Parametros(int id, char* nombre, char* apellido, float nota)
{
    eAlumno* unAlumno = new_Alumno();
    unAlumno->id = id;
    strcpy(unAlumno->apellido, apellido);
    strcpy(unAlumno->nombre, nombre);
    unAlumno->nota = nota;
    return unAlumno;
}
int getId(eAlumno* unAlumno) // para eliminar la flechita (->) en el printf
{
    int id;
    if(unAlumno!=NULL)
    {
        id = unAlumno->id;
    }
    return id;
}
void setId(eAlumno* unAlumno, int id)
{
    unAlumno->id = id;
}
