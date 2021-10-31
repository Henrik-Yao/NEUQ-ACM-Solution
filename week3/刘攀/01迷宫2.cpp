#include<iostream>
using namespace std;
int n,m,x,y;
int a[1001][1001];
char ch[1010][1010];
int judge[10000][10000];
int sum;
int pastx[10000][10000]={0};
int pasty[10000][10000]={0};
int nowx, nowy;
void dfs(int x, int y);
int main()
{
    int i,j;
 
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {   
            cin>>ch[i][j];
            a[i][j]=ch[i][j]-48;
        }
    }
    
    for(i=1;i<=n;i++)
    	for(j=1;j<=n;j++)
            judge[i][j]=-1;
    
    for(i=1;i<=m;i++)
    {
        sum=0;
        cin>>x>>y;
        
        if(judge[pastx[x][y]][pasty[x][y]]>0) 
        {
            cout<<judge[pastx[x][y]][pasty[x][y]];
            if(i!=m) cout<<endl;
            continue;
        }
        nowx=x;
        nowy=y;
        dfs(x,y);
        cout<<sum;
        if(i!=m) cout<<endl;
        judge[x][y]=sum;
        pastx[x][y]=x;
        pasty[x][y]=y;
    }
 
    return 0;
}
 
inline void dfs(int x, int y)
{
    int dirx[4]={1,-1,0,0,},diry[4]={0,0,1,-1};
 	int i;   
    if(x>n||x<1||y>n||y<1)
        return;
    if(judge[x][y]!=-1)
        return;
    sum++;
    pastx[x][y]=nowx;
    pasty[x][y]=nowy;
    judge[x][y]=0;
    
    for(i=0;i<4;i++)
    {
        if(a[x+dirx[i]][y+diry[i]]!=a[x][y])
            dfs(x+dirx[i],y+diry[i]);
    }
}
