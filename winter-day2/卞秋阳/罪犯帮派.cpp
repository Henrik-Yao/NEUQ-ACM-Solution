#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[1000000];
int n,m,q;int tot;
bool vis[100000];
int get(int x); 
void merge(int x,int y){
	f[get(x)]=get(y);
}
int main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
	
		f[i]=i;
	}
	
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		merge(x,y);
	}
	for(int i=1;i<=n;i++){
		if(!vis[get(i)])vis[f[i]]=1,tot++;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(f[x]==f[y])
		cout<<"In the same gang."<<endl;
		else cout<<"In different gangs."<<endl;
	}
	cout<<tot;
	return 0;
}
int get(int x)
{
	if(x==f[x])return x;
	return f[x]=get(f[x]);
}

