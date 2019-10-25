#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#define T 3





float promedioPromedio(float buffer, int contador)
{
    float promedioDePromedios;

    promedioDePromedios=buffer/contador*100;

    return promedioDePromedios;
}

float calcularPromedio(int nota1, int nota2, int nota3)
{
    float promedio;
    promedio=(float)(nota1+nota2+nota3)/T;

    return promedio;
}

int cargarAlumnos(char nombre[][50],char sexo[], int edad[], int legajo[], int nota1[], int nota2[], int nota3[],int numeroAlumno, float promedio[])
{

    printf("Ingrese su nombre completo: ");
    fflush(stdin);
    gets(nombre[numeroAlumno]);


    printf("Ingrese el sexo del alumno: ");
    fflush(stdin);
    scanf("%c",&sexo[numeroAlumno]);
    sexo[numeroAlumno]=toupper(sexo[numeroAlumno]);

    while(sexo[numeroAlumno]!='F'&&sexo[numeroAlumno]!='M')
    {
        printf("Ingrese el sexo del alumno: ");
        fflush(stdin);
        scanf("%c",&sexo[numeroAlumno]);
        sexo[numeroAlumno]=toupper(sexo[numeroAlumno]);
    }

    printf("Ingrese edad: ");
    scanf("%d",&edad[numeroAlumno]);

    printf("Ingrese legajo: ");
    scanf("%d",&legajo[numeroAlumno]);

    printf("Ingrese nota 1: ");
    scanf("%d",&nota1[numeroAlumno]);
    printf("Ingrese nota 2: ");
    scanf("%d",&nota2[numeroAlumno]);
    printf("Ingrese nota 3: ");
    scanf("%d",&nota3[numeroAlumno]);
    promedio[numeroAlumno]=calcularPromedio( nota1[numeroAlumno],nota2[numeroAlumno],nota3[numeroAlumno]);

    numeroAlumno++;
    return numeroAlumno;

}

void cargarDatos(char nombre[][50], char sexo[], int edad[], int legajo[], int nota1[], int nota2[], int nota3[], int cant, float promedio[])
{
    int i;

    printf("%20s %6s %6s %6s %6s %6s %6s %8s", "nombre", "sexo", "edad", "legajo", "nota 1", "nota2", "nota3", "promedio\n");
    for (i=0; i<cant; i++)
    {
        if(edad[i]!=-1)
        {
            printf("%20s %6c %6d %6d %6d %6d %6d %8.2f \n",nombre[i], sexo[i], edad[i], legajo[i], nota1[i], nota2[i], nota3[i], promedio[i]);
        }

    }
    system("pause");
}
void inicializarvector(char nombre[][50], char sexo[], int edad[], int legajo[], int nota1[], int nota2[], int nota3[], float promedio[])
{
    int i;
    for(i=0; i<T; i++)
    {
        strcpy(nombre[i], " ");
        legajo[i]=-1;
        nota1[i]=0;
        nota2[i]=0;
        nota3[i]=0;
        edad[i]=-1;
        sexo[i]='N';

    }
}

void seleccionDatos(char nombre[][50],char sexo[], int edad[], int legajo[], int nota1[], int nota2[], int nota3[], int cant, float promedio[])
{
    int ingreseLegajo;
    int i;
    char respuesta;

    printf("ingrese legajo: ");
    scanf("%d",&ingreseLegajo);
    for(i=0;i<=cant;i++)
    {
        if(ingreseLegajo==legajo[i])
        {
            printf("Se a encontrado legajo!!!\n");
            printf("%20s %6s %6s %6s %6s %6s %6s %8s", "nombre", "sexo", "edad", "legajo", "nota 1", "nota2", "nota3", "promedio\n");
            printf("%20s %6c %6d %6d %6d %6d %6d %8.2f \n",nombre[i], sexo[i], edad[i], legajo[i], nota1[i], nota2[i], nota3[i], promedio[i]);
            printf("¿Desea realizar cambios?(s/n)");
            fflush(stdin);
            scanf("%c",&respuesta);
            if(respuesta=='s')
            {
                modificacion(nota1,nota2,nota3,i,promedio);
            }else
            {
                 break;
            }
        }
    }
    if(i==4)
    {
        printf("No se a encontrado legajo");
    }

}


void modificacion( int nota1[], int nota2[], int nota3[],int numeroAlumno, float promedio[])
{
    printf("Ingrese nota 1: ");
    scanf("%d",&nota1[numeroAlumno]);
    printf("Ingrese nota 2: ");
    scanf("%d",&nota2[numeroAlumno]);
    printf("Ingrese nota 3: ");
    scanf("%d",&nota3[numeroAlumno]);

    promedio[numeroAlumno]=calcularPromedio( nota1[numeroAlumno],nota2[numeroAlumno],nota3[numeroAlumno]);
}

