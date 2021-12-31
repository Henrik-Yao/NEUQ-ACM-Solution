#include<bits/stdc++.h>
using namespace std;
int a[105];
int s=0;
int ii=1;
typedef struct tree
{
    int data;
    struct tree *lc,*rc;
}tree,*linktree;

linktree creattree()
{
    int Data;
    linktree node;
    cin>>Data;
    if(Data==0)node=NULL;
    else 
    {
        node=(linktree)malloc(sizeof(tree));
        node->data=Data;
        node->lc=creattree();
        node->rc=creattree();
    }
    return node;
}
void work(linktree bt)
{
    if(bt)
    {
        if(bt->lc==NULL&&bt->rc==NULL)
        a[ii]+=bt->data;
        work(bt->lc);
        work(bt->rc);
        if(bt->lc!=NULL&&bt->rc!=NULL)ii++;
    }
    return ;
}
int find(int *a,int k)
{
    int i,j;
    int l=0;
    int t=a[0];
    for(int j=1;j<k;j++)
    {
        if(t<=a[j])
        {
            t=a[j];
            l=j;
        }
    }
    return l;
}
int main()
{
    linktree t=NULL;
    t=creattree();
    if(t->lc==NULL&&t->rc==NULL)
    {
        cout<<"0";
        return 0;
    }
    work(t);
    int s=find(a,ii);
    cout<<s;
    return 0;
}