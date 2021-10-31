#include <bits/stdc++.h>
using namespace std;

char s[1000005],Ans[1000005];
int cnt[10000],len;

inline int read() {
	int ret=0,f=1;
	char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

void dfs(int x) {
    if (x==len) {
        puts(Ans);
        return ;
    }
    for (int i=0; i<26; ++i) {
        if (cnt[i]) {
            cnt[i]--;
            Ans[x]=i+'a';
            dfs(x+1);
            cnt[i]++;
        }
    }
}

signed main() {
    scanf("%s",s);
    len=strlen(s);
    for (int i=0; i<len; ++i) {
        ++cnt[s[i]-'a'];
    }
    dfs(0);
	return 0;
}
