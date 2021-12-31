#include <bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> a;
typedef struct tree
{
	tree *left;
	tree *right;
};
int y=0;
tree* preorder(int pre[],int mid[],int n)
{
	if(n==0) return NULL;
	tree *bt = new tree;
	int i;
	for(i=0;i<n;i++) 
	if(pre[0]==mid[i]) break;
	if(i==n) return NULL;
	a.insert(a.begin(),pre[0]);
	bt->right = preorder (pre+i+1,mid+i+1,n-i-1);
	bt->left = preorder(pre+1,mid,i);
	return bt;
}
int main()
{
	int n;
  	cin>>n;
 	int pre[n], mid[n];
 	for (int i = 0; i < n; i++) 	cin>> pre[i];
 	for (int i = 0; i < n; i++)     cin>>mid[i];
	tree *bt=preorder(pre,mid,n);
	for(int i=0;i<n;i++) cout<<a[i]<<' ';
	return 0;
} 
