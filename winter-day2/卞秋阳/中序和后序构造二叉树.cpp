#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node_Tree
{
	int data;
	Node_Tree *le,*ri;	
};
int n,back[10000],middle[10000];
void createTree(Node_Tree *&t,int *back,int *middle,int n); 
void preorder(Node_Tree *t)
{
	if(t==NULL)
		return;
	cout<<t->data<<" ";
	preorder(t->le);
	preorder(t->ri);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>back[i];
	for(int i=0;i<n;i++) cin>>middle[i];
	Node_Tree *T;
	createTree(T,back,middle,n);
	preorder(T);
	return 0;
}
void createTree(Node_Tree *&t,int *back,int *middle,int n)
{
	int num;
	int *ptr;
	if(n<=0)
	{
		t=NULL;
		return;
	}
	t=new Node_Tree;
	ptr=middle;
	while(*ptr!=back[n-1]){
		ptr++;
	}
	t->data=*ptr;
	num=ptr-middle;
	createTree(t->le,back,middle,num);
	createTree(t->ri,back+num,middle+num+1,n-num-1);
}
