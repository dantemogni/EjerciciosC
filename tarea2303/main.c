#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>//Permite el uso de caracteres de otros idiomas.
#include <locale.h>//Permite el uso de s�mbolos de monedas y otros.

//Parcial ingreso, ejercicio 1.

void main(void)
{
    int ancho;
    int alto;

    setlocale(LC_ALL, "");//Activa el uso de caracteres latinos

    printf("Por favor ingrese el ancho del rect�ngulo en cm. y presione enter: \n");

    scanf("%d", &ancho);

    printf("Por favor ingrese el alto del rect�ngulo en cm. y presione enter: \n");

    scanf("%d", &alto);

    printf("El �rea del rect�ngulo es %d cm2", ancho*alto);

}
