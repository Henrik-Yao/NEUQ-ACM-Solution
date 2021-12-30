#include<bits/stdc++.h>
using namespace std;
vector<int>s;
int main()
{
	int n;
	cin>>n;
	int x;
	for(int i=0;i<2*n;i++)//两个组并起来
	{
		scanf("%d",&x);
		s.push_back(x);
	}
	sort(s.begin(),s.end());
	int mid=(s.size()+1)/2-1;
	cout<<s[mid];
	return 0;
}