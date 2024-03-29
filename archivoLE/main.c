#include <stdio.h>

#define ARCH	".\\bin.dat"
#define ESC 27

struct a
{
    char nombre[31];
    int edad;
};

int main (void)
{
    FILE  *bin;
    struct a pers;
    int cant;

    if ((bin=fopen(ARCH,"rb+"))==NULL)
    {
        if ((bin=fopen(ARCH,"wb+"))==NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
    }

    do
    {
        printf("\nIngrese el nombre: ");
        gets(pers.nombre);

        printf("Ingrese la edad: ");
        scanf("%d",&pers.edad);

        fflush(stdin);
        fseek(bin, 0L, SEEK_END); //Argumentos: puntero al archivo, desplazamiento en bytes (0L ero long), origen (al final del archivo).
        fwrite(&pers,sizeof(pers),1,bin);

        printf("\nPresione ESC para terminar");
    }
    while((getche())!=ESC);

    rewind (bin);//Se lleva el indicador de posici�n al principio para comenzar a leer

    while(!feof(bin))
    {
        cant = fread(&pers,sizeof(pers),1,bin);

        if(cant!=1)
        {
            if(feof(bin))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }

        printf("\n%s\t%d",pers.nombre,pers.edad);
    }

    fclose(bin);
    getch();//Funciona como un system("pause");

    return 0;
}
