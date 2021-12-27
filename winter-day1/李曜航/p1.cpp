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
const int N = 1e7;
ll a[N];
int n, q;

int lowbit(int x)
{
  return x&(-x);
}
void update(int i,int k)//在i位置加上k
{    
    while(i <= n)
    {
		a[i] += k;
		i += lowbit(i);
    }
}

ll getsum(int i)
{
	ll res = 0;
	while(i > 0)
    {
		res += a[i];
		i -= lowbit(i);
	}
	return res;
}

int main()
{
    n = read(), q = read();
    for(int i=1;i<=n;i++)
        update(i,read());
    while(q--)
    {
        int op = read();
        if(op==1)
        {
            int ai = read(), x = read();
            update(ai,x);
        }
        if(op==2)
        {
            int l = read(), r = read();
            cout<<getsum(r)-getsum(l-1)<<endl;
        }
    }
    return 0;
}

