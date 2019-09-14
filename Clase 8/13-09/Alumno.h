#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    /*campos o atributos*/
    int legajo;
    char nombre[50];
    int nota;
}sAlumno;/*s de srtuct
sAlumno es un tipo de dato, es como un int float o void*/

void mostrarAlumno(sAlumno);
sAlumno pedirAlumno();
