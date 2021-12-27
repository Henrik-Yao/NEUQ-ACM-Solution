#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *leftc;
	tree *rightc;
};
string fir="\0";
bool jud;
tree* postorder(int post[],int mid[],int n)
{
	if (n==0) return NULL;
	tree *bt = new tree;
	int i;
	for(i=0;i<n;i++)
	if(post[n-1]==mid[i]) break;
	if(i==n) 
	{
		jud=0;
		return NULL;
	}
	cout<<post[n-1]<<' ';
	bt->leftc = postorder(post,mid,i);
	bt->rightc = postorder(post+i,mid+i+1,n-i-1);
	return bt;
}
int main()
{
	int n;
  	cin>>n;
 	int post[n], mid[n];
 	for (int i = 0; i < n; i++) 	cin>> post[i];
 	for (int i = 0; i < n; i++)     cin>>mid[i];
	tree *bt=postorder(post,mid,n);
	return 0;
} 
