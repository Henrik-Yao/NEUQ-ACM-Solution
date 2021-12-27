#include <iostream>
using namespace std;
typedef struct tree
{
    int data;
    tree *left=NULL;
    tree *right=NULL;
}tree;
int f[120],m[120];
tree *x=new tree;
tree* build(int l1,int r1,int l2,int r2)
{
	tree *t=new tree;
    if(l1>r1||l2>r2)
        return NULL;
    else if(l1==r1&&r2==l2)
        {
        	t->data=f[l1];
        	t->left=NULL;
        	t->right=NULL;
		}
    else
    {
    	int root=f[l1];
    	t->data=root;
    	int i;
    	for( i=l2;i<=r2;i++)
	    {
    	    if(m[i]==root)
        	{
    	        break;
        	}
	    }
        if(i==l2)
        {
            t->right=build(l1+i+1-l2,r1,i+1,r2);
        }
        else if(i==r2)
        {
            t->left=build(l1+1,i+l1-l2,l2,i-1);
        }
        else
        {
    	    t->left=build(l1+1,l1+i-l2,l2,i-1);
       	 	t->right=build(l1+i+1-l2,r1,i+1,r2);
        }
	}
    return t;

}
void print(tree *p)
{
    if(p!=NULL)
    {
    print(p->left);
    print(p->right);
    cout<<p->data<<" ";
    }
}
int main()
{
    int n;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>f[i];
    }
    for(i=0;i<n;i++)
    {cin>>m[i];}
    tree *p=build(0,n-1,0,n-1);
    print(p);
}
