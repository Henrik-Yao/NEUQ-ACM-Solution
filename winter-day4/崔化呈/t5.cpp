#include<bits/stdc++.h>
using namespace std;
int show[1000][1000];
bool vis[1000][1000];
int mx[]={1,-1,0,0};
int my[]={0,0,1,-1};
typedef struct node
{
	int x,y,sum;
	node* pre;
};
void find(node* fr,node* to)
{
	int minn=65535;
	node* ans=new node;	
	fr->pre=NULL;
	queue<node*>q;
	q.push(fr);
	while(!q.empty())
	{
		node* t=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=t->x+mx[i];
			int yy=t->y+my[i];
			if(show[xx][yy]!=-1&&!vis[xx][yy])
			{
				vis[xx][yy]=1;
				node* tt=new node;
				tt->x=xx;tt->y=yy;
				tt->pre=t;
				tt->sum+=show[xx][yy];
				q.push(tt);
			}
		}
		if(t->x==to->x&&t->y==to->y&&t->sum<minn)
		{
			minn=t->sum;
			ans=t;
		}
	}
	while(ans->pre!=NULL)
	{
		printf("(%d %d)",ans->x,ans->y);
		ans=ans->pre;
	}
	printf("(%d %d)",fr->x,fr->y);
}
int main()
{
	int m,n,sx,sy,ex,ey;
	scanf("%d%d",&m,&n);
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	node s,e;
	s.x=sx;s.y=sy;e.x=ex;e.y=ey;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&show[i][j]);
		}
	}	
	find(&s,&e);
	
	return 0;
}
