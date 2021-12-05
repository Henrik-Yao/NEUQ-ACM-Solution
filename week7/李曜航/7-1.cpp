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
map <string,string> mp;
int main()
{
    int n = read(), m = read();
    string a, b;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        mp[b] = a;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a;
        if(mp.count(a)==0)
        {
            printf("eh\n");
        }
        else
        {
            cout<<mp[a]<<endl;
        }
    }
    return 0;
}