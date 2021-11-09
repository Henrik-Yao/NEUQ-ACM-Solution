#include <bits/stdc++.h>
using namespace std;

bool Flag;
int N,tot,f[100005];

struct Person {
	int fa=-1,ma=-1;
	bool man;
} a[100005];

inline int read() {
	int ret=0,f=1;char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f; 
}

void DFS_A(int x,int o) {
	f[++tot]=x;
	if (o==0) return ;
	if (a[x].fa>=0) DFS_A(a[x].fa,o-1);
	if (a[x].ma>=0) DFS_A(a[x].ma,o-1);
}

void DFS_B(int x,int o) {
	if (!Flag) return ;
	for (int i=1; i<=tot; ++i) {
		if (f[i]==x) {Flag=0;break;}
	}
	if (o==0||!Flag) return ;
	if (a[x].fa>=0) DFS_B(a[x].fa,o-1);
	if (a[x].ma>=0) DFS_B(a[x].ma,o-1);
}

void Solve(int a,int b) {
	tot=0,Flag=1;
	DFS_A(a,4);
	DFS_B(b,4);
	puts(Flag?"Yes":"No");
}

int main() {
	N=read();
	for (int i=1; i<=N; ++i) {
		int id=read();
		a[id].man=(getchar()=='M');
		a[a[id].fa=read()].man=1;
		a[a[id].ma=read()].man=0;
	}
	for (int T=read(); T--; ) {
		int A=read(),B=read();
		if (a[A].man==a[B].man) puts("Never Mind");
		else Solve(A,B);
	}
	return 0;
}
