#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidad.h"
#include "funcionesGet.h"

Entidad* entidad_new()
{
    return (Entidad*)malloc(sizeof(Entidad));
}

void entidad_delete(Entidad* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

int entidad_setDominio(Entidad* this, char* dominio)
{
    int retorno=-1;

    if(this!=NULL && dominio!=NULL)
    {
        strcpy(this->dominio, dominio);
        retorno=0;
    }
    return retorno;
}

int entidad_getDominio(Entidad* this,char* dominio)
{
    int retorno=-1;

    if(this!=NULL && dominio!=NULL)
    {
        strcpy(dominio,this->dominio);
        retorno=0;
    }
    return retorno;
}


int entidad_setId(Entidad* this, int id)
{
    int retorno=-1;
    static int idAutoincrementable=0;

    if(this!=NULL)
    {
        if(idAutoincrementable>=0)
        {
            idAutoincrementable++;
            this->idUnico= idAutoincrementable;
        }
        retorno=0;
    }
    return retorno;
}

int entidad_getId(Entidad* this, int* id)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *id= this->idUnico;
        retorno=0;
    }
    return retorno;
}

int entidad_setTipo(Entidad* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        if(this->dominio[0]>='0' && this->dominio[0]<='9')
        {
            if(this->dominio[1]>='0' && this->dominio[1]<='9')
            {
                if(this->dominio[2]>='0' && this->dominio[2]<='9')
                {
                    this->tipo= 'm';
                    retorno=0;
                }
            }
        }
        else
        {
            this->tipo= 'a';
            retorno=0;
        }
    }
    return retorno;
}

int entidad_setAnio(Entidad* this,int anio)
{
    int retorno=-1;

    if(this!= NULL)
        if(anio>0)
        {
            this->anio= anio;
            retorno= 0;
        }

    return retorno;
}

int entidad_getAnio(Entidad* this,int* anio)
{
    int retorno=-1;

    if(this!= NULL)
    {
        *anio= this->anio;
        retorno= 0;
    }
    return retorno;
}


Entidad* entidad_newParametros(char* idStr,char* dominioStr,char* anioStr,char* tipoStr)
{
    Entidad* entidadAux;

    entidadAux= entidad_new();

    if(validarInt(idStr)==0)
    {
        if(validarString(dominioStr)==0)
        {
            if(validarString(tipoStr)==0)
            {
                if(validarInt(anioStr)==0)
                {

                    entidad_setDominio(entidadAux,dominioStr);
                    entidad_setDominio(entidadAux,tipoStr);
                    entidad_setAnio(entidadAux,atoi(anioStr));
                    entidad_setId(entidadAux,atoi(idStr));
                    return entidadAux;
                }
            }
        }
    }
    entidad_delete(entidadAux);

    return NULL;
}
