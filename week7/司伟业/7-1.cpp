#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
int read()
{
    int res=0,x=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
        x=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        res=res*10+(c-'0');
        c=getchar();
    }
    return res*x;
}
int n,m;
map<string,string>q;
map<string,int>s;
int main()
{
    string a,b;
    n=read();m=read();
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        q[b]=a;
        s[b]=1;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a;
        if(s[a]==0) puts("eh");
        else cout<<q[a]<<endl;
    }
    return 0;
}
