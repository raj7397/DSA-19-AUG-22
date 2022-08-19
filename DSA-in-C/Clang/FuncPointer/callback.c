#include "reg_callback.h"
//#include "reg_callback.c"
#include <stdio.h>
#include <string.h>
void display()
{
    printf("Displaying Rajkalsh Rajbhar\n");
}
int main()
{
    callback_ptr my_callback = display;
    reg_callback(my_callback);
}