#include <iostream>
using namespace std;
typedef struct tree
{
    int data;
    tree *left;
    tree *right;
}tree;
int a[1001],maxl=-1,sum=0;
tree *build(int n,int m,int l)
{
    
    tree *t=new tree;
    if(a[n]==0)
    {
        t=NULL;
    }
    else
    {
        sum++;
        maxl=max(l,maxl);
        t->data=a[n];
        if(n*2<=m)
        {
            t->left=build(n*2,m,l+1);
        }
        else
        {
            t->left=NULL;
        }
        if(n*2+1<=m)
        {
            t->right=build(n*2+1,m,l+1);
        }
        else
        {
            t->right=NULL;
        }
    }
    return t;
}
int b=0;
 void count(tree *p)
{
    if(p)
    {
        count(p->left);
        count(p->right);
        b++;
    }
}
void print(tree *p,int x)
{
    if(p!=NULL)
    {
        print(p->left,x);
        if(b==x-1)
            cout<<p->data;
        else
        cout<<p->data<<" ";
        b++;
        print(p->right,x);

    }
}
int  main()
{
    int n;
    cin>>n;
    while(n--)
    {
        b=0;
        sum=0;
        maxl=-1;
        int m;
        cin>>m;
        int i,j;
        for(j=1;j<=m;j++)
        {
            cin>>a[j];
        }
        tree *p=build(1,m,1);
        int x=0;
        count(p);
        x=b;
        b=0;
        print(p,x);
        cout<<endl<<maxl<<endl;
    }
}
