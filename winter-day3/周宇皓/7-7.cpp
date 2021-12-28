#include<bits/stdc++.h>
using namespace std;
const int N=1509;
struct Edge
{
    int a,b,dis;
}edge[N*2];
int n,v,m,bin[N];
bool cmp(const Edge&a,const Edge&b)
{
    return a.dis<b.dis;
}
int find(int x)
{
    if(x!=bin[x]) bin[x]=find(bin[x]);
    return bin[x];
}
int main()
{
    while(cin>>n>>v>>m)
    {
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            edge[i]={a,b,c};
        }
        sort(edge,edge+m,cmp);
        for(int i=0;i<=n;i++) bin[i]=i;
        int cnt=0,sum=0,temp=0;
        for(int i=0;i<m;i++)
        {
            int fa=find(edge[i].a),fb=find(edge[i].b);
            if(fa!=fb)
            {
                if(edge[i].a==v||edge[i].b==v)
                {
                    temp++;
                    if(temp<=2)
                    {
                        bin[fa]=fb,cnt++;
                        sum+=edge[i].dis;
                    }
                }
                else 
                {
                    bin[fa]=fb,cnt++;
                    sum+=edge[i].dis;
                }
            }
            if(cnt==n-1) break;
        }
        if(cnt==n-1) cout<<sum<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
