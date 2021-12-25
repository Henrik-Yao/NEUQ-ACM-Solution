#include <bits/stdc++.h>
using  namespace  std;
int sum = 0;
string f;
struct List{
    char data;
    List* next;
    List* front;
};
struct gg{
     List* w;
    int soulation;
};
gg a;
void init(List* rear)
{
    a.w = rear;
    a.soulation = 0;
}
void insert(char t){
    if(a.soulation==0)
    {
        List *p = (List*) malloc(sizeof (List));
        p->next = a.w;
        p->front = a.w->front;
        a.w->front->next = p;
        a.w->front = p;
        p->data = t;
        sum++;
    } else
    {
        a.w->data = t;
        a.w = a.w->next;
    }
}
//bc
void backspace()
{
        sum--;
        a.w->front->front->next = a.w;
        a.w->front = a.w->front->front;
}
//abc
int main()
{

    getline(cin,f);
    List *head,*rear;
    List *s = (List*) malloc(sizeof (List));
    head = rear = s;
    head->next = rear;
    rear->front = head;
    init(rear);
    for(char i : f)
    {
         if((i>='a'&&i<='z')||(i>='A'&&i<='Z')||i==' ')
        {
            insert(i);
        }
         else if(i=='[')a.w = head->next;
         else if(i==']')a.w = rear;
         else if(i=='{'&&a.w!=head->next)a.w = a.w->front;
         else if(i=='}'&&a.w!=rear)a.w = a.w->next;
         else if(i=='-'){
            if(a.soulation)a.soulation = 0;
            else a.soulation = 1;
        }
         else if(i=='=')backspace();
         else ;
    }
    for(List *t = head->next; t!=rear; t = t->next)cout<<t->data;
    cout<<endl;
    return  0;
}