void calculoDePromedios(char nombre[][50], int legajo[], int cantAlumnos, float promedio[])
{
    int i;
    int flag=0;
    char aprobados[T][50];
    char alumnoMayor[50];
    char alumnoMenor[50];
    float promedioMayor;
    float promedioMenor;
    int alumnosAprobados=0;
    int alumnoDesaprobados=0;
    int contador=0;
    float porcentajeDesaprobados;
    float porcentajeAprobados;


    for(i=0;i<cantAlumnos;i++)
    {
        if(promedio[i]>=6 && legajo[i]!=-1)
        {
            strcpy(aprobados[i],nombre[i]);
            alumnosAprobados++;
        }else
        {
            if(promedio[i]<6 && legajo[i]!=-1)
            {
                alumnoDesaprobados++;
            }
        }

        if(flag==0&&strcmp(nombre[i]," ")!=0)
        {
            strcpy(alumnoMenor,nombre[i]);
            strcpy(alumnoMayor,nombre[i]);
            promedioMayor=promedio[i];
            promedioMenor=promedio[i];
            contador++;
            flag=1;
        }else
        {
            if(promedioMayor<promedio[i]&&strcmp(nombre[i]," ")!=0)
            {
                strcpy(alumnoMayor,nombre[i]);
                promedioMayor=promedio[i];
                contador++;
            }else
            {
                if(promedioMenor>promedio[i]&&strcmp(nombre[i]," ")!=0)
                {
                    strcpy(alumnoMenor,nombre[i]);
                    promedioMenor=promedio[i];
                    contador++;
                }
            }
        }
    }
    if(contador!=0)
    {
        porcentajeAprobados=promedioPromedio(alumnosAprobados,contador);
        porcentajeDesaprobados=promedioPromedio(alumnoDesaprobados,contador);
    }


    cargarPromedios(aprobados,alumnoMayor, alumnoMenor,promedioMayor,promedioMenor, alumnosAprobados,  alumnoDesaprobados, cantAlumnos,  porcentajeAprobados,  porcentajeDesaprobados);

}

void cargarPromedios(char aprobados[][50], char alumnoMayor[50], char alumnoMenor[50], float promedioMayor, float promedioMenor, int alumnosAprobados, int alumnosDesaprobados, int cant, float promedioAprobados, float promedioDesaprobados)
{
    int i;
    printf("%20s \n", "Aprobados");
    for (i=0; i<alumnosAprobados; i++)
    {
        printf("%20s\n",aprobados[i] );
    }

    printf("\nEl mayor promedio es de %s con %.2f", alumnoMayor, promedioMayor);
    printf("\nEl menor promedio es de %s con %.2f", alumnoMenor, promedioMenor);
    printf("\ncantidad de desaprobados %d", alumnosDesaprobados);
    printf("\nPorcentaje: %.2f ",promedioDesaprobados);
    printf("\ncantidad de aprobados %d", alumnosAprobados);
    printf("\nPorcentaje: %.2f ",promedioAprobados);

    system("pause");

}

void ordenarNombre(char nombre[][50], char sexo[], int edad[], int legajo[], int nota1[], int nota2[], int nota3[], int cant, float promedio[])
{
    int i;
    int j;
    char temp[50];
    char tempSexo;
    int tempEdad;
    int tempLegajo;
    int tempNumero1;
    int tempNumero2;
    int tempNumero3;

    float tempFloat;

    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(stricmp(nombre[j],nombre[i])<0)
            {
                strcpy(temp,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],temp);

                tempSexo=sexo[i];
                sexo[i]=sexo[j];
                sexo[j]=tempSexo;

                tempEdad=edad[i];
                edad[i]=edad[j];
                edad[j]=tempEdad;

                tempLegajo=legajo[i];
                legajo[i]=legajo[j];
                legajo[j]=tempLegajo;

                tempNumero1=nota1[i];
                nota1[i]=nota1[j];
                nota1[j]=tempNumero1;

                tempNumero2=nota2[i];
                nota2[i]=nota2[j];
                nota2[j]=tempNumero2;

                tempNumero3=nota3[i];
                nota3[i]=nota3[j];
                nota3[j]=tempNumero3;

                tempFloat=promedio[i];
                promedio[i]=promedio[j];
                promedio[j]=tempFloat;
            }else
            {
                if(stricmp(nombre[j],nombre[i])==0&&promedio[j]>promedio[i])
                {
                    strcpy(temp,nombre[i]);
                    strcpy(nombre[i],nombre[j]);
                    strcpy(nombre[j],temp);

                    tempSexo=sexo[i];
                    sexo[i]=sexo[j];
                    sexo[j]=tempSexo;

                    tempEdad=edad[i];
                    edad[i]=edad[j];
                    edad[j]=tempEdad;

                    tempLegajo=legajo[i];
                    legajo[i]=legajo[j];
                    legajo[j]=tempLegajo;

                    tempNumero1=nota1[i];
                    nota1[i]=nota1[j];
                    nota1[j]=tempNumero1;

                    tempNumero2=nota2[i];
                    nota2[i]=nota2[j];
                    nota2[j]=tempNumero2;

                    tempNumero3=nota3[i];
                    nota3[i]=nota3[j];
                    nota3[j]=tempNumero3;

                    tempFloat=promedio[i];
                    promedio[i]=promedio[j];
                    promedio[j]=tempFloat;
                }
            }
        }
    }

}

