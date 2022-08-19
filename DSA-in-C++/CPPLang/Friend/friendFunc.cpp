#include <iostream>
#include <string>

using namespace std;

class Complex{
    int re;
    int img;
    public:
        Complex(int re,int img)
        {
            this->re = re;
            this->img = img;
        }
        friend void display(Complex &);
};
void display(Complex &c)
{
    cout<<"re: "<<(c.re)<<endl;
}
int main()
{
    Complex c1(3,4);
    display(c1);
}