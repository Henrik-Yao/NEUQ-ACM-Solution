#include <bits/stdc++.h>
using namespace std;
set< list<int> >s;//set���ϣ��Դ�ȥ�غ����� 
list<int> l;//˫��������ǰ�󶼲�ѯ�����ݽṹ 
int n,num[100];
void dfs(int x)
{
	if(x==n)
	{
		if(l.size()>=2)
		{
			s.insert(l);
		}
		return;
	}
	if(!l.size()||num[x]>=l.back())//l.back()��ѯ�������һ��Ԫ�� 
	{
		l.push_back(num[x]);
		dfs(x+1);
		l.pop_back();
	}
	if(!l.size()||num[x]!=l.back())
	{
		dfs(x+1);
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	dfs(0);
	int ans=s.size();
	cout<<ans<<endl;
	return 0;
}
