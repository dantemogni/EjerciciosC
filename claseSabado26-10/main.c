#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"

int main()
{
//IMPORTANTE: ABRIR ARCHIVO - MODIFICAR ARCHIVO -  BORRAR ARCHIVO

    FILE* archivo; //para trabajar con archivos hay que crear la estructura FILES. Nos da acceso al archivo
//    char mensaje[50];
    int i = 0;
    eAlumno* lista[10];
    eAlumno* unAlumno;

    //todo en char porque el archivo es de tipo texto
    char id[10];
    char nombre[50];
    char apellido[50];
    char nota[10];

    archivo = fopen("MOCK_DATA.csv","r"); //abrir archivo en directorio especifico, para leer o escribir. Recibe dos cadenas, el primero es el PATH del archivo. Si pongo solo el nombre del archivo, se crea en el directorio del proyecto. El segundo es el modo de apertura ("r" o "w", etc)
                                    // lo asigno a "archivo" porque fopen devuelve un puntero a FILE*, si no existe el directorio devuelve NULL
//    if(archivo!=NULL)
//    {
//        printf("Archivo creado");
//    } else
//    {
//        printf("Archivo no creado");
//    }

//    fgets(mensaje,49,archivo); // falsa lectura, para que no printee la primera linea (la cabecera)

    fscanf(archivo, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, nota); //id, nombre, ap, nota ya apuntan a memoria porque son arrays. no se pone * ni &

    //"%[^,]," -----> se traduce a "lee hasta la coma y excluila

    //feof() devuelve TRUE o FALSE (0 o 1) si encontro o no el final

    /* SIN ESTRUCTURA */
//    while(!feof(archivo))
//    {
//        if(feof(archivo))
//            break;
////        fgets(mensaje,49,archivo);
//        fscanf(archivo, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, nota);
//        printf("%s--%s--%s--%s\n", id, nombre, apellido, nota);
//        i++;
//    }

//    fprintf(archivo, "El dia esta lindo");

    /* ESTRUCTURA */
    printf("***** CON ESTRUCTURA *****\n");
    while(!feof(archivo))
    {
        fscanf(archivo, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, nota);
        unAlumno = new_Alumno_Parametros(atoi(id),nombre,apellido,atof(nota)); //--> hablo de malloc IMPORTANTE declarlo en while, porque asi pide memoria para CADA dato ((esto es un encapsulamiento de malloc))
        //setId(unAlumno, 7); //para modificar id
        *(lista+i) = unAlumno; //el * primero referencia el dato y no la memoria
        i++;
    }

     fclose(archivo);

    for(i=0;i<10;i++)
    {
        //lista[i] = lista+i porque en ambos casos i se incrementa,uno es para vectores y otro aritmetica de punteros
      unAlumno = *(lista+i);
      printf("%d - %s - %s - %.2f\n",getId(unAlumno), (*(lista+i))->nombre, (*(lista+i))->apellido, (*(lista+i))->nota);
    }

    return 0;
}

