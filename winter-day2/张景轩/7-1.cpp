#include<iostream>
using namespace std;

#define Status int
#define OK 1
#define ERROR 0

typedef struct BiNode
{
    int data;
    BiNode *lchild;
    BiNode *rchild;
}BiNode,*LinkNode;

int sum = 0;
int level = 1;
int ans[1000] = {0};

LinkNode CreateBiTree()
{
    int DATA;
    BiNode *newNode;
    cin>>DATA;
    if(DATA == 0)
    {
        newNode = NULL;
    }
    else
    {
        newNode = (LinkNode) malloc (sizeof(BiNode));
        newNode->data = DATA;
        newNode->lchild = CreateBiTree();
        newNode->rchild = CreateBiTree();
    }

    return newNode;
}

Status findSum(LinkNode bt)
{
    if(!bt)
    {
        return NULL;
    }

    if(!bt->lchild && !bt->rchild)
    {
        ans[level] = ans[level] + bt->data;
    }

    findSum(bt->lchild);
    findSum(bt->rchild);

    if(bt->lchild && bt->rchild)
    {
        level++;
    }

    return OK;
}

int main()
{
    level = 1;
    LinkNode root = NULL;
    root = CreateBiTree();
    if(!root->lchild && !root->rchild)
    {
        cout<<"0";
        return 0;
    }
    findSum(root);

    int temp = ans[0];
    int max = 0;
    for(int i=1;i<level;i++)
    {
        if(temp < ans[i])
        {
            temp = ans[i];
            max =   i;
        }
    }

    cout<<max<<endl;

    return 0;
}


