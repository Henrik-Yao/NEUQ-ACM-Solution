#include<bits/stdc++.h>
using namespace std;
const int N = 50005;
int n,a[N],m,flag;
bool vis[N]; 
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

void dfs(int s) {
	if(s>=n||s<0) return ;
	if(a[s]==0) { printf("True\n"); exit(0);} 
	if(vis[s]==1) return ; 
	vis[s] = 1;
	dfs(s+a[s]);
	dfs(s-a[s]);
	return ;
}

int main(){
	read(n);
	for(int i=0; i<n; i++) read(a[i]);
	read(m);
	dfs(m);
	printf("False\n");
    return 0;
}

