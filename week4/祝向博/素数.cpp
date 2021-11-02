#include <bits/stdc++.h>
using namespace std;

const int maxn=100005;
bool isp[maxn];
int cnt,p[maxn];

inline int read() {
	int ret=0,f=1;char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

int main() {
	memset(isp,1,sizeof isp);
	isp[1]=0,cnt=0;
	for (int i=2; i<maxn; ++i) {
		if (isp[i]) {
			p[++cnt]=i;
		}
		for (int j=1; j<=cnt&&i*p[j]<maxn; ++j) {
			isp[i*p[j]]=0;
			if (i%p[j]==0) break;
		}
	}
	int L,R;
	while (~scanf("%d%d",&L,&R)) {
		for (int i=1; i<=cnt; ++i) {
			if (p[i]>=L&&p[i]<=R) {
				if (p[i+1]>R) printf("%d",p[i]);
				else printf("%d ",p[i]);
			}
		}
//		for (int i=L; i<=R; ++i) if (isp[i]) printf("%d ",i);
		puts("");
	}
	return 0;
}
