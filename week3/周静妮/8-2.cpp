#include <iostream>
#include <cstring>
using namespace std;
void f(string a,string b,string c,int n)
{
    if(n==1) cout<<a<<"->"<<c<<endl;
    else 
    {
        f(a,c,b,n-1);
        cout<<a<<"->"<<c<<endl;
        f(b,a,c,n-1);
    }
}

int main()
{
    int n;
    string a,b,c;
    cin>>n;
    cin>>a>>b>>c;
    f(a,b,c,n);
    return 0;
}
