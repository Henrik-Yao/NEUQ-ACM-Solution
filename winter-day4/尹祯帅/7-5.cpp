#include<bits/stdc++.h>
using namespace std;
struct mg
{
	int x,y;
	int sum;
	mg *p;
};
queue <mg*> q;
mg *from = new mg,*to = new mg;
bool jud[1001][1001];
int tu[1001][1001];
int minn = 65535;
int fx[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void dfs(mg *from,mg *to)
{
	mg *ans = new mg;
	q.push(from);
	while(!q.empty())
	{
		mg *temp =new mg;
		temp = q.front();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int x1=temp->x+fx[i][0],y1 = temp->y+fx[i][1];
			if(!jud[x1][y1])
			{
				jud[x1][y1] = 1;
				mg *tmp = new mg;
				tmp->x = x1;
				tmp->y = y1;
				tmp->sum += tu[x1][y1];
				tmp->p = temp;
				q.push(tmp);
			}
		}
		if(temp->x==to->x&&temp->y==to->y&&temp->sum<minn)
		{
			ans = temp;
			minn = temp->sum;
			
		}
	}
	cout<<"("<<ans->x<<" "<<ans->y<<")";
	ans=ans->p;
	while(ans->p!=NULL)
	{
		cout<<"("<<ans->x-1<<" "<<ans->y-1<<")";
		ans=ans->p;
	}
	cout<<"("<<from->x<<" "<<from->y<<")";
}
int main() 
{
	int m,n;
	cin>>m>>n;
	cin>>from->x>>from->y;
	from->p = NULL;
	cin>>to->x>>to->y;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		cin>>tu[i][j];
		if(tu[i][j]==-1) jud[i][j]=1;
	}
	dfs(from,to);
	return 0;
}
