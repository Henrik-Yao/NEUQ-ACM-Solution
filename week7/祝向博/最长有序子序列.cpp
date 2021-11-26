#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5; 

int Len,sta[maxn],N;

inline int read() {
	int ret=0,f=1;char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

inline int Find(int x) {
	int L=1,R=Len,mid,ret=1;
	while (L<=R) {
		mid=L+(R-L>>1);
		if (sta[mid]>=x) ret=mid,R=mid-1;
		else L=mid+1;
	}
	return ret;
}

int main() {
	for (int T=read(); T--; ) {
		N=read(),Len=0;
		for (int i=1; i<=N; ++i) {
			int x=read();
			if (Len==0||sta[Len]<x) sta[++Len]=x;
			else sta[Find(x)]=x;
		}
        if (T) printf("%d\n\n",Len);
        else printf("%d",Len);
	}
	return 0;
}
