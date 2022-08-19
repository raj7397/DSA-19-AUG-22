#include <iostream>
//#include <string.h>
#include <string>
//#include <string>
#include <vector>
#include <sstream>
using namespace std;

/*int main()
{
     
    string line = "GeeksForGeeks is a must try";
     
    // Vector of string to save tokens
    vector <string> tokens;
     
    // stringstream class check1
    stringstream check1(line);
     
    string intermediate;
     
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
     
    // Printing the token vector
    for(int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << '\n';
}*/
int main()
{
    string line = "This is Rajkalash Rajbhar, and My father name is, Ramesh Rajbhar, and my father was doctor";
    stringstream check1(line);
    vector<string>token;
    string temp;
    while(getline(check1,temp,','))
    {
        token.push_back(temp);
        cout<<"token: "<<temp<<endl;
    }
    for(int i = 0; i < token.size();i++)
    {
        cout<<token[i] <<" ";
    }
    cout<<endl;
  
  /*  string ch = "y";
    string str;
    while(ch == "y")
    {
        cout<<"Enter name: "<<endl;
        getline(cin>>ws,str);
        cout<<"name: "<<str<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>ch;
    }
    string str;
    cin>>str;
    cout<<"str: "<<str<<endl;
    getline(cin,str);
    cout<<"str: "<<str<<endl;
    string str = to_string(3.143434343);
    //cout<<"str: "<<str<<endl;
    int i;
    long l;
    long long ll;
    float f;
    double d;
    cout<<sizeof(int)<<endl;
    cout<<sizeof(long)<<endl;
    cout<<sizeof(long long)<<endl;
    cout<<sizeof(float)<<endl;
    cout<<sizeof(double)<<endl;
    cout<<sizeof(long double)<<endl;
   const char * name2 = "Ramesh Rajbhar";
 char *name = new char[2];
 strcpy(name, "Rajkalash");
 memcpy(name,name2,sizeof(name2));
 char * c = name;
 /*while(*c != '\0')
 {
     cout<<"*c: "<<*c;
     c++;
 }
 cout<<"name: "<<name<<endl;*/   
}