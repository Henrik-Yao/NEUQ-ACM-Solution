#include<bits/stdc++.h>
using namespace std;
#define lobit(i) ((i)&(-i))
long long  c[1000005];
int n,q;
void update(int a,int b){
	for(int i=a;i<=n;i+=lobit(i)){
		c[i]+=b;
	}
}
long long getsum(int a){
	long long sum=0;
	for(int i=a;i>0;i=i-lobit(i)){
		sum+=c[i];
	}
	return sum;
}
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		update(i,a);
	}
	while(q--){
		int x,y,z;
		cin>>x>>y>>z;
		if(x==1) update(y,z);
		else {
			cout<<getsum(z)-getsum(y-1)<<endl;
		}
	}
}
