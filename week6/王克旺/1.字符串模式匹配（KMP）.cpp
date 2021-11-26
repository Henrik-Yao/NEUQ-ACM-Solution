#include<iostream>
#include<cstring>
using namespace std;
char t[1000001],p[1000001];
int nt[1000001];
void Next(char p[])
{
	int i=0,j=-1,len=strlen(p);
	nt[0]=-1;
	while(i<len)
	{
		if(j==-1||p[i]==p[j])
		{
			i++;
			j++;
			nt[i]=j;
		}
		else
		{
			j=nt[j];
		}
	}
}
int kmp(char t[],char p[])
{
	int i=0,j=0,count=0,len1=strlen(t),len2=strlen(p);
	while(i<len1&&j<len2)
	{
		if(j==-1||t[i]==p[j])
		{
			i++;
			j++;
		}
		else
		{
			j=nt[j];
		}
		if(j==len2)
		{
		    count++;
			j=nt[len2-1];
			i--;	
		}
	}
	return count; 
}
int main()
{
	cin>>t;
	cin>>p;
	Next(p);
	cout<<kmp(t,p);
}
