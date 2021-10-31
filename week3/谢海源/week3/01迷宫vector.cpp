#include<bits/stdc++.h>
using namespace std;
const int fi[4]={-1, 0, 1, 0};
const int fj[4]={0, -1, 0, 1};
bool a[1005][1005]={};//记录棋盘
bool b[1005][1005]={};//检验是否走过
int s[1005][1005]={};
int sum=0;
int n,m;
vector<pair<int, int>>save;
void dfs(int i,int j)
{
	b[i][j]=1;
	sum++;
	save.push_back(make_pair(i, j));
	for(int k=0;k<4;k++)
    {
        int xi=i+fi[k];
        int xj=j+fj[k];
        if(xi<1||xi>n||xj<1||xj>n||b[xi][xj]||a[i][j]+a[xi][xj]!=1) continue;
        dfs(xi,xj);
    }
}
int main()
{   
    memset(s,0,sizeof(s));
	cin>>n>>m;
	char str[n];
	for(int i=1;i<=n;i++)//输入
	{
		scanf("%s",str);
		for(int j=1;j<=n;j++)
		{
			a[i][j]=str[j-1]-'0';
		}
	}
	for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(b[i][j]) continue;
        	b[i][j]=1;s[i][j]=1;sum=0;save.clear();
            dfs(i,j);//未搜索过则搜索
            for(auto k: save) s[k.first][k.second]=sum;//将走过的点全部记录sum
        }
	int i,j;
	while(m--)
	{
		scanf("%d %d",&i,&j);
		printf("%d\n",s[i][j]);
	}
	return 0;	
}
