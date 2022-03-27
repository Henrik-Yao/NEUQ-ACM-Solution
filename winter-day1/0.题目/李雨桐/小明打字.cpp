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
    List s,e,temp;
    List L = new LNode();
    s = L;
    e = L;
    temp = L;

    bool isInsert = true;

    List ins;
    while (scanf("%c",&c) &&c!='\n')
        {
        if (c == '[')
            temp = s;
        else if (c == ']')
            temp=e;
        else if (c == '{')
            {
            if (temp->prev)
            temp=temp->prev;
            }
        else if (c == '}')
            {
            if (temp->next)
            temp=temp->next;
            }
        else if (c=='-')
            isInsert = !isInsert;
        else if (c=='=')
            {
            if (temp->prev)
            {
                List t = temp;
                temp->prev->next = temp->next;

                if (temp->next)
                {
                    temp->next->prev = temp->prev;
                    temp = temp->prev;
                }
                else
                {
                    temp = temp->prev;
                    temp->next=NULL;
                }
                delete t;
                if (temp->next==NULL)
                    e=temp;
            }
        }
        else
        {
            ins=new LNode();
            ins->c=c;
            ins->next=temp->next;
            ins->prev=temp;
            temp->next=ins;
            temp = ins;
            if (temp->next==NULL)
                e=temp;
            if (!isInsert&&temp->next)
            {
                List t=temp->next;
                if (t->next)
                {
                    temp->next=t->next;
                    t->next->prev=temp;
                    delete t;
                }
                else
                {
                    delete t;
                    e=temp;
                    temp->next=NULL;
                }
            }
        }

    }

    temp = s->next;
    while (temp>0)
    {
        printf("%c", temp->c);
        temp = temp->next;
    }


    return 0;
}

