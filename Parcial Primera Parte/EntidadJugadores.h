
typedef struct
{
    int codigoJugador;
    char apellidoJugador[31];
    char nombreJugador[31];
    int codigoEquipo;
    char sexo;
    eFecha fechaNacimiento;
} eJugadores;

void subMenuJugadores(eJugadores[], int);
void cargaJugadores(eJugadores[], int);
void mostrarJugadores(eJugadores[], int);
void listarAlfabeticamenteJugadores(eJugadores[], int);
int encontrarJugadores(eJugadores[], int, int);
void eliminarJugadores(eJugadores[], int);
