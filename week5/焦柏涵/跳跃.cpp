#include <bits/stdc++.h>
using namespace std;
int n,m[50001],v[50001],flag=1;
void move(int i)
{
	v[i]=1;
	if(flag==0||i>n||i<1) return;
	if(m[i]==0)
	{
		flag=0;
		return;
	}
	if(v[i-m[i]]!=1) move(i-m[i]);
	if(v[i+m[i]]!=1) move(i+m[i]);
}
int main()
{
	int start;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>m[i];
	cin>>start;
	move(start+1);//start是从0开始的 
	if(flag==0) cout<<"True";
	else cout<<"False";
	return 0; 
}
