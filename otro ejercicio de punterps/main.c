#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pEntero= (int*)calloc(sizeof(int),4);
    int i;
      for (i=0;i<5;i++)
    {
        printf("%d\n",*(pEntero+3));
    }
    free(pEntero);
}
