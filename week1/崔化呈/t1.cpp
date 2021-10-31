#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char a[51000],t[31];
	cin>>a;
	int la,lt;
	la=strlen(a);
	for(int i=0;i<n;i++)
	{
		cin>>t;
		lt=strlen(t);
		int c=0;
		for(int k=0;k<la;k++)
		{
				int j=0;
					for(;j<lt;j++)
					{
						if(a[j+k]==t[j]){}
						else{break;}				
					}
					if(j==lt){c++;}
					else{}
		}
        if(i==n-1){cout<<c;}
        else{cout<<c<<endl;}
		
	}
	return 0;
}
