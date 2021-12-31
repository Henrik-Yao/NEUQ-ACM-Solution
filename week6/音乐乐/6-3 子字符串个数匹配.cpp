#include<bits/stdc++.h>
using namespace std;
int base=13331,mod=1e7+7;
int ha[10000][10000];

int main()
{
	int k=1,p=0;
	int flag=0;
	while(1)
	{
		char t=getchar();
		//cout<<"get "<<t<<endl;
		if(t=='\n')
		{
			ha[0][p]=k-1;
			break;
		}
		if((t>='a'&&t<='z')||(t>='A'&&t<='Z'))
		{
			flag=0;
			//cout<<"in "<<t;
			if(t>='a'&&t<='z')
			{
				ha[k][p]=(1ll*ha[k-1][p]*base%mod+t-'a'+1)%mod;
			}
			else
			{
				ha[k][p]=(1ll*ha[k-1][p]*base%mod+t-'A'+1)%mod;
			}
			//printf("ha[%d][%d]=%d\n",k,p,ha[k][p]);
			//cout<<"k "<<k<<endl;
			k++;
		}
		else
		{
			if(flag==1)
			continue;
			ha[0][p]=k-1;
		    k=1;
			p++;
			flag=1;
			//cout<<"P "<<p<<endl;
		}
	}
	//cout<<"×îºóµÄp"<<p<<endl;
	string s;
	cin>>s;
	int cnt=0;
	int haxi=0;
	int len=s.size();
	int mi=1;
	for(int i=1;i<=len;i++)
	{
		mi=1ll*mi*base%mod;
	}
	for(int i=0;i<len;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		haxi=(1ll*haxi*base%mod+s[i]-'a'+1)%mod;
		else
		haxi=(1ll*haxi*base%mod+s[i]-'A'+1)%mod;
	}
	//cout<<"haxi"<<haxi<<endl;
	int subhash=0;
	for(int i=0;i<=p;i++)
	{
		for(int j=len;j<=ha[0][i];j++)
		{
			subhash=(mod+ha[j][i]-1ll*ha[j-len][i]*mi%mod)%mod;
			//cout<<j<<' '<<i<<" subhash"<<subhash<<endl;
			if(subhash==haxi)
			{
				cnt++;
				//cout<<"cnt"<<cnt<<endl;
				break;
			}
		}
		//cout<<"i"<<i<<endl;
	}
	cout<<cnt<<endl;
	return 0;
}
