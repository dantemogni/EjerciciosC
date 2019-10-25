#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "funcionesGet.h"


/**
 * \brief Solicita un n�mero al usuario y devuelve un int
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
int getInt(char* mensaje)
{
    int auxiliar;

    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un n�mero al usuario y devuelve un float
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
float getFloat(char* mensaje)
{
    float auxiliar;

    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un caracter al usuario y devuelve un char
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje)
{
    char auxiliar;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char* mensaje,char* input)
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

/**
 * \brief Verifica si el valor recibido es num�rico
 * \param Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int validarStringNumerico(char* stringNumerico)
{
   int i=0;
   while(stringNumerico[i] != '\0')
   {
       if(stringNumerico[i] < '0' || stringNumerico[i] > '9')
           return 0;

       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es num�ricos flotante
 * \param Array con la cadena a ser analizada
 * \return 1 si es n�merico flotante y 0 si no lo es
 *
 */
int validarStringNumericoFlotante(char* stringNumerico)
{
   int i=0;
   int cantidadPuntos=0;
   while(stringNumerico[i] != '\0')
   {
       if (stringNumerico[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(stringNumerico[i] < '0' || stringNumerico[i] > '9')
           return 0;

       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es alfanum�rico
 * \param Array con la cadena a ser analizada
 * \return 1 si es alfan�merico y 0 si no lo es
 *
 */
int validarStringAlfaNumerico(char* stringNumerico)
{
    int i=0, retorno=1;

    while(stringNumerico[i]!='\0')
    {
        if((stringNumerico[i]!=' ')&&(stringNumerico[i]<'a'|| stringNumerico[i]>'z')&&(stringNumerico[i]<'A'|| stringNumerico[i]>'Z')&&(stringNumerico[i]<'0'|| stringNumerico[i]>'9'))
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}

/**
 * \brief Verifica si el array recibido contiene solo letras
 * \param Array con la cadena a ser analizada
 * \return 1 si es solo letras y 0 si no lo es
 *
 */
int validarStringLetras(char* stringLetras)
{
   int i=0;

   while(stringLetras[i] != '\0')
   {
       if((stringLetras[i] != ' ') && (stringLetras[i] < 'a' || stringLetras[i] > 'z') && (stringLetras[i] < 'A' || stringLetras[i] > 'Z'))
           return 0;

       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el array recibido es num�rico telefonico
 * \param Array con la cadena a ser analizada
 * \return 1 si es n�merico telefonico y 0 si no lo es
 *
 */
int validarStringTelefonico(char* stringTelefono)
{
    int i=0;
    int contadorGuiones=0;

    while(stringTelefono[i] != '\0')
   {
       if((stringTelefono[i] != ' ') && (stringTelefono[i] != '-') && (stringTelefono[i] < '0' || stringTelefono[i] > '9'))
           return 0;
       if(stringTelefono[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras y 0 si no
 */
int getStringLetras(char* mensaje,char* input)
{
    char auxiliar[351];

    getString(mensaje,auxiliar);
    if(validarStringLetras(auxiliar)==1)
    {
        strcpy(input,auxiliar);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumeros(char* mensaje,char* input)
{
    char auxiliar[50];

    getString(mensaje,auxiliar);
    if(validarStringNumerico(auxiliar))
    {
        strcpy(input,auxiliar);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto num�rico flotante al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros y flotantes y 0 si no
 */
int getStringNumerosFlotantes(char* mensaje, char* input)
{
    char auxiliar[50];

    getString(mensaje,auxiliar);
    if(validarStringNumericoFlotante(auxiliar)==1)
    {
        strcpy(input,auxiliar);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n�mero ingresado por el usuario
 *
 */
int getValidInt(char* mensaje,char* mensajeError)
{
    char auxStr[256];
    int auxInt;

        if (!getStringNumeros(mensaje,auxStr))
        {
            printf ("%s\n",mensajeError);
        }
        auxInt = atoi(auxStr);

        return auxInt;
}

/**
 * \brief Solicita una opcion numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit numero minimo posible
 * \param highLimit numero maximo posible
 * \return El n�mero ingresado por el usuario
 *
 */
 int getValidIntOpcion(char* requestMessage,char* errorMessage, int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("\tERROR\nEL NUMERO DEBE SER MAYOR A %d Y MENOR A %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;
    }
}

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n�mero ingresado por el usuario
 *
 */
float getValidFloat(char* mensaje,char* mensajeError)
{
    char auxStr[256];
    float auxInt;

        if (!getStringNumerosFlotantes(mensaje,auxStr))
        {
            printf ("%s\n",mensajeError);
        }
        auxInt = atof(auxStr);

        return auxInt;
}

/**
 * \brief Solicita un texto solo de letras al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargara el string
 * \return Void
 *
 */
void getValidString(char* mensaje,char* mensajeError,char* input)
{
    while(1)
    {
        if(!getStringLetras(mensaje,input))
           {
                printf("%s\n",mensajeError);
                continue;
           }
           fflush(stdin);
           break;
    }
}

/**
 * \brief Solicita un texto alfanumerico al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargara el string
 * \return Void
 *
 */
 void getValidStringAlfaNumerico(char* mensaje,char* mensajeError, char* input)
{
    char auxStr[250];

    if(input!= NULL)
    {
        getString(mensaje,auxStr);
        if(!validarStringAlfaNumerico(auxStr))
        {
            printf("%s",mensajeError);

        }
        else
        {
            strcpy(input,auxStr);
        }
    }
}

 /**
 * \brief Genera un n�mero aleatorio
 * \param desde N�mero aleatorio m�nimo
 * \param hasta N�mero aleatorio m�ximo
 * \param iniciar Indica si se trata del primer n�mero solicitado 1 indica que si
 * \return retorna el n�mero aleatorio generado
 *
 */
 char getNumeroAleatorio(int desde, int hasta, int iniciar)
 {
     if(iniciar)
        srand(time(NULL));
     return desde + (rand()%(hasta + 1 - desde));
 }


  /**
 * \brief valida un caracter de genero
 * \param mensaje, mensaje a ser mostrado al pedir dato
 * \param mensajeError, error al no cumplirse
 * \param input, array de char donde se guardara el caracter
 * \return void
 */
 void getCaracterSexo(char* mensaje,char* mensajeError,char* input)
 {
    char sexo[13];

    do
    {
        getValidString(mensaje,mensajeError,sexo);

        if(sexo[0]!= 'f' && sexo[0] != 'm' && sexo[0]!= 'F' && sexo[0] != 'M')
        {
            system("cls");
            printf(mensajeError);
        }
        else
        {
            strcpy(input,sexo);
        }
    }while(sexo[0]!= 'f' && sexo[0] != 'm' && sexo[0]!= 'F' && sexo[0] != 'M');
 }


/**
 * \brief Solicita una edad al usuario y devuelve un int
 * \param mensaje Es el mensaje a ser mostrado
 * \return la edad ingresado por el usuario - (-1) ERROR
 *
 */
int getEdad(char* mensaje)
{
    int auxiliar;

    printf("%s",mensaje);
    scanf("%d",&auxiliar);

    if(auxiliar>99 || auxiliar<0)
    {
        auxiliar=-1;
    }
    return auxiliar;
}

/**
 * \brief Solicita un nombre al usuario y lo carga en input
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el nombre ingresado
 * \return 0 si contiene nomre, (-1) Error
 */
void getNombre(char* mensaje,char* input)
{
    char auxiliar[200];

    getString(mensaje,auxiliar);
    if(validarStringLetras(auxiliar)==0)
    {
        strcpy(input,auxiliar);
    }
}

