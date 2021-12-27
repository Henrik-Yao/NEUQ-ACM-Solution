#include<iostream>
#include<vector>
using namespace std;
struct aaa
{
    char c;
    aaa* front;
    aaa* behind;
    aaa(char c) : c(c) {}
};
int main()
{
    aaa* llist=new aaa(0);
    llist->behind=llist->front=llist;
    aaa* now=llist;
    char x;
    int f_insert=0;
    while(x=getchar())
    {
        if(x=='\n') break;
        else if(x=='[') now=llist;
        else if(x==']') now=llist->front;
        else if(x=='{')
        {
            if(now!=llist)
                now=now->front;
        }
        else if(x=='}')
        {
            if(now->behind!=llist)
                now=now->behind;
        }
        else if(x=='-') f_insert=1-f_insert;
        else if(x=='=') 
        {
            if(now!=llist)
            {
                now=now->front;
                now->behind=now->behind->behind;
                now->behind->front=now;
            }
        }
        else
        {
            if(f_insert==1)
            {
                now->behind->c=x;
                now=now->behind;
                continue;
            }
            aaa* temp=new aaa(x);
            temp->c=x;
            temp->behind=now->behind;
            temp->behind->front=temp;
            now->behind=temp;
            temp->front=now;
            now=temp;
        }
    }
    for(aaa* p=llist->behind;p!=llist;p=p->behind)
    {
        cout<<p->c;
    }
    return 0;
}