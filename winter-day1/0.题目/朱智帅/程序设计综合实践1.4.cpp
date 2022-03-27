#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
typedef struct Node
{
	int data;
	Node* next;
}*Linklist;
int main()
{
	int number[10001], cnt = 0, i;
	while (cin >> number[cnt])
	{
		cnt++;
	}
	sort(number, number + cnt);
	Linklist Head = (Linklist)malloc(sizeof(Node)), p;
	Head->data = NULL;
	Head->next = NULL;
	p = Head;
	for (i = 0; i < cnt; i++)
	{
		cout << number[i];
		if (i + 1 < cnt) cout << "->";
		Linklist newL = (Linklist)malloc(sizeof(Node));
		newL->data = number[i];
		newL->next = NULL;
		p->next = newL;
		p = p->next;
	}
	cout << endl;
	Linklist Head2 = (Linklist)malloc(sizeof(Node)), q;
	p = Head;
	q = Head2;
	while (p->next)
	{
		if (p->next->data % 2 == 0)
		{
			Linklist t = p->next;
			Linklist tmp = (Linklist)malloc(sizeof(Node));
			tmp->data = t->data;
			tmp->next = NULL;
			q->next = tmp;
			q = q->next;
			if (t->next) p->next = t->next;
			else p->next = NULL;
			delete t;
		}
		else p = p->next;
	}
	//cout << endl;
	p = Head->next;
	q = Head2->next;
	while (p)
	{
		cout << p->data;
		if (p->next) cout << "->";
		p = p->next;
	}
	cout << endl;
	while (q)
	{
		cout << q->data;
		if (q->next) cout << "->";
		q = q->next;
	}
	cout << endl;
}
