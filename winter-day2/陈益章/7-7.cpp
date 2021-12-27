#include<iostream>
#include<queue>
using namespace std;
string pre[15],mid[15],post[15];
struct node
{
    string data;
    node* left;
    node* right;
};
node* get_tree(int i,int j,int len)
{
    if(len<=0) return NULL;
    node *tree=new node;
    tree->data=pre[i];
    int p;
    for(p=1;p<=15;p++)
        if(mid[p]==pre[i]) break;
    tree->left=get_tree(i+1,j,p-j);
    tree->right=get_tree(i+(p-j)+1,p+1,len-1-(p-j));
    return tree;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>pre[i];
    for(int i=1;i<=n;i++) cin>>mid[i];
    node *root=get_tree(1,1,n);
    queue<node*>loft;
    loft.push(root);
    while(!loft.empty())
    {
        cout<<loft.front()->data<<" ";
        if(loft.front()->left!=NULL) loft.push(loft.front()->left);
        if(loft.front()->right!=NULL) loft.push(loft.front()->right);
        loft.pop();
    }
}
