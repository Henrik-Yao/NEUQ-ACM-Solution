#include <bits/stdc++.h>
using namespace std;
int mp[1000][1000];
bool vis[1000][1000];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int m,n,a1,b1,a2,b2;
int minn=65535;
struct ax{
	int x,y,sum;
	ax *p;
};
queue<ax*> q;
void bfs(ax *from,ax *to)
{
	ax* ans=new ax;
	from->p=NULL;
	q.push(from);
	while(!q.empty())
	{
		ax *tmp=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=tmp->x+dx[i],yy=tmp->y+dy[i];
			if(mp[xx][yy]!=-1 && !vis[xx][yy])
			{
				vis[xx][yy]=1;
				ax *t=new ax;
				t->x=xx,t->y=yy;t->p=tmp;t->sum+=mp[xx][yy];
				q.push(t);
			}
		}
		if(tmp->x==to->x&&tmp->y==to->y&&tmp->sum<minn)
		{
			minn=tmp->sum;
			ans=tmp;
		}
	}
	while(ans->p!=NULL)
	{
		cout<<"("<<ans->x<<" "<<ans->y<<")";
		ans=ans->p;
	}
	cout<<"("<<from->x<<" "<<from->y<<")";
}
int main(){
	cin>>m>>n;
	cin>>a1>>b1>>a2>>b2;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>mp[i][j];
	ax from,to;
	from.x=a1,from.y=b1;
	to.x=a2,to.y=b2;
	bfs(&from,&to);
    return 0;    
}

