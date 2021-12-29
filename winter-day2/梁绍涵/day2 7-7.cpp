#include<bits/stdc++.h>
using namespace std;
typedef struct tree
{
	struct tree *left=NULL,*right=NULL;
	int data;
}*bitree,node;
bitree creat(bitree &T,int s)
{
	queue<bitree> q;
	q.push(T);
	while(s--)
	{
		int x;		
		cin>>x;
		bitree m;
		m=q.front();
		m=new node;
		if(x==0)
		{
			q.pop();
			continue;
		}
//		cout<<s<<"??"<<x<<"?"<<endl;
		m->data=x;
//		cout<<m->data<<"x"<<m->left;
		q.pop();
		q.push(m->left);
		q.push(m->right);
	}
	return T;
}
void inorder(bitree &T)
{
	if(T==NULL) return;
	inorder(T->left);
	inorder(T->right);
	cout<<T->data<<" ";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		bitree tr;	
		tr=creat(tr,n);
//		cout<<"xx";
cout<<tr->data<<">>>"<<endl;
		inorder(tr);
//		delete tr;	
		cout<<endl;
		cout<<log2(n)+1<<endl;
	}
}
