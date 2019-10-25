#include <stdio.h>
#include <stdlib.h>

void leerPuntero(int* p);

int main()
{

    int x =10;

    int* p = &x;//Puntero, contiene una direcci�n de memoria a un entero. *p cuando utilizo la variable.
    int* q = p;//El puntero q apunta al mismo lugar que p.

    int** r = &p;//Un puntero que almacena un puntero.

    printf("%d\n", **r);//Muestra x. Puntero a puntero.

//    char* j;//Puntero, contiene una direcci�n de memoria a un char.
//
//    p=&x;//Guarda la direcci�n de memoria de x en el puntero p.
//
//    printf("%d\n", x);
//
//    printf("%d\n", *p);//*p operador de indirecci�n. printfmuestra el contenido de la direcci�n de memoria contenida en p.
//
//    printf("%x\n", p);//Muestra la direcci�n de memoria %x m�scara para hexadecimal. %p muestra el puntero.
//
//    printf("%x\n", &x);//�dem anterior.
//
//    printf("Direccion de x: %x\n", &x);
//
//    printf("Antes de llamar a la funcion\n");
//
//    printf("%d\n", x);
//
//    leerPuntero(&x);
//
//     printf("Despues de llamar a la funcion\n");

    printf("%d\n", x);

    return 0;
}

void leerPuntero(int* p)
{

//    printf("%d\n", *p);
    printf("Direccion guardada en p: %x\n", p);

    *p=38;//Afecto a x en el main desde el �mbito de la funci�n.

}
