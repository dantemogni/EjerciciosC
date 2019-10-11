typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idPropietario;
    char nombre[10];
    eFecha fechaNacimiento;
} ePropietario;

typedef struct
{
    int patente;
    eFecha fechaIngreso;
    int horaEntrada;
    int horaSalida;
    ePropietario idPropietario;
} eVehiculo;

void menu(ePropietario[], eVehiculo[], int);
void cargaPropietarios(ePropietario[], int);
void mostrarDatos(ePropietario[], int);
void modificarPropietario(ePropietario[], int);
void eliminarPersonas(ePropietario[], int);
void ingresoVehiculo(eVehiculo[], int);
void mostrarVehiculos(eVehiculo[], int);
