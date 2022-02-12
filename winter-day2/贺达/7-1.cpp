#include<bits/stdc++.h>
using namespace std;
int c[101];
typedef struct BiNode
{
    int data;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

BiTree pre()
{
    BiTree T;
    int d;
    cin>>d;
    if(d!=0)
    {
        T=(BiTree)malloc(sizeof(BiNode));
        T->data=d;
        T->lchild=pre();
        T->rchild=pre();
    }
    else
    {
        T=NULL;
    }
    return T;
}
int h=1;
void gety(BiTree T)
{
    if(T)
    {
        if(T->lchild==NULL&&T->rchild==NULL)//叶子
        {
            c[h]=c[h]+(T->data);
        }
        gety(T->lchild);
        gety(T->rchild);
        if(T->lchild!=NULL&&T->rchild!=NULL)
        {
            h++;//不是叶节点继续往下
        }
    }
    return ;
}

int getre()
{
    int m,loca;
    m=c[0];
    loca=0;
    for(int i=0;i<h;i++)
    {
        if(c[i]>=m)
        {
            m=c[i];
            loca=i;
        }
    }
    return loca;
}

int main()
{
    BiTree T;
    T=pre();
    gety(T);
    int result;
    result=getre();
    cout<<result;
    return 0;
}
