#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int date;
	Node* left;
	Node* right;
};
queue<Node*>q;
int ans;
void build(Node* t,int n)
{
	int date;
	q.push(t);
	while(!q.empty())
	{
		cin>>date;
		n--;
		if(date==0)
		{
			q.front()=NULL;
			q.pop();
			continue;
		}
		q.front()->date=date;
		q.front()->left=new Node;
		q.front()->right=new Node;
		q.push(q.front()->left);
		q.push(q.front()->right);
		q.pop();
		if(!n)
		{
			Node *temp;
   			while(!q.empty())
			{
				
				temp=q.front();
				q.front()->left=NULL;
				q.front()->right=NULL;
				q.pop();
				
			}
			delete temp;
			break;
		}
	}
}
void show(Node* t,int level)
{
	if(t==NULL)
	return ;
	show(t->left,level+1);
	cout<<t->date<<" ";
	ans=max(ans,level);
	show(t->right,level+1);
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		Node *t=new Node;
		build(t,n);
		show(t,0);
		cout<<endl<<ans<<endl;
	}
}
