#include <bits/stdc++.h>
using namespace std;
int a[20],cnt = 0,n;
bool is[20];
vector<int> ji;
int p[20];
void dfs(int start,int num)
{
	if(num>1) cnt++;
	for(int i=start;i<n;i++)
	{
		if(!is[i])
		{
			bool f = 1;
				if(num==0) 
			{
				for(int j=0;j<i;j++) if(a[j]==a[i]) 
                f = 0;
				if(f)
				{
					ji.push_back(a[i]);
					is[i]=1;
					p[num]=i;
					dfs(i+1,num+1);
					is[i]=0;
					ji.pop_back();
				}
			}
			else if(num!=0&&a[i]>=ji.back())
			{
				
				for(int j=p[num-1]+1;j<i;j++) if(a[j]==a[i]) f = 0;
				if(f)
				{
					ji.push_back(a[i]);
					is[i]=1;
					p[num]=i;
					dfs(i+1,num+1);
					is[i]=0;
					ji.pop_back();
				}
			}
			
		}
		while(i<n&&a[i]==a[i+1]) i++;
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		 cin>>a[i];
		 is[i]=0;
	}
	dfs(0,0);
	cout<<cnt;
	return 0;
}
