#include "sum.h"
#include "sub.h"
#include <stdio.h>
#include <string.h>

int main()
{
    int res1 = sum(20,30);
    int res2 = sub(300,100);
    printf("sum: %d sub: -> %d\n",res1,res2);
}