#include <iostream>
#include <string>
#include <map>

using namespace std;
class myComp{
    public:
        bool operator()(int a, int b)
        {
            if(a > b)
                return true;
            return false;
        }
};
int main()
{
    map<int,int,myComp> hm;
    hm.insert({10,100});
    hm.insert({30,300});
    hm.insert({40,400});
    for(auto ele: hm)
    {
        cout<<"first: "<<ele.first<<" second: "<<ele.second<<endl;
    }
}