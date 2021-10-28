#include<iostream>
using namespace std;

int arr[1000005],l[100005],r[100005];
int i,ans1=1,ans2=0,ans=0,n;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
		l[arr[1]]++;
		if(i>=2)
		{
			if(r[arr[i]]==0)
			{
				ans2++;
			}
			r[arr[i]]++;
		}
	}
	ans=ans1+ans2;
	for(i=2;i<=n-1;i++)
	{
		if(r[arr[i]]==1)
		{
			ans2--;
		}
		r[arr[i]]--;
		if(l[arr[i]]==0)
		{
			ans1++;
		}
		l[arr[i]]++;
		if(ans1+ans2>ans)
		ans=ans1+ans2;
	}
	cout<<ans<<endl;
	return 0;
}
