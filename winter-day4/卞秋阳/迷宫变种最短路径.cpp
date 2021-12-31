#include<bits/stdc++.h>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int m,n,sx,sy,ex,ey;
int Map[1000][1000];
bool book[1000][1000];
struct Node
{
	int x;
	int y;
	int sum;
	Node* p;
};
queue<Node*>q;
void search(Node* from,Node* to); 
int main()
{
	cin>>m>>n;
	cin>>sx>>sy>>ex>>ey;
	Node s,e;
	s.x=sx;s.y=sy;e.x=ex;e.y=ey;
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	cin>>Map[i][j];
	search(&s,&e);
}
void search(Node* from,Node* to)
{
	int Min=65535;
	Node* ans=new Node;
	from->p=NULL;
	q.push(from);
	while(!q.empty())
	{
		Node* temp=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=temp->x+dx[i],yy=temp->y+dy[i];
			if(Map[xx][yy]!=-1&&!book[xx][yy])
			{
				book[xx][yy]=1;
				Node* t=new Node;
				t->x=xx;t->y=yy;t->p=temp;t->sum+=Map[xx][yy];
				q.push(t);
			}
		}
		if(temp->x==to->x&&temp->y==to->y&&temp->sum<Min)
		{
			Min=temp->sum;
			ans=temp;
		}
	}
	while(ans->p!=NULL)
	{
		cout<<"("<<ans->x<<" "<<ans->y<<")";
		ans=ans->p;
	}
	cout<<"("<<from->x<<" "<<from->y<<")";
}
