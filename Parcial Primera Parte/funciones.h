typedef struct
{
    int codigoEquipo;
    char nombre[51];
    char localidad[33];
}eEquipos;

typedef struct
{
    int codigoJugador;
    char apellidoJugador[31];
    char nombreJugador[31];
    eEquipos codigoEquipo;
    char sexo;
    eFecha fechaNacimiento;
}eJugadores;

typedef struct
{
    int codigoReferi;
    char apellidoReferi[31];
    char nombreReferi[31];
    char sexo;
    char mail[31];
    eFecha fechaNacimiento;
}eReferi;

typedef struct
{
    int codigoPartido;
    eEquipos codigoVisitante;
    eEquipos codigoLocal;
    eReferi codigoReferi;
    eFecha fechaPartido;
}ePartido;

