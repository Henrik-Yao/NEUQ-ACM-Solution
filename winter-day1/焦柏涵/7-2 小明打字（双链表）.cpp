#include <bits/stdc++.h>
using namespace std;
struct str{
	struct str *front;
	char ch;
	struct str *next;
	str(char z) : ch(z) {}
};
typedef str* lb;
lb Creat_lb()
{
	lb l=new str(0);
	l->front=l->next=l;
	return l;
}
int main()
{
	bool change=0;
	lb head=Creat_lb(),site;
	site=head;
	char a;
	while((a=getchar())!='\n')
	{
		if(a=='[') site=head;
		else if(a==']') site=head->front;
		else if(a=='{') 
		{
			if(site!=head) site=site->front;
		}
		else if(a=='}')
		{
			if(site->next!=head) site=site->next;
		}
		else if(a=='-')
			{
				if(change==0) change=1;
				else change=0;
			}
		else if(a=='=')
			{
				if(site!=head)
				{
					site=site->front;
					site->next=site->next->next;
					site->next->front=site;
				}
			}
		else if((a>='a'&&a<='z')||a==' ')
		{
			if(change!=0)
			{
				site->next->ch=a;
				site=site->next;
				continue;
			}
			lb n=new str(a);
			n->ch=a;
			n->next=site->next;
			n->next->front=n;
			site->next=n;
			n->front=site;
			site=n;
		}
	}
	for(lb i=head->next;i!=head;i=i->next) cout<<i->ch;
	cout<<endl;
	return 0;
}
