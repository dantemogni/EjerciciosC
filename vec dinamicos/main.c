#include <stdio.h>
#include <stdlib.h>

int main()
{
    ///putro a void void* significa un puntero a cualquier cosa
    int* miVector;
    int x;
    int* auxMiVector;

    miVector= (int*) malloc(sizeof(int)*5);
    if(miVector!=NULL)
    {
        for(x=0;x<5;x++)
        {
            *(miVector+x)=x+1;
        }
            for(x=0;x<5;x++)
            {
                printf("%d\n",*(miVector+x));
            }
            printf("agrandando espacio\n");

        auxMiVector=(int*)realloc(miVector,sizeof(int)*10);
        if(auxMiVector!=NULL);
        {
         miVector=auxMiVector;
         for(x=5;x<10;x++)
         {
             *(miVector+x)=x+1;

         }
            for(x=0;x<10;x++)
            {
                printf("%d\n",*(miVector+x));
            }
        }
        printf("reduciendo espacio \n");
        realloc(miVector,sizeof(int)*4);
           for(x=0;x<4;x++)
            {
                printf("%d\n",*(miVector+x));
            }

    }
    else
    {
    printf("no encopnre espacio\n");
    }
    return 0;
}
