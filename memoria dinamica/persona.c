#include "persona.h"
ePersona* new_persona(){
    //ePersona miPersona={100,40,1.81};
    //return &miPersona;
    ePersona* miPersona;
    miPersona = calloc(sizeof(ePersona),1); //memori alocation  (Reserva espcaio en memoria)
     return miPersona ;
}

int mostrarPersona(ePersona* unaPersona)
{
    int ret;
    if(unaPersona!= NULL)
        {
            printf("%d--%d--%f",unaPersona->edad,unaPersona->legajo,unaPersona->altura);
            ret=1;
        }
    return ret;
}
int deletePerson(ePersona* unaPersona)
{
    int ret;
    if(unaPersona!= NULL)
        {
           free(unaPersona);
           ret=1;
        }
    return ret;
}
ePersona* newPersonParameters(int legajo,int edad,float altura)
{
    ePersona* unaPersona=(ePersona*)malloc(sizeof(ePersona));
    if(unaPersona!=NULL)
    {
    unaPersona->edad = edad;
    unaPersona->legajo = legajo;
    unaPersona->altura = altura;
    }
    return unaPersona;
}
