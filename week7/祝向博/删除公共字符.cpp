#include <bits/stdc++.h>
using namespace std;
int len;
char s[1000000],F[500];
bool cnt[500];

int main() {
	while (cin.getline(s,1000000)) {
		cin.getline(F,500);
	    len=strlen(s);
	    memset(cnt,0,sizeof cnt);
	    for (int i=0; F[i]; ++i) cnt[int(F[i])]=1;
	    for (int i=0; i<len; ++i) {
	    	if (!cnt[int(s[i])]) putchar(s[i]);
		}
		puts("");
	}
    return 0;
}
