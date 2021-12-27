#include<bits/stdc++.h>
using namespace std;
vector<int>T;
int n,m,k,flag=1;
int main()
{   int y;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)T.push_back(i);
	
	while(T.size()>=1){
	
	y=T.front();
	T.erase(T.begin());
	reverse(T.begin(),T.end());
	T.insert(T.begin(),y);
	if(flag)
	{
		for(int i=0;i<m;i++)
		{
			y=T.front();
			T.erase(T.begin());
			if(i!=m-1) T.push_back(y);
			else cout<<y<<" ";
			
		}
		flag=0;
	}
	else{
		for(int i=0;i<k;i++)
		{
			y=T.front();
			T.erase(T.begin());
			if(i!=k-1) T.push_back(y);
			else cout<<y<<" ";
			
		}
		flag=1;
	}
	
	
	
} return 0;
}
