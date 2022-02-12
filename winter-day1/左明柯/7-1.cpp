#include <bits/stdc++.h>
#define lowbit(i)((i)&(-i)) 
using namespace std;
const int maxn=1e6+10;
int n,q;
long long c[maxn];
void hh(int x,int v){
	for(int i=x;i<=n;i=i+lowbit(i)){
		c[i]=c[i]+v;
	}
}
long long getsum(int x){
	long long sum=0;
	for(int i=x;i>0;i=i-lowbit(i)){
		sum=sum+c[i];
	}
	return sum;
}
int main(){
cin>>n>>q;
memset(c,0,sizeof(c));
for(int i=1;i<=n;i++){
	int ans;
	cin>>ans;
	hh(i,ans);
}
while(q--){
	int x,y,z;
	cin>>x>>y>>z;
	if(x==1){
		hh(y,z);
	} 
	else{
		cout<<getsum(z)-getsum(y-1)<<endl;
	}
}

return 0;

}
