#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

typedef struct LNode
{
    int data;
    LNode *next;
}LNode;

void Split(LNode list)
{
    LNode *head1,*head2;
    LNode *p = list.next;

    head1 = new LNode;
    head1->next = NULL;
    head2 = new LNode;
    head2->next = NULL;
    LNode *temp1 = head1;
    LNode *temp2 = head2;
    while(p)
    {
        if(p->data % 2 ==  1)
        {
            temp1->next = p;
            temp1 = p;
            p = p->next;
            temp1->next = NULL;
        }
        else
        {
            temp2->next = p;
            temp2 = p;
            p = p->next;
            temp2->next = NULL;
        }
    }
    
    temp1 = head1->next;
    temp2 = head2->next;
    while(temp1)
    {
        cout<<temp1->data;
        if(temp1->next)
        {
            cout<<"->";
        }
        temp1 = temp1->next;
    }
    cout<<endl;
    while(temp2)
    {
        cout<<temp2->data;
        if(temp2->next)
        {
            cout<<"->";
        }
        temp2 = temp2->next;
    }
    cout<<endl;
}


int main()
{
    int a[10000];
    int total = 1;
    cin>>a[0];
    while(1)
    {
        if(cin.get() == '\n')
        {
            break;
        }
        cin>>a[total];
        total++;
    }
    sort(a,a+total);

    LNode list;
    LNode *head;
    LNode *tail;
    head = new LNode;
    head->next = NULL;
    head->data = NULL;
    head = &list;
    tail = head;

    for(int i=0;i<total;i++)
    {
        LNode *p;
        p = new LNode;
        p->data = a[i];
        p->next =  NULL;
        tail->next = p;
        tail = p;
    }

    LNode *p  = head->next;
    while(p)
    {
        cout<<p->data;
        if(p->next)
        {
            cout<<"->";
        }
        p = p->next;
    }
    cout<<endl;

    Split(list);

    return 0;



    
}





