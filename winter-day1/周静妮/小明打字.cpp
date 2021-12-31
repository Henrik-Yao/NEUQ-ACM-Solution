#include <bits/stdc++.h>
using namespace std;

typedef struct LNode 
{
	char c;
	LNode* next;
	LNode* prev;
} * List;

int main()
{
	char c;
	List start,end,temp,ins;
	List l=new LNode();
	start=l;
	end=l;
	temp=l;
	bool insert=1;
	while(scanf("%c", &c) && c != '\n')
	{
		if(c=='[')	temp=start;
		else if(c==']')	temp=end;
		else if(c=='{')	
			if(temp->prev) temp=temp->prev;
		else if(c=='}')
			if(temp->next)	temp=temp->next;
		else if(c=='-')	insert=!insert;
		else if(c=='=')
		{
			if(temp->prev)
			{
				List t=temp;
				temp->prev->next=temp->next;
				if(temp->next)
				{
					temp->next->prev=temp->prev;
					temp=temp->prev;	
				}
				else
				{
					temp=temp->prev;
					temp->next=NULL;
	
				}
				delete t;
				if(temp->next==NULL)	end=temp;
						
			}
		}
		else 
		{
			ins=new LNode();
			ins->c=c;
			ins->next=temp->next;
			ins->prev=temp;
			temp->next=ins;
			temp=ins;
			if(temp->next==NULL) end=ins;
			if(!insert && temp->next)
			{
				List t=temp->next;
				if(t->next)
				{
					temp->next=t->next;
					t->next->prev=temp;			
				}
				else
				{
					end=temp;
					temp->next=NULL;
				}
				delete t;
			}
		}
	}
	temp=start->next;
	while(temp)
	{
		printf("%c", temp->c);
		temp=temp->next;
	}
	return 0;
}
