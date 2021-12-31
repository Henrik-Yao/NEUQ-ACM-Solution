
#include<bits/stdc++.h>
using namespace std;
int dp[11000];
int k[11000];
int n,i=1;int s;
int p,q,n1;
struct time1
{
	int b;
	int c;
}a[10086]; 
bool cmp(time1 s1,time1 s2)
{
	return s1.c<s2.c;
}

int main(){
	cin>>p;
for(int k=1;k<=p;k++)
{
cin>>n;
for(int i=0;i<n;i++)
{
	cin>>a[i].b>>a[i].c;
}
sort(a,a+n,cmp);
int count=1;
int j=0;
	for(int i=1;i<n;i++)
	{
		if(a[i].b>=a[j].c)
		{count++;
		j=i;
		}
	}
    cout<<n-count<<endl;
		
		}
	


}
