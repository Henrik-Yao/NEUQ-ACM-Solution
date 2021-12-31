#include <bits/stdc++.h>
using namespace std;
const int M=25;
struct per
{
	string na;
	int gr;
}p[M];
bool cmp(per a,per b)
{
	if(a.gr==b.gr){return a.na<b.na;}
	else{return a.gr>b.gr;}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>p[i].na>>p[i].gr;
	}
	sort(p,p+n,cmp);
	for(int i=0;i<n;i++){cout<<p[i].na<<" "<<p[i].gr<<endl;}
	return 0;
}
