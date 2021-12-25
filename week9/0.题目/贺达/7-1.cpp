#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int d[n-1];//统计相邻数差值
    for(int i=0;i<n-1;i++)
    {
        d[i]=a[i+1]-a[i]-1;
    }
    sort(d,d+n-1);
    int len=a[n-1]-a[0]+1;
    int cnt=n-2;
    for(int j=0;j<m-1;j++)
    {
        len=len-d[cnt];//消去间隔最长的几段
        cnt--;
    }
    cout<<len;
	return 0;
}

