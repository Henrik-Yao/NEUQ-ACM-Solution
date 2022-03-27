#include<bits/stdc++.h>
using namespace std;
string dfs()
{
	char c;
	int n;
	string str,ans;
	while(cin>>c)
	{
		if(c=='[')
		{
			cin>>n;
			str=dfs();
			while(n--)
			{
				ans+=str;
                
			}
		}
		else if(c==']')
		{
            
			return ans;
		}
        
		else
		{
			ans+=c;	
		}
	}
}


int main()
{
    
	cout<<dfs();
	return 0;
}