void ordenarSexo(char nombre[][50], char sexo[], int edad[], int legajo[], int nota1[], int nota2[], int nota3[], int cant, float promedio[])
{
    int i;
    int j;
    char temp[50];
    char tempSexo;
    int tempEdad;
    int tempLegajo;
    int tempNumero1;
    int tempNumero2;
    int tempNumero3;
    float tempFloat;

    for(i=0;i<T-1;i++)
    {
        for(j=i+1;j<T;j++)
        {
            if(sexo[j]=='F')
            {
                strcpy(temp,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],temp);

                tempSexo=sexo[i];
                sexo[i]=sexo[j];
                sexo[j]=tempSexo;

                tempEdad=edad[i];
                edad[i]=edad[j];
                edad[j]=tempEdad;

                tempLegajo=legajo[i];
                legajo[i]=legajo[j];
                legajo[j]=tempLegajo;

                tempNumero1=nota1[i];
                nota1[i]=nota1[j];
                nota1[j]=tempNumero1;

                tempNumero2=nota2[i];
                nota2[i]=nota2[j];
                nota2[j]=tempNumero2;

                tempNumero3=nota3[i];
                nota3[i]=nota3[j];
                nota3[j]=tempNumero3;

                tempFloat=promedio[i];
                promedio[i]=promedio[j];
                promedio[j]=tempFloat;
            }
        }
    }
}
void mostrarJuanes(char nombre[][50], char sexo[], int edad[], int legajo[], int nota1[], int nota2[], int nota3[], int cant, float promedio[])
{
    int i;

    printf("%20s \n", "Los que se llaman juan");

    printf("%20s %6s %6s %6s %6s %6s %6s %8s", "nombre", "sexo", "edad", "legajo", "nota 1", "nota2", "nota3", "promedio\n");

    for (i=0; i<cant; i++)
    {
        if(stricmp(nombre[i],"juan")==0)
        {
            printf("%20s %6c %6d %6d %6d %6d %6d %8.2f \n",nombre[i], sexo[i], edad[i], legajo[i], nota1[i], nota2[i], nota3[i], promedio[i]);
        }
    }
    system("pause");

}

void mostrarP(char nombre[][50], char sexo[], int edad[], int legajo[], int nota1[], int nota2[], int nota3[], int cant, float promedio[])
{
    int i;
    printf("%20s \n", "Los que empiezan con P");

    printf("%20s %6s %6s %6s %6s %6s %6s %8s", "nombre", "sexo", "edad", "legajo", "nota 1", "nota2", "nota3", "promedio\n");

        for (i=0; i<cant; i++)
        {
            if(nombre[i][0]=='p')
            {
                printf("%20s %6c %6d %6d %6d %6d %6d %8.2f \n",nombre[i], sexo[i], edad[i], legajo[i], nota1[i], nota2[i], nota3[i], promedio[i]);
            }
        }

    system("pause");


}

void porcentajeEdad(int edad[], int cant)
{
    int edadmenor=0;
    int edadmedia=0;
    int edadmayor=0;
    int i;

    for(i=0;i<=cant;i++)
    {
        if(edad[i]>=15&&edad[i]<=18)
        {
            edadmenor++;
        }else
        {
            if(edad[i]>=19&&edad[i]<=25)
            {
                edadmedia++;
            }else
            {
                if(edad[i]>=26)
                {
                    edadmayor++;
                }
            }
        }
    }

    controlEdad(edadmenor, edadmedia, edadmayor);



}

void controlEdad( int edadmenor,int edadmedia,int edadmayor)
{
    int i;

    printf("EDADES:");
    printf("\n%6s :","15-18");
    for (i=1; i<=edadmenor; i++)
    {
           printf("#");
    }
    printf("\n%6s :","19-25");
    for (i=1; i<=edadmedia; i++)
    {
           printf("#");
    }
    printf("\n%6s :","26+");
    for (i=1; i<=edadmedia; i++)
    {
           printf("#");
    }
    printf("\n");
    system("pause");
}
