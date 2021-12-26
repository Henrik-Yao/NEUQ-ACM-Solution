
#include<iostream>
using namespace std;

struct linknode {
	int data;
	struct linknode* next;
	struct linknode* prior;
};

int main()
{
	int n, ni, shun, i;
	cin >> n >> ni >> shun;
	struct linknode* p, * q, * g;
	p = (struct linknode*)malloc(sizeof(struct linknode));
	g = q = p;
	p->data = 1; p->next = p;
	for (i = 2; i <= n; i++)
	{
		q = (q->next = (struct linknode*)malloc(sizeof(struct linknode)));
		q->prior = g;
		q->data = i;
		q->next = p;
		g = g->next;
	}
	
	p->prior = g;
	
	q = p;
	
	while (q != q->next)
	{
		
		if (ni == 1)
		{
			cout << q->data<<" ";
			q->next->prior = q->prior;
			q->prior->next = q->next;
			q = q->prior;
		}
		else
		{
			for (i = 2; i < ni; i++)
				q = q->prior;
			cout << q->prior->data <<" ";
			q->prior = q->prior->prior;
			q->prior->next = q;
			q = q->prior;
		}
		
		if (shun == 1)
		{
			cout << q->data << " ";
			q->next->prior = q->prior;
			q->prior->next = q->next;
			q = q->next;
		}
		else
		{
			for (i = 2; i < shun; i++)
				q = q->next;
			cout << q->next->data <<" ";
			q->next = q->next->next;
			q->next->prior = q;
			q = q->next;
		}
	}
	if (n % 2 == 1)
	{
		cout << p->data;
	}
	cout << endl;
	return 0;
}