#include<bits/stdc++.h>
using namespace std;
list<int>circle;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) circle.push_back(i);//围成一圈
	int flag=1;
	int t;
	while(circle.size()>1)
	{
		if(flag==1)//逆时针
		{
			for(int i=1;i<m;i++)//逆时针报m-1个人，不包括本身
			{
				t=circle.back();
				circle.pop_back();
				circle.push_front(t);
			}
			cout<<circle.front()<<" ";
			circle.pop_front();
		}
		else if(flag==-1)//顺时针
		{
			for(int i=1;i<k;i++)//逆时针报m-1个人，不包括本身
			{
				t=circle.front();
				circle.pop_front();
				circle.push_back(t);
			}
			cout<<circle.back()<<" ";
			circle.pop_back();
		}
		flag*=-1;
	}
	cout<<circle.front()<<" "<<endl;
	return 0;
}