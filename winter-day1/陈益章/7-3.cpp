#include<iostream>
#include<vector>
using namespace std;
vector<int> a;
int main()
{
	int n,m,k,now=1,f=1,id;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
	a.push_back(i);
	id=n;
	while(n)
	{
		if(f%2!=0)
		{
		m%=n; 
		now-=m-1;
		if(now<=0)
		now=id+now;
		f++;
		cout<<a[now-1]<<" ";
		a.erase(a.begin()+now-1,a.begin()+now-1);
		n--;
	}
	else
	{
		k%=n;
		now+=k-1;
		if(now>=n)
		now=now-id;
		f++;
		cout<<a[now-1]<<" ";
		a.erase(a.begin()+now-1,a.begin()+now-1);
		n--;
	}
	}
}
