#include<bits/stdc++.h>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int g[1001][1001];
bool visit[1001][1001];
int fromx,fromy,tox,toy,mmin=100000;
int cnt=0;
vector<int>path;
string way;

void dfs(int x,int y,int len)
{
    if(cnt>9999) return ;
    if(x==tox && y==toy)
    {
        string str="";
        for(int i=path.size()-1;i>=0;i=i-2)
            str=str+'('+char(path[i-1]+'0')+','+char(path[i]+'0')+')';
        if(len<mmin)
        {
            mmin=len;
            way=str;
        }
        return ;
    }
    for(int i=0;i<4;i++)
    {
        int a=x+dx[i];
        int b=y+dy[i];
        if(g[a][b]!=-1 && visit[a][b]==0)
        {
            path.push_back(a);
            path.push_back(b);
            visit[a][b]=1;
            dfs(a,b,len+g[x][y]);cnt++;
            visit[a][b]=0;
            path.pop_back();
            path.pop_back();
        }
    }
    return ;
}

int main()
{
    int m,n;
    memset(g,0,sizeof(g));
    memset(visit,0,sizeof(visit));
    cin>>m>>n;
    cin>>fromx>>fromy>>tox>>toy;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>g[i][j];
    path.push_back(fromx);
    path.push_back(fromy);
    visit[fromx][fromy]=1;
    dfs(fromx,fromy,0);
    cout<<way;
    return 0;
}