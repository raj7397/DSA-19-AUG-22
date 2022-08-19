#include <iostream>
#include <cstring>


using namespace std;

int main(int argc, char ** argv)
{
    const char *name = "Rajkalash";
    char *target = strdup(name);
    cout<<"name: "<<name<<" target: "<<target<<endl;
}