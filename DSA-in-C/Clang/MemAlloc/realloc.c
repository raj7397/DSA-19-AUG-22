#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fun()
{
    int a = 20;
    
}

int main()
{
    int *ptr = malloc(5*sizeof(int));
    for(int i = 0; i < 5;i++)
    {
        ptr[i] = 10*(i+1);
    }
    int *ptr2 = realloc(ptr, 10*sizeof(int));
    printf("ptr1\n");
    for(int i = 0; i < 5;i++)
    {
        printf("%d ",ptr[i]);
    }
    printf("\n");
    for(int i = 0; i < 10;i++)
    {
        printf("%d ",ptr2[i]);
    }
}
