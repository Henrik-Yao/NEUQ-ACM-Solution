#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *l;
	tree *r;
};
string f="\0";
bool is;
tree* order(char hou[],char zhong[],int n)
{
	if (n==0) return NULL;
	tree *x = new tree;
	int i;
	for(i=0;i<n;i++)
	if(hou[n-1]==zhong[i]) break;
	if(i==n) 
	{
		is=0;
		return NULL;
	}
	f+=hou[n-1];
	x->l = order(hou,zhong,i);
	x->r = order(hou+i,zhong+i+1,n-i-1);
	return x;
}
int getheight(tree *x)
{
	if(x == NULL) return 0;
	return max(getheight(x->l),getheight(x->r))+1;
}
int main()
{
	string s;
  	while(cin>>s)
  	{
  	is=1;
 	int n = s.size();
 	char hou[n], zhong[n];
 	for (int i = 0; i < n; i++) 	
    hou[i] = s[i];

	cin>>s;
 	for (int i = 0; i < n; i++)     
    zhong[i] = s[i];
	tree *x=order(hou,zhong,n);
	
	if(is) 
	{
		cout<<getheight(x)-1<<'\n';
		cout<<f;
	}
	else cout<<"INVALID";
	cout<<'\n';
	f="\0";
	}
	return 0;
}
