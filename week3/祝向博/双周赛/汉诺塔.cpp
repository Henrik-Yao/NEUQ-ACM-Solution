#include <bits/stdc++.h>
using namespace std;

int N;
char Nam[4][100005];

inline int read() {
	int ret=0,f=1;
	char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

void dfs(int s,int t,int o,int n) {
    if (n==0) return ;
    dfs(s,o,t,n-1);
    printf("%s->%s\n",Nam[s],Nam[t]);
    dfs(o,t,s,n-1);
}

signed main() {
    N=read();
    for (int i=1; i<=3; ++i) scanf("%s",Nam[i]);
    dfs(1,3,2,N);
	return 0;
}
