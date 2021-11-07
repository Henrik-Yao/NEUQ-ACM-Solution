#include<iostream>
using namespace std;

long long fuc(long long q,long long w,long long e)
{
    if(w==1) 
    {
        return q;
    }
    long long x1,x2;
    x1=w/2;
    x2=w-x1;
    return (fuc(q,x1,e)%e)*(fuc(q,x2,e)%e);
} 

int main()
{
    int a,b;
    
    int c,n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        cout<<fuc(a,b,c)%c<<"\n";
    }
    return 0;
}