#include<iostream>
using namespace std;

long long function(long long a,long long b,long long c)
{
    if(b==1) return a;
    long long x1,x2;
    x1=b/2;
    x2=b-x1;
    return (function(a,x1,c)%c)*(function(a,x2,c)%c);
} 

int main()
{
    int a,b,c,n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        cout<<function(a,b,c)%c<<"\n";
    }
    return 0;
}