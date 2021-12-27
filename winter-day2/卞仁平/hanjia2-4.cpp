#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
    tree* last;
    tree* next;

};
void add(tree *x,tree *y)
{
    if(x->last==NULL&&y->last==NULL)
    {
            while(x->next!=NULL)
            x=x->next;
            x->next=y;
            y->last=x;
    }
    else if(x->last==NULL)
    {
        while(y->next=NULL)
        y=y->next;
        y->next=x;
        x->last=y;
    }
    else if(y==NULL)
    {
        while(x->next!=NULL)
        x=x->next;
        x->next=y;
        y->last=x;
    }
    else 
    {
        while (y->last!=NULL)
        {
            y=y->last;
        }
        while(x->next!=NULL)
        x=x->next;
        x->next=y;
        y->last=x;
        
    }
}

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    tree a[n+1];
    for(int i=1;i<=n;i++)
    {
        a[i].last=NULL;
        a[i].next=NULL;
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
		while(aa1->last!=NULL) 
		{
			if(aa1->last==aa2)
			{
				cout<<"In the same gang."<<'\n';
				jud=1;
				break;
				
			}
			aa1=aa1->last;
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
		if(aa1->last==NULL) sum++;
	}
	cout<<sum;
	return 0;
}