#include <bits/stdc++.h>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*Linklist;
int main(){
    Linklist L;
    L=(Linklist)malloc(sizeof(LNode));
    L->next=NULL;
    int n;
    cin>>n;
    Linklist p;
        p=(Linklist)malloc(sizeof(LNode));
        p->data=n;
        p->next=L->next;
        L->next=p;
    while(cin>>n){
            p=L;
        while(p->next&&p->next->data<n){
            p=p->next;
        }
        Linklist q;
        q=(Linklist)malloc(sizeof(LNode));
        q->data=n;
        q->next=p->next;
        p->next=q;
    }
    p=L->next;
    while(p->next){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<p->data<<endl;
    Linklist N;
    N=(Linklist)malloc(sizeof(LNode));
    N->next=NULL;
    p=L;
    Linklist f,t;
    t=N;
    while(p->next){
        if(p->next->data%2==0) {
            f=p->next;
            p->next=f->next;
            f->next=t->next;
            t->next=f;
            t=f;
        }
        else p=p->next;
    }
    //t->next=NULL;
    f=L;
    while(f->next&&f->next->next){
        cout<<f->next->data<<"->";
        f=f->next;
    }
    if(f->next) cout<<f->next->data;
    cout<<endl;
    t=N;
    while(t->next&&t->next->next){
        cout<<t->next->data<<"->";
        t=t->next;
    }
    if(t->next) cout<<t->next->data;
}
