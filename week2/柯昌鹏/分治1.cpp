#include<bits/stdc++.h>
using namespace std;
int s1[10001]={};
int s2[10001]={};
vector<int>t[100001];
int main()
{
    int n,m,aa,a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		t[a].push_back(b);
		s1[a]++;
		t[b].push_back(a);
		s1[b]++;
	}
    cin>>aa;
    while(aa--)
    {
    	for(int i=1;i<=n;i++)
    	{
    		s2[i]=s1[i];
		}
    	int cc,v,flag=1;
    	cin>>cc;
    	while(cc--)
    	{
		cin>>v;
		s2[v]=0;
		int i;
		for(auto i:t[v])	    
		{
		    s2[i]--;			}		
		}
	for(int i=1;i<=n;i++)
	{
		if(s2[i]>0)
        {
			flag=0;
			printf("NO\n");
			break;
		}
		}
	if(flag==1) printf("YES\n");
	}
    return 0;
}
