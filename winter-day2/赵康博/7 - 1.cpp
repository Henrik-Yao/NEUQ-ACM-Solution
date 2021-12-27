#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
    int data;
    tree *lChild,*rChild;
}*Tree;
int s[100];
int v[100];
void build(int n,Tree &a)
{
    int f;
    cin>>f;
    if(f!=0){
        a = (Tree) malloc(sizeof (tree));
        a->data = f;
    }
    else {
        a = nullptr;
        return;
    }
    build(n+1,a->lChild);
    build(n+1,a->rChild);
    if(a->rChild== nullptr&&a->lChild== nullptr)
    {
        s[n]+=a->data;
        v[n] = 1;
    }
}
int main() {
    Tree a;
    build(0,a);
    int t,max = -100;
    int xum = 0;
    for(int i = 0; i < 100; i++)
    {
        if(v[i]!=0)
        {
            if(s[i]>=max)
            {
                max = s[i];
                t = i;
            }
        }
    }
    cout<<t<<endl;
    return 0;
}
