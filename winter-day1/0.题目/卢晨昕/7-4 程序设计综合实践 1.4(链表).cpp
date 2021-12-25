#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;

int len=0;
int a[100005];


struct node
{
	node *nex,*pre;
	int num;
};
node *heads,*tails;
node *heads1,*tails1;
void setnode()
{
	heads=new node();
	tails=new node();
	heads->nex=tails;
	tails->pre=heads;
}
void setnode1()
{
	heads1=new node();
	tails1=new node();
	heads1->nex=tails1;
	tails1->pre=heads1;
}
void insert(node *p,int val)
{
	node *q=new node();
	q->num=val;
	p->nex->pre=q;
	q->nex=p->nex;
	p->nex=q;
	q->pre=p;
}
void remove(node *p)
{
	p->pre->nex=p->nex;
	p->nex->pre=p->pre;
	delete p;
}
void re()
{
	while(heads!=tails)
	{
		heads=heads->nex;
		delete heads->pre;
	}
	delete tails;
}
void re1()
{
	while(heads1!=tails1)
	{
		heads1=heads1->nex;
		delete heads1->pre;
	}
	delete tails1;
}
int main()
{
	while(scanf("%d",&a[++len])!=EOF);
	sort(a+1,a+len);
	setnode();
	setnode1();
	node *nows=heads;
	node *nows1=heads1;
	for(int i=1;i<len;i++)
	{
		insert(nows,a[i]);
		nows=nows->nex;
	}
	for(node *i=heads->nex;i!=tails;i=i->nex)
	{
		if(i!=tails->pre)cout<<i->num<<"->";
		else cout<<i->num<<endl;
	}
	for(node *i=heads->nex;i!=tails;i=i->nex)
	{
		node *j=i->pre;
		if(i->num%2==0)
		{
			insert(nows1,i->num);
			nows1=nows1->nex;
			remove(i);
			i=j;
		}
	}
	for(node *i=heads->nex;i!=tails;i=i->nex)
	{
		if(i!=tails->pre)cout<<i->num<<"->";
		else cout<<i->num<<endl;
	}
	if(heads->nex==tails)cout<<endl;
	for(node *i=heads1->nex;i!=tails1;i=i->nex)
	{
		if(i!=tails1->pre)cout<<i->num<<"->";
		else cout<<i->num;
	}
	re();
	re1();
	return 0;
}
