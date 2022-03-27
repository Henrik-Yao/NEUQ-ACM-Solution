#include<iostream>
#include<string>
using namespace std;

string fun()
{
    int n;
    char c;
    string Str,s;
    while(cin>>c)
    {
        if(c=='[')
        {
            cin>>n;
            s=fun();
            while(n--) Str=Str+s;
        }
        else if(c==']') return Str;
        else Str=Str+c;
    }
    return Str;
}
int main()
{
    cout<<fun();
    return 0;
}