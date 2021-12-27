#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int d,u,flag=0,count=0;
		int a[100]={0};
		vector<int>v[100];
		queue<int>q;
		for(int i=0;i<m;i++)
        {
            cin>>d>>u;
            v[d].push_back(u);
            a[u]++;
        }
        for(int i=1;i<=n;i++)
        {
        	if(!a[i])
			{
				q.push(i);
			}
		}           
        if(q.size()==1)
		{
			flag=1;
		}
        while(!q.empty())
        {
		    count++;
            int temp=q.front();
            q.pop();          
            for(int i=0;i<v[temp].size();i++)
            {
            	a[v[temp][i]]--;
				if(a[v[temp][i]]==0)
            	{
            		q.push(v[temp][i]);
				}                    
			}     
        }
        if(count!=n)
        {
            cout<<0<<endl;
        }
        else if(count==n&&flag==1)
		{
			cout<<1<<endl;
		}
        else
		{
			cout<<2<<endl;
		}
	}
	return 0;
}
