#include<bits/stdc++.h>
using namespace std;
const int N = 2333;
const int MIN = -0x7fffffff;
int maxd,cnt,ans=MIN,root,pos;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

struct node {
    int l,r,d,v;
}tree[N];

vector<node> a[N];

void build(int &now, int d) {
    int x; 
    read(x);
    if(!x) return;
    cnt++;
    now = cnt;
    tree[now].v = x;
    tree[now].d = d;
    build(tree[now].l, d+1);
    build(tree[now].r, d+1);
    if(tree[now].l==0 && tree[now].r==0) {
        a[d].push_back(tree[now]);
        maxd = max(maxd, d);
    }
}

int main() {
    build(root, 0);
    for(int i = maxd; i>=0; --i) {
        int res = 0;
        if(!a[i].size()) continue;
        for(int j=0; j<a[i].size(); j++) res += a[i][j].v;
        if(res > ans) {
            ans = res;
            pos = i;
        }
    }
    cout << pos << endl;
    return 0;
}
