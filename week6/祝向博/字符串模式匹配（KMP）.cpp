#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char a[maxn],b[maxn];
int la,lb,nxt[maxn];
int main() {
	cin>>a+1;
    cin>>b+1;
	la=strlen(a+1);
	lb=strlen(b+1);
	int j=0,Ans=0;
	for (int i=2; i<=lb; ++i) {
		while (j&&b[i]!=b[j+1]) j=nxt[j];
		if (b[j+1]==b[i]) ++j;
		nxt[i]=j;
	}
	j=0;
	for (int i=1; i<=la; ++i) {
		while (j&&b[j+1]!=a[i]) j=nxt[j];
		if (b[j+1]==a[i]) ++j;
		if (j==lb) {
			Ans++;
			j=nxt[j];
		}
	}
	printf("%d\n",Ans);
	return 0;
}
