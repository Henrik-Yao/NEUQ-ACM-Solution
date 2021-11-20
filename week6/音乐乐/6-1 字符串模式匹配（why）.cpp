#include<iostream> 
using namespace std;
string str,S;
int hashh[1000005],hashstr=0;
long long subhash=0;
int base=13331,mod=1e9+7;
int cnt=0;

int main()
{
	cin>>S>>str;
	int i,j;
	//cout<<"base "<<base<<endl;
	for(i=0;i<str.size();i++)
	{
		hashstr=(1ll*hashstr*base%mod+str[i]-'A'+1+mod)%mod;
		//一般而言需要-'A'+1，也就是'A'对应的hash值为1，如果'A'对应的hash值为0则容易冲突
	}
	int len=str.size();
	int p=1;
	for(i=1;i<=len;i++)
	{
		p=1ll*p*base%mod;
	}
	hashh[0]=(S[0]-'A'+1+mod)%mod;
	for(i=1;i<S.size();i++)
	{
		hashh[i]=(1ll*hashh[i-1]*base%mod+S[i]-'A'+1+mod)%mod;
		if(i>=len-1)
		{
			if(i==len-1)
			subhash=hashh[len-1];
			else if(i>len-1)
			{
				subhash=(mod+hashh[i]-1ll*hashh[i-len]*p%mod)%mod;
			}
			//cout<<"subhash "<<subhash<<endl;
			if(subhash==hashstr)
				cnt++;
			//cout<<cnt<<endl;
		}
	}
	cout<<cnt;
	return 0;
}
