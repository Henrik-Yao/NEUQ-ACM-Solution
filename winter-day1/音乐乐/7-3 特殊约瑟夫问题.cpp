#include<bits/stdc++.h>
using namespace std;
typedef struct tagNode
{
	int data;
	struct tagNode *pre,*next;
}Node,*LinkList;

void InitList(LinkList *L)
{
	*L=(LinkList)malloc(sizeof(Node));
	//获取Node的字段长度，然后强转为LinkList类型。L变量就代表地址长度和Node一样所占内存空间同样大小的LinkList
	(*L)->next=(*L)->pre=*L;
	//初始化：两个指针都指向自身 
}

int main()
{
	int n,m,k,i;
	cin>>n>>m>>k;
	LinkList L;
	InitList(&L);
	struct tagNode *p,*q,*g;
	p=(LinkList)malloc(sizeof(Node));
	g=q=p;
	p->data=1;
	p->next=p;
	for(i=2;i<=n;i++)
	{
		q = (q->next=(LinkList)malloc(sizeof(Node)));
		q->pre=g;
		q->data=i;
		q->next=p;
		g=g->next;
	}
	p->pre=g;
	q=p;
	for(int cnt=1;cnt<=n;cnt++)
	{
		if(cnt&1)
		{
			if (m == 1)
			{
				printf("%d", q->data);
				q->next->pre = q->pre;
				q->pre->next = q->next;
				q = q->pre;
			}
			else
			{
				for (i=2;i<m;i++)
					q=q->pre;
				printf("%d ",q->pre->data);
				q->pre=q->pre->pre;
				q->pre->next=q;
				q = q->pre;
			}
		}
		else
		{
			if (k == 1)
			{
				printf("%d", q->data);
				q->next->pre=q->pre;
				q->pre->next=q->next;
				q = q->next;
			}
			else
			{
				for (i=2;i<k; i++)
					q=q->next;
				printf("%d ", q->next->data);
				q->next=q->next->next;                                                                                                 ;
				q->next->pre=q;
				q=q->next;
			}
		}
	}
	return 0;
}
