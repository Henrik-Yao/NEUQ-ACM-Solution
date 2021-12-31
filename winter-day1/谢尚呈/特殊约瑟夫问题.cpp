#include<iostream>
using namespace std;

struct node{
	int num;
	node *pre, *nex;
};

struct round{
	node *lap;
	node *now;

	round(void)
	{
		lap=new node;
		lap->num=0;
		lap->nex=lap;
		lap->pre=lap;
		now=lap;
	}
	
	void add(int num)
	{
		node *adt=new node;
		adt->num=num;
		adt->pre=now->pre;
		adt->nex=now;
		adt->pre->nex=adt;
		adt->nex->pre=adt;
		return;
	}
	
	node* operator+(int times)
	{
		if(lap->nex==lap);
		else
		for(int i=0; i<times; i++)
		{
			now=now->nex;
			if(now==lap)	now=now->nex;
		}
		return now;
	}
	node* operator-(int times)
	{
		if(lap->pre==lap);
		else
		for(int i=0; i<times; i++)
		{
			now=now->pre;
			if(now==lap)	now=now->pre;
		}
	}
	
	void del(bool next)
	{
		node *let=now;
		if(next)	(*this)+1;
		else		(*this)-1;
		let->nex->pre=let->pre;
		let->pre->nex=let->nex;
		delete let;
	}
	
	bool fit(void)
	{
		return lap->nex->nex==lap;
	}
	
	~round(void)
	{
		now=lap->nex;
		while(lap->nex!=lap)	del(true);
		delete lap;
	}
};

int main()
{
	round it;
	int n, m, k;
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)	it.add(i);
	it+1;
	bool next=true;
	while(!it.fit())
	{
		if(next)	it-(m-1);
		else		it+(k-1);
		cout<<it.now->num<<" ";
		it.del(!next);
		next=!next;
	}
	cout<<it.lap->nex->num<<" ";
	return 0;
}
