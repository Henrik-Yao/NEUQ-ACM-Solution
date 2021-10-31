#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
int n,a[N],head[N],tail[N],ans=-1;
bool vis1[N],vis2[N];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

int main(){
	read(n);
	for(int i=1; i<=n; i++) read(a[i]);
	for(int i=1; i<=n; i++) {
		if(vis1[a[i]]==0) head[i] = head[i-1]+1;
		else head[i] = head[i-1];
		vis1[a[i]] = 1;
	}
	for(int i=n; i>=1; i--) {
		if(vis2[a[i]]==0) tail[i] = tail[i+1]+1;
		else tail[i] = tail[i+1];
		vis2[a[i]] = 1;
	}
	for(int i=1; i<n; i++) ans = max(ans, head[i]+tail[i+1]);
	printf("%d\n",ans);
    return 0;
}

