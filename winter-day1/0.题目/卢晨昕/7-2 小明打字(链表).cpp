//链表模板，多看看 
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
string a;
struct node
{
	node *nex,*pre;
	char c;
};
node ans[50005];
node *head,*tail;
node *now;//now指每个字符的位置前边
int op=1;//当前是插入还是替换 
int len=0;//链表长度 
int main()
{
	head=ans;
	tail=(ans+50004);
	head->pre=NULL;
	head->nex=tail;
	tail->pre=head;
	tail->nex=NULL;
	getline(cin,a);
	
	int noww=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]!='['&&a[i]!=']'&&a[i]!='{'&&a[i]!='}'&&a[i]!='-'&&a[i]!='=')
		{
			ans[++len].c=a[i];
			head->nex=(ans+len);
			tail->pre=(ans+len);
			(ans+len)->pre=head;
			(ans+len)->nex=tail;
			now=tail;
			noww=i;
			break;
		}
	}
	for(int i=noww+1;i<a.length();i++)
	{
		if(a[i]=='[')now=head->nex;
		else if(a[i]==']')now=tail;
		else if(a[i]=='{')
		{
			if(now!=head->nex)
			{
				now=now->pre;
			}
		}
		else if(a[i]=='}')
		{
			if(now!=tail)
			{
				now=now->nex;
			}
		}
		else if(a[i]=='-')
		{
			op=-op;
		}
		else if(a[i]=='=')
		{
			if(now->pre!=head->nex)
			{
				now->pre->pre->nex=now;
				now->pre=now->pre->pre; 
			}
			else if(now->pre==head->nex)
			{
				head->nex=now;
				now->pre=head;
			}
			else if(now==tail)
			{
				tail->pre=tail->pre->pre;
				tail->pre->pre->nex=tail;
			}
		}
		else
		{
			if(op==1)
			{
				if(now!=head->nex&&now!=tail)
				{
					ans[++len].c=a[i];
					(ans+len)->pre=now->pre;
					(ans+len)->nex=now;
					now->pre->nex=(ans+len);
					now->pre=(ans+len);
				}
				if(now==head->nex)
				{
					ans[++len].c=a[i];
					(ans+len)->nex=head->nex;
					head->nex->pre=(ans+len);
					head->nex=(ans+len);
					(ans+len)->pre=head;
				}
				else if(now==tail)
				{
					ans[++len].c=a[i];
					tail->pre->nex=(ans+len);
					(ans+len)->pre=tail->pre;
					(ans+len)->nex=tail;
					tail->pre=(ans+len);
				}
			}
			else if(op==-1)
			{
				if(now!=tail)
				{
					now->c=a[i];
					now=now->nex;
				}
				else
				{
					ans[++len].c=a[i];
					tail->pre->nex=(ans+len);
					(ans+len)->pre=tail->pre;
					(ans+len)->nex=tail;
					tail->pre=(ans+len);
				}
			}
		}
	}
	for(node *i=head->nex;i!=tail;i=i->nex)
	{
		if(i==tail)break;
		cout<<i->c;
	}
	return 0;
}
