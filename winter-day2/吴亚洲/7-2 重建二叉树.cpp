#include<bits/stdc++.h>
using namespace std;
bool flag=true;
string ans;
char mid[105],post[105];
struct Node
{
	char date;
	Node *left;
	Node *right;
};
Node* rebuild(char post[],char mid[],int len)
{
	if(len==0)
	return NULL;
	Node *t=new Node;
	t->date=post[len-1];
	int i=0;
	for(;i<len;i++)
	if(post[len-1]==mid[i])
	break;
	if(i==len)
	{
		flag=false;
		return NULL;
	}
	else
	{
		ans+=t->date;
		t->left=rebuild(post,mid,i);
		t->right=rebuild(post+i,mid+i+1,len-i-1);
	}
	return t;
}
int getheight(Node *t)
{
	if(t==NULL)
	return 0;
	int x=getheight(t->left);
	int y=getheight(t->right);
	if(x>y)
	return x+1;
	else
	return y+1;
}
int main()
{
	string a;
	while(cin>>a>>mid)
	{
		for(int i=0;i<a.length();i++)
		post[i]=a[i];
		flag=true;
		ans="";
		Node *T=new Node;
		T=rebuild(post,mid,a.length());
		if(!flag)
		cout<<"INVALID"<<endl;
		else
		cout<<getheight(T)-1<<endl<<ans<<endl;
	}
}
