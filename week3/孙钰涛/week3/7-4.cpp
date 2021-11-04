#include<bits\stdc++.h>
using namespace std;
char Map[1001][1001];
int mem[1001][1001],Count=0,result[100001],n;
int directionx[4]={1,0,-1,0};
int directiony[4]={0,1,0,-1};


void DFS(int x,int y,int flag,int i)
{
    if(x==0 || y==0 || x==n+1 || y==n+1 || mem[x][y]!=-1 || flag!=Map[x][y]) return ;
    mem[x][y]=i;
    result[i]++;
    for(int o=0;o<4;o++) DFS(x+directionx[o],y+directiony[o],'0'+'1'-flag,i);
}

int main()
{
    int m,x,y;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>Map[i][j];
    memset(mem,-1,sizeof(mem));
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if(mem[x][y]==-1) DFS(x,y,Map[x][y],i);
        else result[i]=result[mem[x][y]];
    }
    for(int i=1;i<=m;i++)
    {
        cout<<result[i];
        if(i!=m) cout<<"\n";
    }
    return 0;
}
