#include<bits/stdc++.h>
using namespace std;
struct node
{
	int n;
	node* pre;
	node* nex;	
};
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	node *curv,*prev,*head;
	head=new node;
	head->nex=head;
	head->pre=head;
	prev=head;
	for(int i=1;i<=n;i++)
	{
		curv=new node;
		curv->n=i;
		prev->nex=curv;
		curv->pre=prev;
		prev=curv;
	}
	curv->nex=head->nex;
	head->nex->pre=curv;
	curv=curv->nex;
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			for(int i=1;i<k;i++)
			{
				prev=curv;
				curv=curv->nex;
			}
			cout<<curv->n<<' ';
			prev->nex=curv->nex;
			curv->nex->pre=prev;
			delete curv;
			curv=prev->nex;
		}
		else
		{
			for(int i=1;i<m;i++)
			{
				prev=curv;
				curv=curv->pre;
			}
			cout<<curv->n<<' ';
			prev->pre=curv->pre;
			curv->pre->nex=prev;
			delete curv;
			curv=prev->pre;
		}
	}
	return 0;
}
