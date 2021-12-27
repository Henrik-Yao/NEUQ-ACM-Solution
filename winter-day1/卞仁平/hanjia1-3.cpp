#include <bits/stdc++.h>
using namespace std;
int n,m,k;
//链表

struct biao
{
    int data;
    struct biao* next;
    struct biao* last;
};

int main()
{
    cin>>n>>m>>k;
    struct biao* p,*q,*g;
    p=(struct biao*)malloc(sizeof(struct biao));
    g=q=p;
    p->data=1;
    p->next=p;
    for(int i=2;i<=n;i++)
    {
        q=(q->next=(struct biao*)malloc(sizeof(struct biao)));
        q->last=g;
        q->data=i;
        q->next=p;
        g=g->next;
    }
    p->last=g;
    q=p;
    while(q!=q->next)
    {
        if(m==1)
        {
            cout<<q->data;
            q->next->last=q->last;
            q->last->next=q->next;
            q=q->last;
        }
        else 
        {
            for(int i=2;i<m;i++)
            q=q->last;
            cout<<q->last->data<<" ";
            q->last=q->last->last;
            q->last->next=q;
            q=q->last;
        }
        if(k==1)
        {
            cout<<q->data;
            q->next->last=q->last;
            q->last->next=q->next;
            q=q->next;
        }
        else 
        {
            for(int i=2;i<k;i++)
            q=q->next;
            cout<<q->next->data<<" ";
            q->next=q->next->next;
            q->next->last=q;
            q=q->next;
        }
    }
    if(n%2==1)
    cout<<p->data;
    return 0;
}
