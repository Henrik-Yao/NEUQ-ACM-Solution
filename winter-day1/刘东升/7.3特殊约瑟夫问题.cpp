#include <bits/stdc++.h>
using namespace std;
struct node
{
	int n;
	node* pre;
	node* nex;	
};
int main()
{
	int N,M,K;
	cin>>N>>M>>K;
	node *curv,*prev,*head;//建一个列表 
	head=new node;
	head->nex=head;
	head->pre=head;
	prev=head;
	for(int i=1;i<=N;i++)
	{
		curv=new node;
		curv->n=i;
		prev->nex=curv;
		curv->pre=prev;
		prev=curv;
	}
	curv->nex=head->nex;
	head->nex->pre=curv;
	curv=curv->nex;
	for(int i=1;i<=N;i++)
	{
		if(i%2==0)//用次数的奇偶来判断向前还是向后 
		{
			for(int i=1;i<K;i++)//开始移动 
			{
				prev=curv;
				curv=curv->nex;
			}
			cout<<curv->n<<' ';
			prev->nex=curv->nex;
			curv->nex->pre=prev;
			delete curv;//报完数踢出去 
			curv=prev->nex;
		}
		else
		{
			for(int i=1;i<M;i++)
			{
				prev=curv;
				curv=curv->pre;
			}
			cout<<curv->n<<' ';
			prev->pre=curv->pre;
			curv->pre->nex=prev;
			delete curv;
			curv=prev->pre;
		}
	}
	return 0;
}
