#include <iostream>
using namespace std;

int p(long long  a,long long  b,long long  c)
{
    int ans=1;
    while(b>0)
    {
        if(b&1==1) ans=ans*a%c;//这里是用位运算判断是否为奇数 
        a=a*a%c;
        b=b>>1;
    }
   
    cout<<ans<<endl;
}

int main ()
{
    int m;
    cin>>m;
    long long  a,b,c;
    while(m--)
    {
        cin>>a>>b>>c;
        p(a,b,c);
    }
    return 0;
}
