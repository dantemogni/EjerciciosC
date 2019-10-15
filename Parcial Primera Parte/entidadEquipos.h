typedef struct
{
    int codigoEquipo;
    char nombre[51];
    char localidad[33];
} eEquipos;

void subMenuEquipo(eEquipos[], int);
void cargaEquipos(eEquipos[], int);
void mostrarEquipos(eEquipos[], int);
void listarAlfabeticamenteEquipos(eEquipos[], int);
void modificarEquipo(eEquipos[], int);
int encontrarEquipo(eEquipos[], int, int);
void eliminarEquipo(eEquipos[], int);
