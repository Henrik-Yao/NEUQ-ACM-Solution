#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,f[233];

signed main(){
	while(cin>>n) {
		memset(f,0,sizeof(f));
		f[1] = 1;
		f[2] = 2;
		f[3] = 4;
		if(n>3) for(int i=4; i<=n; i++) f[i] = f[i-1]+f[i-2]+f[i-3];
		printf("%lld\n",f[n]);
	}
    return 0;
}

