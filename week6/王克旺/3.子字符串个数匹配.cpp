#include<bits/stdc++.h>
using namespace std;
int base=13331,mod=1e9+7;
int ha[100000];
 
int main()
{
	int i,j,count=0,flag=0,hash=0,Hash;
    string a,b;
	getline(cin,a);
	cin>>b;
    int len1=a.size(),len2=b.size();
    for(i=0;i<len2;i++)
	{
		if(b[i]>='a'&&b[i]<='z')
        {
            hash=(1ll*hash*base%mod+b[i]-'a'+1)%mod;
        }	
		else
        {
		    hash=(1ll*hash*base%mod+b[i]-'A'+1)%mod;            
        }
	}
	int x=1;
	for(int i=1;i<=len2;i++)
	{
		x=1ll*x*base%mod;
	}
	int k=1;
	for(j=0;j<=len1;j++)
	{
		if((a[j]>='a'&&a[j]<='z')||(a[j]>='A'&&a[j]<='Z'))
		{
			if(a[j]>='a'&&a[j]<='z')
            {
                ha[k]=(1ll*ha[k-1]*base%mod+a[j]-'a'+1)%mod;
            }
			else if(a[j]>='A'&&a[j]<='Z')
            {
                ha[k]=(1ll*ha[k-1]*base%mod+a[j]-'A'+1)%mod;
            }
			if(k>=len2)
			{
				Hash=(mod+ha[k]-1ll*ha[k-len2]*x%mod)%mod;
				if(Hash==hash)
				{
					flag=1;
				}
			}
			k++;
		}
		else
		{
			if(flag==1)
			count++;
			flag=0;
			memset(ha,0,sizeof(a));
		    k=1;	    
		}
	}
	cout<<count;
	return 0;
}
