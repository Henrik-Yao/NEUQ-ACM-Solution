#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    Node *left;
	Node *right;
}Node,*Tree;
Tree create(int *a,int *b,int n)
{
    if(n<1)
    {
    	return NULL;
	}
    Tree tree=(Tree)malloc(sizeof(Node));
    tree->data=a[0];
    int i;
    for(i=0;i<n;i++)
	{
        if(a[0]==b[i])
        {
        	break;
		}         
    }
    tree->left=create(a+1,b,i);
    tree->right=create(a+i+1,b+i+1,n-i-1);
    return tree;
}
void levelorder(Tree &tree)
{
    queue<Tree>q;
    if(tree!=NULL)
    {
        q.push(tree);
    }
    while(q.empty()==false)
    {
        cout<<q.front()->data<<" "; 
        if (q.front()->left!=NULL)
        {
            q.push(q.front()->left);   
        }
        if(q.front()->right!= NULL)
        {
            q.push(q.front()->right);
        }
        q.pop();
    }
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
    Tree tree=create(a,b,n);
    levelorder(tree);
    cout<<endl;
    return 0;
}
