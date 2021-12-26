#include<iostream>
using namespace std;
struct node{
	node *next;
	int area;
	node(void)
	{
		next=NULL;
		area=0;
	}
};

struct sets{
	node *head, *oper;
	
	sets(void)
	{
		head=new node;
		oper=head;
	}
	
	void add(int num)
	{
		oper=head;
		while((oper->next!=NULL)&&(oper->next->area<num))	oper=oper->next;
		node *self=new node;
		self->area=num;
		self->next=oper->next;
		oper->next=self;
	}
	
	node* getnode(node *it)
	{
		node *temp=oper->next;
		oper->next=it;
		node *save=it->next;
		it->next=temp;
		oper=oper->next;
		return save;
	}
	
	void write()
	{
		oper=head->next;
		cout<<oper->area;
		while(oper->next!=NULL)
		{
			oper=oper->next;
			cout<<"->"<<oper->area;
		}
		return;
	}
	
	void prep(void)
	{
		oper=head;
		return;
	}
	
	void clear(void)
	{
		while(head->next!=NULL)
		{
			oper=head->next->next;
			cout<<endl<<"delete node: "<<head->next->area;
			delete head->next;
			head->next=oper;
		}
		delete head;
		return;
	}
};

void split(sets *org, sets *oth)
{
	org->prep();
	oth->prep();
	node *it=org->oper->next;
	while(it!=NULL)
	{
		bool flag=false;
		if((it->area)%2);
		else
		{
			org->oper->next=oth->getnode(it);
			flag=true;
		}
		if(flag==false)	org->oper=org->oper->next;
		it=org->oper->next;
	}
	return;
}

int main()
{
	int n;
	sets org, oth;
	while(cin>>n)	org.add(n);
	org.write();
	cout<<endl;
	split(&org, &oth);
	org.write();
	cout<<endl;
	oth.write();
	org.clear();
	oth.clear();
	return 0;
}
