#include <bits/stdc++.h>
using namespace std;
typedef struct tree
{
	int data;
	tree *left;
	tree *right;
};
int y=0;
tree* preorder(int pre[],int mid[],int n)
{
	if(n==0) return NULL;
	tree *bt = new tree;
	bt->data = pre[0];
	int i;
	for(i=0;i<n;i++) 
	if(pre[0]==mid[i]) break;
	if(i==n) return NULL;
	bt->right = preorder (pre+i+1,mid+i+1,n-i-1);
	bt->left = preorder(pre+1,mid,i);
	return bt;
}
void Layerorder(tree *bt,tree ** F,tree ** R)
{
    *F = bt;        
    cout<<(*F)->data<<' ';
    if((*F)->left!=NULL)
    {
    R=R+1;
    *R=(*F)->left; 
    }
    if((*F)->right!=NULL)
    {
    R=R+1;              
    *R=(*F)->right;         
    }
    if(F!=R)
    {
     F=F+1;
     Layerorder(*F,F,R);
    } 
}
int main()
{
	int n;
  	cin>>n;
 	int pre[n], mid[n];
 	for (int i = 0; i < n; i++) 	cin>> pre[i];
 	for (int i = 0; i < n; i++)     cin>>mid[i];
	tree *bt=preorder(pre,mid,n);
	tree **F,**R;
	tree * Queue[1024];
    F=Queue;
    R=Queue; 
	Layerorder(bt,F,R); 
	return 0;
} 
