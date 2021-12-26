#include <bits/stdc++.h>
using namespace std;
//双向循环链表
struct node
{
    int num;
    node *last;
    node *next;
};
int main()
{
    int n,M,K;
    cin>>n>>M>>K;
    node *head,*insert,*connect;
    head= new node;
    head->num=1;head->next=NULL;head->last=NULL;
    connect=head;
    for(int i=2;i<=n;i++)//构造双向环形链表(画图理解更快)
    {
        insert=new node;
        insert->num=i;
        insert->next=NULL;
        connect->next=insert;
        insert->last=connect;
        connect=connect->next;
    }
    connect->next=head;
    head->last=connect;
    connect=head;
    
    node *man=head;
    bool round=0;//开始是逆时针
    while(man!=man->next)//当不只剩下一个人时，进行循环
    {
        if(round==0)//M 逆时针
        {
            if(M==1)
            {
                cout<<man->num<<" ";
                man->next->last=man->last;
                man->last->next=man->next;
                man=man->last;
            }
            else
            {
                for(int i=2;i<M;i++)
                {
                    man=man->last;
                }//通过n-2次找到那个淘汰者的后一个人
                cout<<man->last->num<<" ";//输出该者号码
                man->last=man->last->last;
                man->last->next=man;
                man=man->last;
            }
            round=1;
        }
        else        //N 顺时针
        {
            if(K==1)
            {
                cout<<man->num<<" ";
                man->next->last=man->last;
                man->last->next=man->next;
                man=man->next;
            }
            else
            {
                for(int i=2;i<K;i++)//定位该淘汰者前一个
                man=man->next;
                cout<<man->next->num<<" ";
                man->next=man->next->next;
                man->next->last=man;
                man=man->next;
            }
            round=0;
        }
    }
    cout<<man->num;
    return 0;
}