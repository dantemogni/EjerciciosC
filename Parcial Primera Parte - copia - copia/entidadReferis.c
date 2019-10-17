#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "entidadReferis.h"
#include "validaciones.h"


void subMenuReferis(eReferi referis[], int cantidad)
{
    printf("\n***REFERIS***\n\n");
    printf("Ingresar nuevo referi\n\n");

    cargaReferis(referis, cantidad);
    mostrarReferis(referis, cantidad);
}

void cargaReferis(eReferi referis[], int cantidad)
{
    int i;
    char hardNombres [][51] = {"Thomas", "Guille", "Robyn", "Rodolfo", "Alberto"};
    char hardApellido [][51] = {"Luccas", "Mate", "Centu", "Perez", "Calcha"};
    char hardSexo = 'm';
    char hardMail[][31] = {"thomas@gmail.com", "guillekpo@gmail.com", "robyn2000@gmail.com", "rodol98@gmail.com", "bertoo@gmail.com"};
    int hardDia[] = {31,7,26,5,17};
    int hardMes[] = {03,01,10,5,6};
    int hardAnio[] = {2000,1987,1980,1993,1965};


    printf("\n// Ingresar el apellido del referi: ...\n");
    //scanf
    printf("// Ingresar el nombre del referi: ...\n");
    //scanf
    printf("// Ingresar el sexo del referi: ...\n");
    //scanf
    printf("// Ingresar el mail del referi: ...\n");
    //scanf
    printf("// Ingresar la fecha de nacimiento del referi: ...\n\n");
    //scanf

    for(i=0; i<cantidad; i++)
    {
        strcpy(referis[i].nombreReferi,hardNombres[i]);
        strcpy(referis[i].apellidoReferi,hardApellido[i]);
        referis[i].sexo = hardSexo;
        referis[i].codigoReferi = i+1;
        strcpy(referis[i].mail, hardMail[i]);
        referis[i].fechaNacimiento.dia = hardDia[i];
        referis[i].fechaNacimiento.mes = hardMes[i];
        referis[i].fechaNacimiento.anio = hardAnio[i];
    }
}

void mostrarReferis(eReferi referis[], int cantidad)
{
    int i;
    printf("\n\tCODIGO\t\tAPELLIDO\tNOMBRE\t\tSEXO\tMAIL\t\t\tF. DE NACIMIENTO\n");
    for(i=0; i<cantidad; i++)
    {
        if(referis[i].codigoReferi!=-1)
        {
            printf("\t%d\t\t%s\t\t%s\t\t%c\t%s\t\t%d/%d/%d\n",
                   referis[i].codigoReferi,
                   referis[i].apellidoReferi,
                   referis[i].nombreReferi,
                   referis[i].sexo,
                   referis[i].mail,
                   referis[i].fechaNacimiento.dia,
                   referis[i].fechaNacimiento.mes,
                   referis[i].fechaNacimiento.anio);
        }
    }
}


