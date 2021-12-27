#include<bits/stdc++.h>
using namespace std;

struct linknode
{
    int data;
    struct linknode* next;
    struct linknode* prior;
};


int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    struct linknode *p,*q,*g;
    p=(struct linknode*)malloc(sizeof(struct linknode));
    g=q=p;
    p->data = 1;
    p->next = p;
    for(int i=2;i<=n;i++)
    {
        q = (q->next = (struct linknode*)malloc(sizeof(struct linknode)));
        q->prior =g;//g存储上一个指针
        q->data =i;
        q->next =p;
        g = g->next;
    }
    p->prior = g;//循环
    q = p;
    //双向循环链表构建完毕
    while(q != q->next)//当队列中不只剩下一个人时
    {
        //先逆时针
        if(m==1)
        {
            cout<<(q->data)<<" ";
            q->next->prior = q->prior;
            q->prior->next = q->next;
            q = q->prior;
        }
        else
        {
            for(int i=2;i<m;i++)
            {
                q = q->prior;
            }
            cout<<(q->prior->data)<<" ";
            //输出后删除该结点
            q->prior = q->prior->prior;
            q->prior->next =q;
            q= q->prior;
        }
        //后顺时针
        if(k==1)
        {
            cout<<q->data<<" ";
            q->next->prior = q->prior;
            q->prior->next = q->next;
            q=q->next;
        }
        else
        {
            for(int i=2;i<k;i++)
            {
                q = q->next;
            }
            cout<<q->next->data<<" ";
            //输出后删除结点
            q->next =q->next->next;
            q->next->prior =q;
            q= q->next;
        }
    }
    if(n%2==1)//n为奇数时，要补上最后一个结点
    {
        cout<<p->data<<" ";
    }
   return 0;
}
