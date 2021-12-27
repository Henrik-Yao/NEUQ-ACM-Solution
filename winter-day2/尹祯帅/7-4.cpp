#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *pre;
	tree *next;
};
void add(tree *a,tree *b)
{
	if(a->pre==NULL&&b->pre==NULL) 
	{
			while(a->next!=NULL) a=a->next;
			 a->next = b;
			 b->pre = a;
	}
	else if(a->pre==NULL) 
	{
		
		while(b->next!=NULL) b=b->next;
			 b->next = a;
			 a->pre = b;
	}
	else if(b==NULL)
	{
		
		while(a->next!=NULL) a=a->next;
			a->next = b;
			b->pre = a;
		
	}
	else 
	{
		while(b->pre!=NULL) b=b->pre;
		
		while(a->next!=NULL) a=a->next;
			 a->next = b;
			 b->pre = a;

	}
}
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	tree a[n+1];
	
	for(int i=1;i<=n;i++)
	{
		 a[i].pre= NULL;
		 a[i].next = NULL;
	}
	int a1,a2;
	tree *aa1;
	tree *aa2;
	while(m--)
	{
		cin>>a1>>a2;
		aa1=&a[a1];
		aa2=&a[a2];
		add(aa1,aa2);
	}
	while(q--)
	{
		bool jud=0;
		cin>>a1>>a2;
		aa1=&a[a1];
		aa2=&a[a2];
		if(a1==a2) 
		{
			cout<<"In the same gang."<<'\n';
			continue;
		}
		tree *aa3=aa1;
		while(aa1->pre!=NULL) 
		{
			if(aa1->pre==aa2)
			{
				cout<<"In the same gang."<<'\n';
				jud=1;
				break;
				
			}
			aa1=aa1->pre;
		}
		while(aa3->next!=NULL) 
		{
			if(aa3->next==aa2)
			{
				cout<<"In the same gang."<<'\n';
				jud=1;
				break;
				
			}
			aa3=aa3->next;
		}
		if(!jud) cout<<"In different gangs."<<'\n';
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		aa1=&a[i];
		if(aa1->pre==NULL) sum++;
	}
	cout<<sum;
	return 0;
} 
