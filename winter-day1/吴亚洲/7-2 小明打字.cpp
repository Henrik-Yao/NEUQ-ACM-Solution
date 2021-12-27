#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
	char x;
	Node* l;
	Node* r;
} * List;
int main()
{
	char x;
	List start,end,temp;
	List N=new Node();
	start=N;end=N;temp=N;
	bool isinsert=true;
	List ins;
	while(scanf("%c",&x)&&x!='\n')
	{
		if(x=='[')
		temp=start;
		else if(x==']')
		temp=end;
		else if(x=='{')
		{
			if(temp->l)
			temp=temp->l;
		}
		else if(x=='}')
		{
			if(temp->r)
			temp=temp->r;
		}
		else if(x=='-')
		isinsert=!isinsert;
		else if(x=='=')
		{
			if(temp->l)
			{
				List t=temp;
				temp->l->r=temp->r;
				if(temp->r)
				{
					temp->r->l=temp->l;
					temp=temp->l;
				}
				else
				{
					temp=temp->l;
					temp->r=NULL;
				}
				delete t;
				if(temp->r==NULL)
				end=temp;
			}
		}
		else
		{
			ins=new Node();
			ins->x=x;
			ins->r=temp->r;
			ins->l=temp;
			temp->r=ins;
			temp=ins;
			if(temp->r==NULL)
			end=ins;
			if(!isinsert&&temp->r)
			{
				List t=temp->r;
				if(t->r)
				{
					temp->r=t->r;
					t->r->l=temp;
					delete t;
				}
				else
				{
					delete t;
					end=temp;
					temp->r=NULL;
				}
			}
		}
	}
	temp=start->r;
	while(temp)
	{
		cout<<temp->x;
		temp=temp->r;
	}
}
