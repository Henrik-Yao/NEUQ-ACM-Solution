#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
bool jud;
int br,fu[maxn],mu[maxn];
bool ju[maxn];
char sex[maxn];
void wufu(int n,int dai)
{
    if(dai>5||n==-1||n==0) return ;
    if(ju[n]) jud=1;
    ju[n]=1;
    wufu(fu[n],dai+1);
    wufu(mu[n],dai+1);
    return ;
}
int main()
{
    int n;
	cin>>n;
	while(n--)
	{
		cin>>br;
		cin>>sex[br]>>fu[br]>>mu[br];

	}
	int k,man,wo;
	cin>>k;
	while(k--)
	{
		cin>>man>>wo;
		if(sex[man]==sex[wo]) 
		{
			cout<<"Never Mind"<<'\n';
			continue;
		}
		memset(ju,0,sizeof(ju));
		jud=0;
		wufu(man,1);
		wufu(wo,1);
		if(jud==0) cout<<"Yes"<<'\n';
		else cout<<"No"<<'\n';
	}
	return 0;
}