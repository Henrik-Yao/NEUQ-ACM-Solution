#include <bits/stdc++.h>
#include <vector>
using namespace std;
int a[20],cnt = 0,n;
bool jud[20];
vector<int> temp;
int p[20];
void dfs(int begin,int num)
{
	if(num>1) cnt++;
	for(int i=begin;i<n;i++)
	{
		if(!jud[i])
		{
			bool judge = 1;
				if(num==0) 
			{
				for(int j=0;j<i;j++) if(a[j]==a[i]) judge = 0;
				if(judge)
				{
					temp.push_back(a[i]);
					jud[i]=1;
					p[num]=i;
					dfs(i+1,num+1);
					jud[i]=0;
					temp.pop_back();
				}
			}
			else if(num!=0&&a[i]>=temp.back())
			{
				
				for(int j=p[num-1]+1;j<i;j++) if(a[j]==a[i]) judge = 0;
				if(judge)
				{
					temp.push_back(a[i]);
					jud[i]=1;
					p[num]=i;
					dfs(i+1,num+1);
					jud[i]=0;
					temp.pop_back();
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
		 jud[i]=0;
	}
	dfs(0,0);
	cout<<cnt;
	return 0;
} 




