#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
bool v[50000005];
bool isprime(int x)
{
    if(x<=50000000){if(!v[x]) return true;else return false;}
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0) return false;
    return true;
}
void aishi()
{
    for(int i=2;i<=50000000;i++)
    {
        if(v[i])
            continue;
        for(int j=i;j<=50000000/i;j++)
            v[i*j] = true;
    }

}
int main()
{
    aishi();
    int n = read();
    while(n--)
    {
        int tp = read();
        if(isprime(tp)) {printf("1\n");continue;}
        else if(tp%2==0) {printf("2\n");continue;}
        else if(isprime(tp-2)) {printf("2\n");continue;}
        else printf("3\n");
    }
    

    
}