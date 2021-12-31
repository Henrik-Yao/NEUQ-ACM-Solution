#include<bits/stdc++.h>
using namespace std;
int pre[11],in[11];
struct tree
{
	int da;
	tree* l;
	tree* r;
}trees;
tree* create(int pren,int inn,int n)
{
	if(n<=0){return NULL;}
	int i;
	tree* bt=new tree;
	bt->da=pre[pren];
	for(i=inn;i<inn+n;i++)
	{
		if(pre[pren]==in[i]){break;}
	}
	int k=i-inn;
	bt->l=create(pren+1,inn,k);
	bt->r=create(pren+1+k,i+1,n-k-1);
	return bt;
}

void level(tree* bt)
{
	queue<tree*> q;
	q.push(bt);
	while(!q.empty())
	{
		cout<<q.front()->da<<' ';		
		if(q.front()->l!=NULL)
		{
			q.push(q.front()->l);
		}
		if(q.front()->r!=NULL)
		{
			q.push(q.front()->r);
		}
		q.pop();
	}
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){cin>>pre[i];}
	for(int i=0;i<n;i++){cin>>in[i];}
	tree* bt=create(0,0,n);
	level(bt);
	return 0;
}
