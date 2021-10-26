#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int chu1[100005];//前半段区间的每个数字出现的次数
int chu2[100005];//后半段区间的每个数字出现的次数
int ans=0;//记录答案 
int ans1=0;//记录前半段区间权值 
int ans2=0;//记录后半段区间权值 
int main()
{
	cin>>n;
	//枚举两端区间的分界点，初始时分界点为 1 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>=2)
		{
			if(chu2[a[i]]==0)//后半段出现新数字 
			{
				ans2++;
			}
			chu2[a[i]]++;
		}
	}
	ans1=1;
	chu1[a[1]]++;
	for(int i=2;i<=n;i++)//枚举分界点 ，对于每次变动 ：前半段多分界点上的数，后半段少分界点上的数 
	{
		if(chu1[a[i]]==0)//a[i]在前半段没出现过 
		{
			ans1++;
			chu1[a[i]]++;
		}
		else//a[i]在前半段出现过 
		{
			chu1[a[i]]++;
		}
		if(chu2[a[i]]>1)//后半段有a[i]不止一个
		{
			chu2[a[i]]--;
		}
		else if(chu2[a[i]]==1)//后半段a[i]只剩一个
		{
			ans2--;
			chu2[a[i]]--;
		}
		if(ans1+ans2>=ans)ans=ans1+ans2;
	}
	cout<<ans;
	return 0;
}
