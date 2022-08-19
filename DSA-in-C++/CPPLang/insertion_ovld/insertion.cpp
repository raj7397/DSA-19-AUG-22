#include <iostream>
#include <string>

using namespace std;
class Test{
    int x;
    int y;
    int z;
    public:
        Test(int x,int y,int z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            cout<<"constructor: "<<endl;
        }
        Test()
        {

        }
    void show()
    {
        cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<endl;
    }

    friend istream& operator >> (istream & in, Test &t);
    friend ostream & operator << (ostream &out , Test &t)
    {
        out<<"x :"<<t.x<<" y: "<<t.y<<" z: "<<t.z<<endl;
        return out;
    }

};
istream& operator >> (istream & in, Test &t)
{
    in>>t.x>>t.y>>t.z;
    return in;


 //   return in;
}
int main()
{
    Test t(10,20,30);
    Test t1;
    Test t2;
    t.show();
    cin>>t1>>t2;
    cout<<"showing t: "<<endl;
    t.show();
    cout<<"t1 show: "<<endl;
    t1.show();
    cout<<"showing t2: "<<endl;
    t2.show();
    cout<<t<<t1;
    
}