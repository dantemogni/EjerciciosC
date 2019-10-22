#include "persona.h"
int main()
{
    ePersona* pPersona;
    //pPersona=new_persona();
    pPersona=newPersonParameters(100,40,1.84);

    if(mostrarPersona(pPersona)!=1)
    {
        printf("error al mostrar");
    }
    deletePerson(pPersona);
    return 0;
}
