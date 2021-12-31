#include<iostream>
#include<string>
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

void get_post(node *root)
{
    if(root!=NULL)
    {
        get_post(root->left);
        get_post(root->right);
        cout<<root->data<<" ";
    }
}


int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>pre[i];
    for(int i=1;i<=n;i++) cin>>mid[i];
    node *root=get_tree(1,1,n);
    get_post(root);
    return 0;
}