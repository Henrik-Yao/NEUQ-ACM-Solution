#include<bits/stdc++.h>
using namespace std;
#define N 100
typedef struct tree{
    int data;
    tree *lChild,*rChild;
}*Tree;
int n;
int f[N],s[N];
Tree buildTree(int l1,int l2,int r1,int r2)
{
    if(l1>l2||r1>r2)return nullptr;
    Tree p = (Tree) malloc(sizeof(tree));
    int a = f[l1];
    int t;
    for(int i = r1; i <= r2; i++)if(a==s[i])t = i;
    p->data = a;
    int l = t - r1;
    p->lChild = buildTree(l1+1,l1 + l,t - l,t - 1);
    p->rChild = buildTree(l1+l+1,l2,t+1,r2);
    return p;
}
void Visit(Tree p)
{
    if(p == nullptr)return;
    Visit(p->lChild);
    Visit(p->rChild);
    cout<<p->data<<" ";
}
int main() {
    int n;
    cin>>n;
    for(int i = 0; i < n ;i++)cin>>f[i];
    for(int i = 0; i < n ;i++)cin>>s[i];
    Tree p = buildTree(0,n-1,0,n-1);
    Visit(p);
    return 0;
}
