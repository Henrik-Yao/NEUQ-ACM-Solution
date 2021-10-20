#include<bits/stdc++.h>
using namespace std;
int n;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}
int solve(int k) {
	if(k==1) return 1;
	int ans = 1;
	for(int i=1; i<k; i++) 
		if(!(k%i)) ans += solve(i);
	return ans;
}
int main() {
	read(n);
	int ans = solve(n);
	printf("%d\n",ans);
	return 0;
}
