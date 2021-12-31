//O(nlog(logn))
#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int PRI = 1e8;
bool v[PRI];
void prime(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(v[i])
            continue;
        // cnt++;
        for(int j=i;j<=n/i;j++)
            v[i*j] = true;
    }
}
int main()
{
    int n = read();
    v[1] = true;
    prime(100005);

    for(int i=1;i<=n;i++)
    {
        int tp = read();
        if(!v[tp])cout<<tp<<" ";
    }
}