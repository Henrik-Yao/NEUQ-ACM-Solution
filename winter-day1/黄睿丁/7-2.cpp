#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    char data;
    node *next;
    node *before;
}node;
int main()
{
    string str;
    getline(cin,str);
    node *head=new node;
    head->next=NULL;
    head->before=NULL;
    node *p=head;
    int mode=1;
    int i,l=str.length();
    for(i=0;i<l;i++)
    {
        char a=str[i];
        if(a>='a'&&a<='z'||a==' ')
        {
            if(mode==1)
            {
                if(p->next==NULL)
                {
                    node *s=new node;
                    s->data=a;
                    s->next=NULL;
                    s->before=p;
                    p->next=s;
                    p=s;
                }
                else
                {
                    node *s=new node;
                node *q=p->next;
                s->data=a;
                s->next=p->next;
                p->next=s;
                s->before=p;
                q->before=p->next;
                p=s;
                }
            }
            else if(mode==-1)
            {
                p=p->next;
                p->data=a;
            }
        }
        else if(a=='[')
        {
            p=head;
        }
        else if(a==']')
        {
            while(p->next)
            {
                p=p->next;
            }
        }
        else if(a=='{')
        {
            if(p->before)
            p=p->before;
        }
        else if(a=='}')
        {
            if(p->next)
            p=p->next;
        }
        else if(a=='-')
        {
            mode*=-1;
        }
        else if(a=='=')
        {
            if(p->next)
            {
                node *q=p;
                p->before->next=p->next;
                p->next->before=p->before;
                p=p->before;
                delete q;
            }
            else
            {
                node *q=p;
                p=p->before;
                p->next=NULL;
                delete q;
            }
        }
    }
    p=head->next;
    while(p->next)
    {
        cout<<p->data;
        p=p->next;
    }
    cout<<p->data;
}
