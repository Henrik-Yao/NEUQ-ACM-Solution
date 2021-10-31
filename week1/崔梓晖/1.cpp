#include <bits/stdc++.h>
using namespace std;
char a[50001];
int ans[500001];
int main()
{
	int n,q=0;
	string b;
	cin>>n;
	cin>>a+1;
	int la=strlen(a+1);
	while(n--)
	{
		int t=0;
		cin>>b;
		int lb=b.size();
		for(int i=1;i<=la-lb+1;i++)
		{
			string c;
			c.clear();
			for(int j=i;j<=i+lb-1;j++)
			{
				c=c+a[j];
			}
			if(b==c)
			t++;
		}
		q++;
		ans[q]=t;
	}
	for(int i=1;i<=q-1;i++)
	{
		cout<<ans[i]<<endl;
	}
	cout<<ans[q];
	return 0;
}
