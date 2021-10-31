#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int read()
{
    char c = getchar(); int f = 1, x = 0;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=c-'0'+x*10;c=getchar();}
    return f*x;
}
ll a[10010];
ll add[10010];
ll _max;
int main()
{
    int n = read();
    bool neg = true;
    for(int i=1;i<=n;i++)
    {
        a[i] = read();
        if(a[i]>0) neg = false;
        add[i] = max(add[i-1]+a[i],a[i]);
        _max = max(add[i],_max);
    }
    if(neg) {cout<<"0";return 0;}
    cout<<_max;
    return 0;
}