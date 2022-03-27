#include<bits/stdc++.h> 
using namespace std;
struct activity
{
	int start;
	int end;
}arr[100];
bool cmp(activity x,activity y)
{
	return x.end<y.end;
}

int main()
{
	int T,i,j;
	cin>>T;
	while(T--)
	{
		for(i=0;i<100;i++)
		{
			arr[i].start=0;
			arr[i].end=0;
		}
		int n;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>arr[i].start>>arr[i].end;
		}
		sort(arr,arr+n,cmp);
		int cnt=1;
		j=0;
		for(i=1;i<n;i++)
		{
			if(arr[i].start>=arr[j].end)
			{
				j=i;
				cnt++;
			}
		}
		cout<<n-cnt<<endl;
	}
	return 0;
}
