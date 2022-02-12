#include <bits/stdc++.h>
using namespace std;
class child
{
    public:
    int data;
    child *next;
    child *pre;
};
void predelete(child *a)
{
    a->next = a->next->next;
    a->next->pre = a;
}
void nextdelete(child *a)
{
    a->pre = a->pre->pre;
    a->pre->next = a;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    child *p =new child;
    p->data=1;
    child *a = p;
    for(int i=2;i<=n;i++) 
    {
        a->next =new child;
        a->next->pre = a;
        a =a->next;
        a->data=i;
    }
    
    a->next =p;
    p->pre =a;
    a = p;
    int jud=0;
    while(n--)
    {
        if(!jud) 
        {
            for(int i=0;i<m;i++) a = a->pre;
            cout<<a->next->data<<' ';
            predelete(a);
            jud=1;
        }
        else 
        {
            for(int i=0;i<k;i++) a = a->next;
            cout<<a->pre->data<<' ';
            nextdelete(a);
            jud=0;
        }
    }
    return 0;
}
