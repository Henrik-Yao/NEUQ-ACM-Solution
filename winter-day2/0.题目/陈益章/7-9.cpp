#include<iostream>
using namespace std;
string post[15],mid[15],pre[15];
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
    tree->data=post[i];
    int p;
    for(p=1;p<=15;p++)
        if(mid[p]==post[i]) break;
    tree->left=get_tree(i-1-(len-1-(p-j)),j,p-j);
    tree->right=get_tree(i-1,p+1,len-1-(p-j));
    return tree;
}
void get_pre(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        get_pre(root->left);
        get_pre(root->right);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>post[i];
    for(int i=1;i<=n;i++) cin>>mid[i];
    node *root=get_tree(n,1,n);
    get_pre(root);
}
