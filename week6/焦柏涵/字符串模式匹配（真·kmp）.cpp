#include <bits/stdc++.h>
using namespace std;
char t[1000001],p[1000001];
int nt,np,nex[1000001]={0},sum=0;//nextÊÇ¹Ø¼ü´Ê 
void pipei(int l)
{
	int i=0,j=-1;
	nex[0]=-1;
	while(i<l)
	{
		if(j==-1||p[i]==p[j])
		{
			i++;j++;
			nex[i]=j;
		}
		else j=nex[j];
	}
}
void kmp()
{
	int i=0,j=0;
	while(i<nt)
	{
		if(j==-1||t[i]==p[j])
		{
			i++;j++;
		}
		else j=nex[j];
		if(j==np)
		{
			sum++;j=nex[j-1];i--;
		}
	}
}
int main()
{
	cin>>t>>p;
	nt=strlen(t);np=strlen(p);
	pipei(np);
	kmp();
	cout<<sum;
	return 0;
}
