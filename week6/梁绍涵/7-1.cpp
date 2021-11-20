#include<bits/stdc++.h>
using namespace std;
int nxt[1000001];
string t,p;
void getn()
{
	nxt[0]=-1;
	int lenp=p.size();
	int k=-1,j=0;
	while(j<lenp)
	{
		if(k==-1||p[k]==p[j])
		{
			j++;
			k++;
			nxt[j]=k;
		}
		else
			k=nxt[k];
	}
	return ;	
}
int KMP(string a,string b)
{
	int ans=0;
	int i=0,j=0;
	int lena=a.size();
	int lenb=b.size();
	while(i<lena)
	{
		if(j==-1||a[i]==b[j])
		{
			j++;
			i++;
		}
		else
		{
			j=nxt[j];
		}
		if(j>=lenb)
		{
			ans++;
			j=nxt[j];
		}
	}
	return ans;
}
int main()
{
	cin>>t>>p;
	getn();
	cout<<KMP(t,p);
}
