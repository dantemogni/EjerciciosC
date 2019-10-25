#ifndef EMPLEADOSDIN_H_INCLUDED
#define EMPLEADOSDIN_H_INCLUDED

typedef struct
{
    char nombre[31];
    int edad;
    int legajo;
    int isEmpty;
} eEmpleado;

/** \brief Muestra un men� que debe ser personalizado en la funci�n. Pide un int que guarda en la variable opcion.
 *
 * \param No recibe par�metros.
 * \return la variable int opcion que ingresa el usuario.
 *
 */
int menu();

int mostrarEmpleado(const char *path, int position);

long measureFile(const char *path);

void mostrarEmpleados(const char *path);

int buscarEmpleado(const char *path, int legajo);

void altaEmpleado(const char *path);

#endif // EMPLEADOSDIN_H_INCLUDED
