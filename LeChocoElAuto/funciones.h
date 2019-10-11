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
    char patente[10];
    eFecha fechaIngreso;
    int horaEntrada;
    int horaSalida;
    ePropietario idPropietario;
} eVehiculo;

void menu(ePropietario[], eVehiculo[], int);
void cargaPropietarios(ePropietario[], int);
void mostrarPropietarios(ePropietario[], int);
void modificarPropietario(ePropietario[], int);
void eliminarPersonas(ePropietario[], int);
void ingresoVehiculo(eVehiculo[], int);
void egresoVehiculo(eVehiculo[], int);
int encontrarVehiculo(eVehiculo[], int, char[10]);
void mostrarVehiculos(eVehiculo[], int);
