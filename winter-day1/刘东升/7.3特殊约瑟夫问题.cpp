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
	node *curv,*prev,*head;//��һ���б� 
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
		if(i%2==0)//�ô�������ż���ж���ǰ������� 
		{
			for(int i=1;i<K;i++)//��ʼ�ƶ� 
			{
				prev=curv;
				curv=curv->nex;
			}
			cout<<curv->n<<' ';
			prev->nex=curv->nex;
			curv->nex->pre=prev;
			delete curv;//�������߳�ȥ 
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
