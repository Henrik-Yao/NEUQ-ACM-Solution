#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int a,b,c[100],d[100];
	while(T--)
	{
		cin>>a;
		for(int i=0;i<a;i++)
		{
			cin>>c[i];
		}
		cin>>b;
		for(int i=0;i<b;i++)
		{
			cin>>d[i];
		}
	
	int sum[200];
	int q=0,w=0,e=0;
		while(w<a&&e<b)
		{
			if(c[w]<=d[e])
			{
				sum[q]=c[w];
				w++;
				q++;
			}
			else
			{
				sum[q]=d[e];
				e++;
				q++;
			}
		}
		while(w<a)
		{
			sum[q]=c[w];
			w++;
			q++;
		}
		while(e<b)
		{
			sum[q]=d[e];
			e++;
			q++;
		}
		for(int i=0;i<a+b;i++)
		{
			cout<<sum[i];
			if(i!=a+b-1) cout<<' ';
			else cout<<'\n';
		}
	}
	return 0;
}
