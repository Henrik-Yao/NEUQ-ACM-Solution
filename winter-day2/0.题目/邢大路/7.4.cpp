#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int height[maxn];
int a[maxn];
int n,m,q;
int find(int x){
	if(a[x]==x)return x;
	else x=find(a[x]);
	return x;
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(height[x]==height[y]){
        height[x]++;
        a[y]=x;
    }
    else{
        if(height[x]<height[y])a[x]=y;
        else a[y]=x;
    }
} 
int main(){
    cin>>n>>m>>q;
    memset(height,0,n+1);
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    int x,y;
    while(m--){
    	cin>>x>>y;
    	a[y]=x;
	}
	while(q--){
		cin>>x>>y;
		if(find(x)==find(y))cout<<"In the same gang"<<endl;
		else cout<<"In different gangs"<<endl;
	}
	int count=0;
	for(int i=1;i<=n;i++)if(a[i]==i)count++;
	cout<<count;
}
