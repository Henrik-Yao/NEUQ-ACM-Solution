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
int n, pre[10010];
int mid[10010];
// int pre_l, pre_r;
struct Node{
    Node *left;
    Node *right;
    int val;
};
void build(int pl, int pr, int ml, int mr, Node *fa)
{
    fa->val = pre[pl];
    if(pl==pr && ml==mr) return;


    int gen;
    for(int i=ml;i <= mr;i++)
    {
        if(mid[i]==pre[pl])
        {
            gen = i;
            break;
        }
    }
    if(gen==ml)
    {
        fa->left = NULL;
        // buildright
        fa->right = new Node;
        build(pl+gen-ml+1,pr,gen+1,mr,fa->right);
        return;
    }
    else if(gen==mr)
    {
        fa->right = NULL;
        //buildleft
        fa->left = new Node;
        build(pl+1,pl+gen-ml,ml,gen-1,fa->left);
        return;
    }
    fa->left = new Node;
    fa->right = new Node;
    build(pl+1,pl+gen-ml,ml,gen-1,fa->left);
    build(pl+gen-ml+1,pr,gen+1,mr,fa->right);
}

//后续遍历二叉树并打印
void postTraverse(Node T)
{
    if(T.left)
        postTraverse(*T.left);
    if(T.right)
        postTraverse(*T.right);
    cout<<T.val<<" ";
}
int main()
{
    freopen("read.in","r",stdin);
    n = read();
    for(int i=1;i<=n;i++)
        pre[i] = read();
    for(int i=1;i<=n;i++)
        mid[i] = read();
    
    Node root;
    build(1,n,1,n,&root);
    postTraverse(root);
}