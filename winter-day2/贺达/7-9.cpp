#include <iostream>
#define M 20
using namespace std;
int a[M];
int b[M];

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}node,*lpLeaf;

struct TreeNode* transaction(int inleft,int inright,int postleft,int postright,int* in,int* post)
{
    if(inright<inleft||postright<postleft)//终止条件，下标矛盾时终止
        return NULL;
    TreeNode* root=new TreeNode;//根节点
    int rootindex=postright;
    root->val=post[rootindex];
    int temp=inleft;
    while(in[temp]!=post[rootindex])
        temp++;//获得根节点在中序遍历中的位置，以便获得左子树和右子树的下标范围

    root->left=transaction(inleft,temp-1,postleft,temp-inleft+postleft-1,in,post);
    root->right=transaction(temp+1,inright,temp-inleft+postleft,postright-1,in,post);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
   return transaction(0,inorderSize-1,0,postorderSize-1,inorder,postorder);
}

void look(lpLeaf root) {
	if (root)
	{
        printf("%d ", root->val);
		look(root->left);
		look(root->right);

	}
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
     for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    lpLeaf root;
    root=buildTree(b,n,a,n);
    look(root);
    return 0;
}
