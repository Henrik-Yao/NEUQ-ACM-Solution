#include<bits/stdc++.h>
using namespace std;
int n,m,a[23333],b[23333],cnt=1;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}
bool cmp(int a, int b) { return a>b; }
int main(){
	read(n), read(m);
	for(int i=1; i<=n; i++) read(a[i]);
	sort(a+1,a+1+n,cmp);
	int ans = a[1]-a[n]+1;
	for(int i=1; i<=n; i++) b[i] = a[i]-a[i+1]-1;
	sort(b+1,b+n,cmp);
	for(int i=1; i<n; i++) 
		if(cnt<m) {
			ans -= b[i];
			cnt++;
		}
	printf("%d\n",ans);
    return 0;
}
