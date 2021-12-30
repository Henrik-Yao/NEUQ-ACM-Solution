#include<bits/stdc++.h>
using namespace std;
const int MIN = -0x7fffffff;
const int N = 23;
int n,maxd,cnt,pre[N],mid[N],root;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

struct node {
    int v,l,r;
}tree[N];

vector<int> ans[N];

int build(int pre[], int mid[], int len) {
    if(len==0) return 0;
    int now = ++cnt;
    tree[now].v = pre[1];
    int i;
    for(i=1; i<=len; i++) if(mid[i]==tree[now].v) break;
    tree[now].l = build(pre+1, mid, i-1);
    tree[now].r = build(pre+i, mid+i, len-i);
    return now;
}

int solve(int now, int dep) {
    if(now==0) return 0;
    ans[dep].push_back(tree[now].v);
    maxd = max(maxd, solve(tree[now].l, dep+1));
    maxd = max(maxd, solve(tree[now].r, dep+1));
    return maxd+1;
}

int main() {
    read(n);
    for(int i=1; i<=n; i++) read(pre[i]);
    for(int i=1; i<=n; i++) read(mid[i]);
    root = build(pre, mid, n);
    solve(root,1);
    for(int i=1; i<=maxd; i++) 
    	for(int j=0; j<ans[i].size(); j++) printf("%d ",ans[i][j]);
    return 0;
}
