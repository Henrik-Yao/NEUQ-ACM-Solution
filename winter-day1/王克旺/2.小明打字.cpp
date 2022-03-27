#include<bits/stdc++.h>
using namespace std;
struct Node{
    char ch;
    Node *next;
    Node *pre;
};
int main()
{
    char ch;
    Node *start,*end,*t;
    Node *N=new Node();
    start=N;
    end=N;
    t=N;
    bool Insert=true;
    Node *input;
    while(scanf("%c",&ch)&&ch!='\n')
	{
        if(ch=='[')
		{
            t=start;
        }
		else if(ch==']')
		{
            t=end;
        }
		else if(ch=='{')
		{
            if(t->pre)
            {
            	t=t->pre;
			}
        }
		else if(ch=='}')
		{
            if(t->next)
			{
				t=t->next;
			}
        }
		else if(ch=='-')
		{
            Insert=!Insert;
        }
		else if(ch=='=')
		{
            if(t->pre)
			{
                t->pre->next=t->next;
                if(t->next)
				{
                    t->next->pre=t->pre;
                    t=t->pre;
                }
				else
				{
                    t=t->pre;
                    t->next=NULL;
                }
                if (t->next==NULL)
				{
				    end=t;
				}
            }
        }
		else
		{
            input=new Node();
            input->ch=ch;
            input->next=t->next;
            input->pre=t;
            t->next=input;
            t=input;
            if(t->next==NULL)
			{
			    end=t;
			}
            if(!Insert&&t->next)
			{
                if(t->next->next)
				{
                    t->next=t->next->next;
                    t->next->next->pre=t;
                }
				else
				{
                    end=t;
                    t->next=NULL;
                }
            }
        }
    }
    t=start->next;
    while(t)
	{
        cout<<t->ch;
        t=t->next;
    }
    delete N;
    delete input;
    return 0;
}
