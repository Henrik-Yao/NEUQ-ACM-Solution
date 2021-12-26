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
int main()
{
    bool vis[1005] = {0};
    int n = read(), m = read(), k = read();
    // int n = 6, m = 3, k = 5;
    int cnt = n;
    int pc = 1;
    bool rev = true;
    while(--cnt)
    {
        if(rev==true)
        {
            for(int i=1;i<m;i++)
            {
                while(vis[pc]){pc--;if(pc<1)pc+=n;}
                pc--;if(pc<1)pc+=n;
            }
            while(vis[pc]){pc--;if(pc<1)pc+=n;}
                vis[pc] = true;cout<<pc<<" ";
            while(vis[pc]){pc--;if(pc<1)pc+=n;}
            // cout<<":"<<pc<<" ";
            rev = false;
        }
        else if(rev==false)
        {
            for(int i=1;i<k;i++)
            {
                while(vis[pc]){pc++;if(pc>n)pc-=n;}
                pc++;
                if(pc>n)pc-=n;
            }
            // cout<<"pc"<<pc<<endl<<"fucku";
            while(vis[pc]){pc++;if(pc>n)pc-=n;}
                vis[pc] = true;cout<<pc<<" ";
            while(vis[pc]){pc++;if(pc>n)pc-=n;}
            // cout<<":"<<pc<<" ";
            rev = true;
        }
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]) cout<<i<<" ";
    return 0;
    
}


