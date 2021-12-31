#include<bits/stdc++.h>
using namespace std;
int n,cnt;
bool vis[10];
char a[10],ans[10];
string nt[100000];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

bool cmp(string a,string b) {
	return a<b;
}

void solve(int k) {
	if(k==n) {
		cnt++;
		for(int i=0; i<n; i++) nt[cnt] += ans[i];
		return;
	}
	for(int i=0; i<n; i++) {
		if(vis[i]==0) {
			vis[i] = 1;
			ans[k] = a[i];
			solve(k+1);
			vis[i] = 0;
		} 		
	}
	return;
}

int main(){
	scanf("%s",a);
	n = strlen(a);
	solve(0);
	sort(nt+1,nt+1+cnt,cmp);
	for(int i=1; i<=cnt; i++) cout<<nt[i]<<endl;
    return 0;
}

