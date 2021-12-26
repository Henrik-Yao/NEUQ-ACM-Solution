#include <bits/stdc++.h>
using namespace std;

struct linknode
{
	int data;
	struct linknode* next;
	struct linknode* prev;
};

int main()
{
	int n,m,k;
    cin>>n>>m>>k;

	struct linknode* p,*q,*g;
	p = (struct linknode*)malloc(sizeof(struct linknode));
	g=q=p;
	p->data = 1;
	p->next = p;
	for (int i=2;i<=n;i++)
	{
		q = (q->next = (struct linknode*)malloc(sizeof(struct linknode)));
        q->data=i;
		q->prev=g;
		q->next=p;
		g=g->next;
	}
	p->prev=g;
	q=p;

	while (q!=q->next)
	{

		if (m == 1)
		{
			cout<<q->data<<' ';
			q->next->prev = q->prev;
			q->prev->next = q->next;
			q = q->prev;
		}
		else
		{
			for (int i = 2; i < m; i++)
				q = q->prev;
			cout<<q->prev->data<<' ';
			q->prev = q->prev->prev;
			q->prev->next = q;
			q = q->prev;
		}

		if (k == 1)
		{
			cout<<q->data<<' ';
			q->next->prev = q->prev;
			q->prev->next = q->next;
			q = q->next;
		}
		else
		{
			for (int i=2; i<k;i++)
				q = q->next;
			cout<<q->next->data<<' ';
			q->next = q->next->next                                                                                                    ;
			q->next->prev = q;
			q = q->next;
		}
	}

	if (n%2==1)
		cout<<p->data<<' ';

	return 0;
}
