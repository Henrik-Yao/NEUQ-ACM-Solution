#include<iostream>
using namespace std;

void hano(int n,char a,char b,char c)
{
    if(n == 1)
    {
        cout<<a<<"->"<<c<<"\n";
    }
    else
    {
        hano(n-1,a,c,b);
        cout<<a<<"->"<<c<<"\n";
        hano(n-1,b,a,c);
    }
}

int main()
{
    double n;
    cin>>n;
    char c1,c2,c3;
    cin>>c1>>c2>>c3;
    hano(n,c1,c2,c3);
    return 0;
}