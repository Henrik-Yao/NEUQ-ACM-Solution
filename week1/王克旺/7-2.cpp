#include<iostream>
using namespace std;
int a[1000001];
int main()
{
    int n,i,ans=0,ans1=0,ans2=0,begin[100001],end[100001];  
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if (end[a[i]]==0)
		{
			ans2++;				
		}
		end[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if (begin[a[i]]==0)
		{
			ans1++;
			begin[a[i]]++;
		}
		else
		{
			begin[a[i]]++;
		}
		if (end[a[i]]>1)
		{
			end[a[i]]--;
		}
		else if(end[a[i]]==1)
		{
			ans2--;
			end[a[i]]--;
		}
		if (ans1+ans2>=ans)
		{
		    ans=ans1+ans2;
		}
	}
	cout<<ans;
	return 0;
}
