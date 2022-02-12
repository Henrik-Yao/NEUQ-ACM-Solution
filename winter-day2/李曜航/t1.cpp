#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
struct Node{
    int val;
    struct Node *left;
    struct Node *right;
    int dep;
};
int maxdep = 0;
int depval[200];
void creat_tree(Node *now, int val, int dep)
{
    now->val = val; now->dep = dep;
    int le = read();
    if(!le) now->left = NULL; else {now->left = new Node; creat_tree(now->left,le,dep+1);}
    int ri = read();
    if(!ri) now->right = NULL; else {now->right = new Node; creat_tree(now->right,ri,dep+1);}
}
void preTraverse(Node T)
{
    // cout<<T.val<<" "<<T.dep<<" "<<endl;
    if(T.left==NULL && T.right==NULL) 
    {
        if(depval[T.dep]==-2139062144) depval[T.dep] = 0;
        depval[T.dep] += T.val;
    }
    maxdep = max(T.dep,maxdep);
    if(T.left)
        preTraverse(*T.left);
    if(T.right)
        preTraverse(*T.right);
}
int main()
{
    // freopen("read.in","r",stdin);
    memset(depval,0x80,sizeof(depval));
    Node root;
    int val = read();
    creat_tree(&root,val,0);

    preTraverse(root);
    // root.val = read();

    int maxval = 0;
    for(int i=0;i<=maxdep;i++)
    {
        if(depval[i]>=depval[maxval])
            maxval = i;
        // printf("dep%d:%d\n",i,depval[i]);
    }
    cout<<maxval<<endl;
    // freopen("read.in","r",stdin);


}