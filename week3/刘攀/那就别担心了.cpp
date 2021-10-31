#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[505][505];
int b[505];
long long sum=0;
int from,to;
bool flag=1;
int f(int from){
	bool count=0;
	if(b[from]) return b[from];
	for(int i=1;i<=n;i++){
		if(a[from][i]){
			b[from]+=f(i);
			count=1;
		}
	}
		if(!count) flag=0;
		return b[from];
}
int main(){
	cin>>n>>m;
	int t1,t2;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i=0;i<m;i++){
		cin>>t1>>t2;
		a[t1][t2]=1;
	}
	cin>>from>>to;
	b[to]=1;
	sum=f(from);
	cout<<sum<<" ";
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
