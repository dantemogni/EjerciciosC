#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 3

int main()
{
    eVehiculo vehiculos[CANT];
    ePropietario propietarios[CANT];
    menu(propietarios, vehiculos, CANT);
    return 0;
}
