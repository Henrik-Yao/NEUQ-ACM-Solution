#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    node *next;
    node *before;
}node;
int main()
{
    node *p=new node,*q=new node;
    node *h=p;
    p->data=0;
    p->next=q;
    q->before=p;
    p=q;
    q=new node;
    p->data=0;
    p->next=q;
    q->before=p;
    p=q;
    int n,m,k;
    cin>>n>>m>>k;
    int i,j;
    for(i=1;i<=n;i++)
    {
        node *s=new node;
        p->data=i;
        p->next=s;
        s->before=p;
        p=s;
    }
    p=p->before;
    p->next=h;
    h->before=p;
    p=h;
    j=1;
    while(n!=0)
    {
        if(j==1)
        {
            for(i=1;i<m;i++)
            {
                if(p->data==0)
                    i--;
                p=p->before;
            }
            p=p->next;
            cout<<p->data<<" ";
            p->next->before=p->before;
            p->before->next=p->next;
            q=p;
            p=p->next;
            delete q;
        }
        else if(j==-1)
        {
            for(i=1;i<k;i++)
            {
                if(p->data==0)
                    i--;
                p=p->next;
            }
            p=p->before;
            cout<<p->data<<" ";
            p->next->before=p->before;
            p->before->next=p->next;
            q=p;
            p=p->before;
            delete q;
        }
        n--;
        j*=-1;
    }
}
