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
const int N = 10005;
int a[N], f[10000000];
int main()
{
    int t = read();
    while(t--)
    {
        int n = read();
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            a[i] = read();
        }
        
        int max_ = 0;//记录答案
        for(int i=1;i<=n;i++)
        {
            int mx = 0;
            for(int j = 1;j<a[i];j++)
            {
                mx = max(mx, f[j]);
            }
            f[a[i]] = mx + 1;
            max_ = max(max_,f[a[i]]);
        }
        if(t)
            cout<<max_<<endl<<endl;
        else
            cout<<max_<<endl;
    }



}