#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *leftc;
	tree *rightc;
};
string fir="\0";
bool jud;
tree* postorder(char post[],char mid[],int n)
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
	fir+=post[n-1];
	bt->leftc = postorder(post,mid,i);
	bt->rightc = postorder(post+i,mid+i+1,n-i-1);
	return bt;
}
int getheight(tree *bt)
{
	if(bt == NULL) return 0;
	return max(getheight(bt->leftc),getheight(bt->rightc))+1;
}
int main()
{
	string s;
  	while(cin>>s)
  	{
  	jud=1;
 	int n = s.size();
 	char post[n], mid[n];
 	for (int i = 0; i < n; i++) 	post[i] = s[i];
	cin>>s;
 	for (int i = 0; i < n; i++)     mid[i] = s[i];
	tree *bt=postorder(post,mid,n);
	
	if(jud) 
	{
		cout<<getheight(bt)-1<<'\n';
		cout<<fir;
	}
	else cout<<"INVALID";
	cout<<'\n';
	fir="\0";
	  }
	return 0;
} 
