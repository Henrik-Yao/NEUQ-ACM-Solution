#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,p,n;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

int pow(int a, int b, int p){
	int r = 1;
	while(b){
		if(b&1) r = r*a %p;
		a = a*a %p;
		b>>=1; 
	} 
	return r%p;
} 
signed main(){
	read(n);
	while(n--) {
		read(a), read(b), read(p);
		int ans = pow(a,b,p);
		printf("%lld\n",ans);
	}
	return 0;
}

