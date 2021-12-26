#include <bits/stdc++.h>
using namespace std;
typedef struct LNode{
    int data;
    LNode *next;
    LNode *prior;
}LNode,*Linklist;
int main(){
    Linklist L;
    L=(Linklist)malloc(sizeof(LNode));
    L->next=NULL;
    L->prior=NULL;
    int n,m,k;
    cin>>n>>m>>k;
    Linklist rear;
        rear=(Linklist)malloc(sizeof(LNode));
        rear->data=n;
        rear->next=L->next;
        L->next=rear;
        rear->prior=L;
    n-=1;
    while(n--){
        Linklist p;
        p=(Linklist)malloc(sizeof(LNode));
        p->data=n+1;
        p->next=L->next;
        L->next->prior=p;
        L->next=p;
        p->prior=L;
    }
    L->next->prior=rear;
    rear->next=L->next;
    L=L->next;
    while(L!=L->next){
        if(m==1){
            cout<<L->data;
            L->next->prior=L->prior;
            L->prior->next=L->next;
            L=L->prior;
        }
        else {
            for(int i=2;i<m;i++)
                L=L->prior;
                cout<<L->prior->data<<" ";
                L->prior->prior->next=L;
                L->prior=L->prior->prior;
                L=L->prior;
        }
        if(k==1){
            cout<<L->data;
            L->next->prior=L->prior;
            L->prior->next=L->next;
            L=L->next;
        }
        else {
            for(int i=2;i<k;i++)
                L=L->next;
                cout<<L->next->data<<" ";
                L->next->next->prior=L;
                L->next=L->next->next;
                L=L->next;
        }
    }
    if (n % 2 == 1)
		printf("%d", L->data);
    cout<<endl;
	return 0;
}
