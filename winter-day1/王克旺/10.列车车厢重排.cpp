#include<bits/stdc++.h>
#include<vector>
using namespace std; 
vector<int>v[100];
int main()
{
	int N,a[100],flag=0,count=0,x;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<N;i++)
	{
		flag=0;
		for(int j=0;j<count;j++)
		{
			if(a[i]<v[j].back())
	    	{
				v[j].push_back(a[i]);
				if(a[i]==1)
				{
					x=j;
				}
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			if(a[i]==1)
		    {
		    	x=count;
		    }
		    v[count++].push_back(a[i]);
		}	
	}
	while(!v[x].empty())
    {
        cout<<v[x].front();
        if(v[x].size()>1)
		{
			cout<<" ";
		}
        v[x].erase(v[x].begin());
    }
    cout<<endl;
    cout<<count<<endl;
	return 0;
}
