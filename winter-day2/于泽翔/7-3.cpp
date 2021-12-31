#include<bits/stdc++.h>
using namespace std;

struct lnode
{
	int data;
	lnode* prior;
	lnode* next; 
};
int main()
{
	int n, m, k;
	cin>>n>>m>>k;
	
	lnode* p, *q, *g;
	p=new lnode;
	g=q=p;
	p->data=1, p->next=p;
	
	for(int i=2; i<=n; i++)
	{
		q=(q->next=new lnode);
		q->prior=g;
		q->data=i;
		q->next=p;
		g=g->next;
	}
	p->prior=g;
	q=p;
	
	while(q!=q->next)
	{
		if(m==1)
		{
			cout<<q->data;
			q->next->prior = q->prior;
			q->prior->next = q->next;
			q = q->prior;
		}
		else
		{
			for(int i=2; i<m; i++)
				q=q->prior;
			cout<<q->prior->data<<' ';
			q->prior=q->prior->prior;
			q->prior->next=q;
			q=q->prior;
		}
		if(k==1)
		{
			cout<<q->data;
			q->next->prior = q->prior;
			q->prior->next = q->next;
			q=q->next;
		}
		else
		{
			for(int i=2; i<k; i++)
				q=q->next;
			cout<<q->next->data<<' ';
			q->next=q->next->next;
			q->next->prior=q;
			q=q->next;
		}
	}
	if(n%2==1)
		cout<<p->data<<' ';
	
	return 0;
}