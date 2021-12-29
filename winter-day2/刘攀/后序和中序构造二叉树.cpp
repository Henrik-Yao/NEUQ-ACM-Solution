#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    Node *left;
	Node *right;
}Node,*Tree;
Tree createtree(int *a,int *b,int n)
{
    if(n<1)
    {
    	return NULL;
	}    
    Tree tree=(Tree)malloc(sizeof(Node));
    tree->data=a[n-1];
    int i;
    for(i=0;i<n;i++)
	{
        if(a[n-1]==b[i])
        {
        	break;
		}         
    }
    tree->left=createtree(a,b,i);
    tree->right=createtree(a+i,b+i+1,n-i-1);
    return tree;
}
void back(Tree tree)
{
    if(!tree)
    {
    	return;
	} 
    cout<<tree->data<<" ";
    back(tree->left);
    back(tree->right);
}
int main()
{
    int n,i;
    cin>>n;
    int a[100],b[100];
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	for(i=0;i<n;i++)
    {
    	cin>>b[i];
	}
    Tree tree=createtree(a,b,n);
    back(tree);
    cout<<endl;
    return 0;
}

