#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int t,pre[1010],dep[1010],d=1;
		stack<int> jie;
		cin>>t;
		dep[t]=d++;
		jie.push(t);
		while(!jie.empty())
		{
			cin>>t;
			if(t)
			{
				pre[t]=jie.top(); //½Úµã»¥²»ÏàµÈ
				dep[t]=d++;
				jie.push(t); 
			}
			else
			{
				jie.pop();
				d--;
			}
		}
		int a,b;
		cin>>t; //0
		cin>>a>>b;
		if(dep[a]>dep[b])
		{
			t=dep[a]-dep[b];
			while(t--)
			{
				a=pre[a];
			}
		}
		else
		{
			t=dep[b]-dep[a];
			while(t--)
			{
				b=pre[b];
			}
		}
		while(pre[a]!=pre[b])  //a,bÒ»¶¨ÔÚÊäÈëµÄÊ÷ÖÐ 
		{
			a=pre[a];
			b=pre[b];
		}
		cout<<pre[a]<<endl;
	}
	return 0;
}
