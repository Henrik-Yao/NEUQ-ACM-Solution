#include<bits/stdc++.h> 
using namespace std;
int T,n,a[100001],f[100001];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}
int main() {
	read(T);
    while(T--) {
    	int ans = 0;
    	memset(f,0,sizeof(f));
    	memset(a,0,sizeof(a));
    	read(n);
    	for(int i=1; i<=n; i++) read(a[i]);
    	for(int i=1; i<=n; i++) {
    		int tmp=0;
      		for(int j=i-1; j>0; j--)
        		if(a[i]>a[j] && f[j]>tmp) tmp = f[j];
            f[i] = tmp + 1;
        	ans = max(ans,f[i]);
    	}
    	printf("%d\n",ans);
    	if(T) puts("");
	}
	return 0;
}
