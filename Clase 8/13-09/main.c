#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"

int main()
{
    sAlumno miAlumno;
    miAlumno = pedirAlumno();
    mostrarAlumno(miAlumno);
    return 0;
}


