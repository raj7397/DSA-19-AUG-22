#include <stdio.h>
#include <stdlib.h>

//polymorphism with function pointer in c
int sum(int a,int b)
{
    return a+b;
}
int sub(int a,int b)
{
    return a-b;
}
int mult(int a,int b)
{
    return a*b;
}
int divide(int a,int b)
{
    return a/b;
}
typedef int (*op)(int,int);
typedef struct calculate{
    op sum;
    op sub;
    op mult;
    op div;
} Cal;

int main(int argc, char **argv)
{
    Cal *simplify = (Cal *)malloc(sizeof(Cal)) ;
    simplify->sum = sum;
    simplify->sub = sub;
    simplify->mult = mult;
    simplify->div = divide;
    int res1 = simplify->sum(10,20);
    int res2 = simplify->sub(10,20);
    int res3 = simplify->mult(10,20);
    int res4 = simplify->div(30,15);
    printf("res1: %d , res2: %d, res3: %d , res4: %d\n",res1,res2,res3,res4);
}