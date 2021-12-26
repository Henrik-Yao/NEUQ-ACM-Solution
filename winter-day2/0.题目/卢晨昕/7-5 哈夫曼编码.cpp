//7-7 ¹ş·òÂü±àÂë
#include<bits/stdc++.h>

using namespace std;
int n,m;
char c[100];
int f[1000];
int ans=0,sum=0;
int flag=0;
priority_queue<int,vector<int>,greater<int> >q;//¹Ì¶¨Ğ´·¨£¬Ğ¡¸ù¶Ñ 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		getchar();
		cin>>c[i]>>f[i];
		q.push(f[i]);
	}
	while(q.size()>1)
	{
		int x=q.top();
		q.pop();
		int y=q.top();
		q.pop();
		q.push(x+y);
		ans+=x+y;
	}
	
	cin>>m;
	while(m--)
	{
		char s[75][75];
		sum=0;
		for(int i=1;i<=n;i++)
		{
			getchar();
			char x;
			cin>>x>>s[i];
			sum+=(int)strlen(s[i])*f[i];
		}
		if(sum!=ans)
		{
			cout<<"No"<<endl;
		}
		else
		{
			flag=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j)
					{
						if(strstr(s[i],s[j])==&s[i][0])
						{
							flag=1;
							break;
						}
					}
				}
				if(flag==1)break;
			}
			if(flag==1)cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}
	
	return 0;
}
