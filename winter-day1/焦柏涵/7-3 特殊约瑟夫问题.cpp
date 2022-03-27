#include <bits/stdc++.h>
using namespace std;
struct dl{
	struct dl *front,*next;
	int num;
	dl(int _num) : num(_num){}
};
typedef dl* lb;
lb Creat_lb()
{
	lb l=new dl(1);
	l->front=l->next=l;
	return l;
}
int main()
{
	int n,m,k;
	bool sx=0;
	cin>>n>>m>>k;
	lb head=Creat_lb(),site=head;
	head->num=1;
	for(int i=2;i<=n;i++)
	{
		lb z=new dl(i);
		z->front=site;
		z->next=head;
		site->next=z;
		head->front=z;
		site=z;
	}
	site=head;
	while(n--)
	{
		if(sx==0)
		{
			for(int i=1;i<m;i++)
			{
				site=site->front;
			}
			sx=1;
			cout<<site->num<<' ';
			site->front->next=site->next;
			site->next->front=site->front;
			site=site->front;
		}
		else
		{
			for(int i=1;i<k;i++)
			{
				site=site->next;
			}
			sx=0;
			cout<<site->num<<' ';
			site->front->next=site->next;
			site->next->front=site->front;
			site=site->next;
		}
	}
	cout<<endl;
	return 0;
}
