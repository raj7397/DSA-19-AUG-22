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
        Complex()
        {
            cout<<"default contrucot: "<<endl;
        }
        Complex(Complex &c)
        {
            this->re = c.re;
            this->img = c.img;
            cout<<"copy "<<endl;
        }
        Complex operator + (Complex &c)
        {
            Complex t;
            t.re = this->re + c.re;
            t.img = this->img + c.img;
            return t;
          /*this->re =   this->re + c.re;
           this->img=  this->img +c.img;
            this->show();
            return *this;*/
        }
        void show()
        {
            cout<<"re: "<<(this->re)<<" img: "<<(this->img)<<endl;
            
        }
 //       friend void display(Complex &);
};
/*void display(Complex &c)
{
    cout<<"re: "<<(c.re)<<endl;
}*/
int main()
{
    Complex c1(3,4), c2(5,7),c3;
    c1+c2;
    c1.show();
   // display(c1);
}