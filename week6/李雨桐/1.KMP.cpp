#include<bits/stdc++.h>
using namespace std;

int Next[1000005];
int ans=0;
string t,p;

void getnext()
{
	Next[0]=-1;
	int k=-1,j=0;
    int len = p.size();

	while(j<len)
	{
		if(k==-1||p[k]==p[j])
		{
			j++; k++;
			Next[j]=k;
		}
		else
			k=Next[k];
	}
	return;
}
void kmp(string x,string y)
{
	int i=0,j=0;

	int len1 = x.size();
	int len2 = y.size();

	while(i < len1)
	{
		if(j==-1||x[i]==y[j])
		{
			j++; i++;
		}
		else
			j=Next[j];

		if(j >= len2)
		{
			ans++;
			j=Next[j];
		}
	}
	return;
}

int main()
{
	cin>>t>>p;

	getnext();
	kmp(t,p);

	cout<<ans;
}
