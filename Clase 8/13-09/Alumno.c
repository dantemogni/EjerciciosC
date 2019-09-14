#include "Alumno.h"

void mostrarAlumno(sAlumno unAlumno)
{
    printf("%d--%s--%d\n", unAlumno.legajo, unAlumno.nombre, unAlumno.nota);
}
sAlumno pedirAlumno()
{
    sAlumno miAlumno;
    printf("Ingrese el legajo: ");
    scanf("%d", &miAlumno.legajo);
    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre);
    printf("Ingrese la nota: ");
    scanf("%d", &miAlumno.nota);
    return miAlumno;
}
