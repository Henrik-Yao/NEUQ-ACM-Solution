#include <bits/stdc++.h>
using namespace std;
struct List{
	int data,worth;
	List* next;
	List() : next(NULL),data(-1),worth(-1) {}
};
int main()
{
	int n,e;
	List *nullp;
	nullp=new List();
	cin>>n>>e;
	vector <List*> p(n);
	vector <List*> site(n);
	for(int i=0;i<n;i++)
	{
		site[i]=p[i]=new List();
		p[i]->next=nullp;
	}
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		List *t=new List();
		t->data=b;
		t->worth=c;
		t->next=NULL;
		while(site[a]!=nullp||site[a]->next->data>t->data)
		{
			if(site[a]->next==nullp)
			{
				site[a]->next=t;t->next=nullp;break;
			}
			if(site[a]->next->data>t->data)
			{
				t->next=site[a]->next;
				site[a]->next=t;
				break;
			}
			site[a]=site[a]->next;
		}
		site[a]=p[a];
		/*while(site[a]->next!=NULL)
		{
			cout<<"("<<a<<","<<site[a]->next->data<<","<<site[a]->next->worth<<")";
			site[a]=site[a]->next;
		}
		site[a]=p[a];*/
	}
	for(int i=0;i<n;i++)
	{
		bool flag=0;
		site[i]=p[i];
		if(site[i]->next!=nullp)
		{
			cout<<i<<":("<<i<<","<<site[i]->next->data<<","<<site[i]->next->worth<<")";
			flag=1;
			site[i]=site[i]->next;
		}
		while(site[i]->next!=nullp)
		{
			cout<<"("<<i<<","<<site[i]->next->data<<","<<site[i]->next->worth<<")";
			site[i]=site[i]->next;
		}
		if(flag) cout<<endl;
	}
	return 0;
}
