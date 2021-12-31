#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a,b,cnt[100001];
bool flag[1001][1001];
char num[1001][1001];
void dfs(int x,int y,int z,int t)
{
    if (x<0||x>=n||y<0||y>=n||flag[x][y]!=0||num[x][y]-'0'!=z)
	{
	    return;
	}
	else
	{
		flag[x][y]=1;
		cnt[t]++;
        dfs(x+1,y,!z,t);
	    dfs(x-1,y,!z,t);
	    dfs(x,y+1,!z,t);
	    dfs(x,y-1,!z,t);
	}
    return;
}
int main()
{
    int i,j;
	scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
		scanf("%s",&num[i]);   	
    }
    memset(flag,0,sizeof(flag));
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
		a--;
		b--;
		if(flag[a][b]==0)
		{
			dfs(a,b,num[a][b]-'0',i);
		}
        else
        {
        	cnt[i]=cnt[flag[a][b]];
		}
    }
    for(i=1;i<=m;i++)
    {
	    printf("%d\n",cnt[i]);
	}   
    return 0;
}
