#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,tmp,now,ans=0;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

signed main(){
	read(n); 
	for(int i=1; i<=n; i++) {
		read(tmp);
		now += tmp;
		if(now>ans) ans = now;
		if(now<0) now = 0;
	}
	cout<<ans<<endl;
    return 0;
}

