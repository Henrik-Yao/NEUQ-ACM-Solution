#include<bits/stdc++.h>
using namespace std;
int n,q,flag;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

map<string, string> fa, ma, sex;
set<string> S;

void up(string x, int dis) {
    if(x=="" || x=="-1" || dis>5) return;
    if(S.count(x)) {flag = 1; return;}
    S.insert(x);
    up(fa[x], dis+1);
    up(ma[x], dis+1);
}

int main() {
    read(n);
    for(int i=1; i<=n; i++) {
        string a, b, c, d;
        cin>>a>>b>>c>>d;
        sex[a] = b;
        sex[c] = "M";
        sex[d] = "F";
        fa[a] = c;
        ma[a] = d;
    }
    read(q);
    while(q--) {
        string a, b;
        cin >> a >> b;
        if(sex[a]==sex[b]) printf("Never Mind");
        else {
            flag = 0; 
			S.clear();
            up(a, 1);
			up(b, 1);
            if(flag) printf("No");
            else printf("Yes");
        }
        if(q) printf("\n");
    }
    return 0;
}
