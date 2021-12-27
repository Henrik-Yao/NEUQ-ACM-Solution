#include<bits/stdc++.h>
using namespace std;
int x,y,n,m,q,fa[1010],pan[1010],cnt=0;
int findd(int x){
	if(fa[x]==x)return x;
	else return fa[x]=findd(fa[x]);
}

int main(){
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		if(findd(x)!=findd(y)){
			fa[findd(x)]=findd(y);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(findd(x)==findd(y))
		cout<<"In the same gang.";
		else
		cout<<"In different gangs.";
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		if(pan[findd(i)]==0){
			pan[findd(i)]=1;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
