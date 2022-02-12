#include<iostream>
using namespace std;
struct people
{
    people* prev;
    int num;
    people* next;
};
int main()
{
    int n,m,k,flag=0,cnt=0;   //flag为0逆时针,为1顺时针
    cin>>n>>m>>k;
    people *now;
    people *p1=new people;
    p1->num=1;
    now=p1;
    for(int i=2;i<=n-1;i++)
    {
        people *temp=new people;
        temp->num=i;
        temp->prev=now;
        now->next=temp;
        now=temp;
    }
    people *pn=new people;
    now->next=pn;
    pn->prev=now;
    pn->num=n;
    pn->next=p1;
    p1->prev=pn;
    now=p1;
    while(n>1)
    {
        if(flag==0)
        {
            while(1)
            {
                cnt++;
                if(cnt==m)
                {
                    cout<<now->num<<" ";
                    now->prev->next=now->next;
                    now->next->prev=now->prev;
                    now=now->prev;
                    flag=1-flag;
                    n--;
                    cnt=0;
                    break;
                }
                now=now->prev;
            }
        }
        else
        {
            while(1)
            {
                cnt++;
                if(cnt==k)
                {
                    cout<<now->num<<" ";
                    now->prev->next=now->next;
                    now->next->prev=now->prev;
                    now=now->next;
                    flag=1-flag;
                    n--;
                    cnt=0;
                    break;
                }
                now=now->next;
            }
        }
    }
    cout<<now->num<<" ";
    return 0;
}