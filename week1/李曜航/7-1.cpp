#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
    int n;
    cin>>n;
    cin>>a;
    while(n--)
    {
        string b;
        cin>>b;
        int cnt = 0;
        if(b.length()==1)
        {
        	for(int i=0;i<a.length();i++)
        		if(b[0]==a[i])
        			cnt++;
		}
		else if(b.length()>a.length())
			cnt = 0;
		else
	        for(int j=0;j<=a.length()-b.length();j++)
	        {
	        	if(a[j]==b[0])
	        	{
	        		bool flag = true;
	        		for(int i=0;i<b.length();i++)
	        		{
	        			if(!(a[j+i]==b[i]))
	        			{
	        				flag=false;
	        				break;
						}
					}
					if(flag)
						cnt++;
				}
			}
		cout<<cnt<<endl;
    }
}