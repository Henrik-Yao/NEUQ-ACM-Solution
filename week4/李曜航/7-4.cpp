#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int c;
int pow(int a, int b)
{
    if(b==1) return a;
    if(b%2==0)
    {
        int tmp = pow(a,b/2);
        return tmp%c*tmp%c;
    }
    if(b%2==1)
    {
        int tmp = pow(a,b/2);
        return tmp%c*tmp%c*a%c;
    } 
}
signed main()
{
    int t = read();
    while(t--)
    {
        int a = read(), b = read();
        c = read();
        // cout<<pow(a,b);
        printf("%d\n",pow(a,b));
        
    }
    

    return 0;
}