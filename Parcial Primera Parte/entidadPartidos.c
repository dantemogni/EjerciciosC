#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "entidadPartidos.h"
#include <string.h>

void subMenuPartidos(ePartido partidos[], int cantidad)
{
    int opciones;
    printf("\n***PARTIDOS***\n\n");
    printf("1 - Ingresar nuevo partido\n2 - Listar los partidos por fecha\n\n");
    printf("Que desea hacer? ");
    scanf("%d",&opciones);
    switch(opciones)
    {
    case 1:
        cargaPartidos(partidos, cantidad);
        mostrarPartidos(partidos, cantidad);
        break;
    case 2:
        listarFechaPartidos(partidos,cantidad);
        mostrarPartidos(partidos, cantidad);
        break;
    }
}

void cargaPartidos(ePartido partidos[], int cantidad)
{
    int i;
    int hardCodVis[] = {2,1,5,4,3};
    int hardCodLocal[] = {4,3,2,1,5};
    int hardCodReferi[] = {1,2,2,2,4};
    int hardDia[] = {2,4,22,15,30};
    int hardMes[] = {07,03,12,05,01};
    int hardAnio = {2019};

    printf("\n// Ingresar el codigo del equipo visitante: ...\n");
    //scanf
    printf("// Ingresar el codigo del equipo local: ...\n");
    //scanf
    printf("// Ingresar el codigo del referi: ...\n");
    //scanf
    printf("// Ingresar la fecha del partido: ...\n\n");
    //scanf

    for(i=0; i<cantidad; i++)
    {
        partidos[i].codigoLocal = hardCodLocal[i];
        partidos[i].codigoReferi = hardCodReferi[i];
        partidos[i].codigoVisitante = hardCodVis[i];
        partidos[i].codigoPartido = i+1;
        partidos[i].fechaPartido.dia = hardDia[i];
        partidos[i].fechaPartido.mes = hardMes[i];
        partidos[i].fechaPartido.anio = hardAnio;
    }
}

void mostrarPartidos(ePartido partidos[], int cantidad)
{
    int i;
    printf("\n\tCOD. PARTIDO\tCOD. LOCAL\tCOD. VISITANTE\tCOD.REFERI\tF. DEL PARTIDO\n");
    for(i=0; i<cantidad; i++)
    {
        if(partidos[i].codigoPartido!=-1)
        {
            printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d/%d/%d\n",
                   partidos[i].codigoPartido,
                   partidos[i].codigoLocal,
                   partidos[i].codigoVisitante,
                   partidos[i].codigoReferi,
                   partidos[i].fechaPartido.dia,
                   partidos[i].fechaPartido.mes,
                   partidos[i].fechaPartido.anio);
        }
    }
}

void listarFechaPartidos(ePartido partidos[], int cantidad)
{
    int i;
    int j;
    int auxCodPartido;
    int auxCodLocal;
    int auxCodVisitante;
    int auxCodReferi;
    int auxDia;
    int auxMes;
    int auxAnio;

    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(partidos[i].fechaPartido.anio>partidos[j].fechaPartido.anio||
                    (partidos[i].fechaPartido.mes>partidos[j].fechaPartido.mes)||
                    (partidos[i].fechaPartido.dia>partidos[j].fechaPartido.dia))
            {
                auxCodPartido = partidos[i].codigoPartido;
                partidos[i].codigoPartido = partidos[j].codigoPartido;
                partidos[j].codigoPartido = auxCodPartido;

                auxCodLocal = partidos[i].codigoLocal;
                partidos[i].codigoLocal = partidos[j].codigoLocal;
                partidos[j].codigoLocal = auxCodLocal;

                auxCodVisitante = partidos[i].codigoVisitante;
                partidos[i].codigoVisitante = partidos[j].codigoVisitante;
                partidos[j].codigoVisitante = auxCodVisitante;

                auxCodReferi = partidos[i].codigoReferi;
                partidos[i].codigoReferi = partidos[j].codigoReferi;
                partidos[j].codigoReferi = auxCodReferi;

                auxAnio = partidos[i].fechaPartido.anio;
                partidos[i].fechaPartido.anio = partidos[j].fechaPartido.anio;
                partidos[j].fechaPartido.anio = auxAnio;

                auxMes = partidos[i].fechaPartido.mes;
                partidos[i].fechaPartido.mes = partidos[j].fechaPartido.mes;
                partidos[j].fechaPartido.mes = auxMes;

                auxDia = partidos[i].fechaPartido.dia;
                partidos[i].fechaPartido.dia = partidos[j].fechaPartido.dia;
                partidos[j].fechaPartido.dia = auxCodReferi;

            }
        }
    }
}
