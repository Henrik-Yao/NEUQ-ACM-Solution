#include<iostream>
using namespace std;
 
typedef struct LNode 
{
	int data;
	LNode* next;
	LNode* pre;
}LNode;
 
int main()
{
	int n, m, k;
	cin>>n>>m>>k;
    LNode *p;
	p = (LNode*) malloc (sizeof(LNode)); 
    LNode *q,*r;
    q = p;
    r = p;
	p->data = 1; p->next = p;
	for (int i = 2; i <= n; i++)
	{
		q = (q->next = (LNode*) malloc (sizeof(LNode)));
		q->pre = r; 
		q->data = i;
		q->next = p;
		r = r->next;
	}
	p->pre = r;

	q = p;
	while (q != q->next)
	{
		if (m == 1)
		{
			cout<<q->data<<" ";
			q->next->pre = q->pre;
			q->pre->next = q->next;
			q = q->pre;
		}
		else
		{
			for (int i = 2; i < m; i++)
            {
                q = q->pre;
            }
			cout<<q->pre->data<<" ";
			q->pre = q->pre->pre;
			q->pre->next = q;
			q = q->pre;
		}
		if (k == 1)
		{
			cout<<q->data<<" ";
			q->next->pre = q->pre;
			q->pre->next = q->next;
			q = q->next;
		}
		else
		{
			for (int i = 2; i < k; i++)
				{
                    q = q->next;
                }
			cout<<q->next->data<<" ";
			q->next = q->next->next;
			q->next->pre = q;
			q = q->next;
		}
	}
	if (n % 2 == 1)
		{
            cout<<p->data<<" ";
        }
	return 0;
}