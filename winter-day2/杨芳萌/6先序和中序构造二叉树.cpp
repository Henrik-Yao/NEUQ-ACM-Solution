#include<bits/stdc++.h>
using namespace std;
const int MIN = -0x7fffffff;
const int N = 23;
int n,cnt,pre[N],mid[N],root;
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

void print(int now) {
    if(now==0) return;
    print(tree[now].l);
    print(tree[now].r);
    printf("%d ",tree[now].v);
}

int main() {
    read(n);
    for(int i=1; i<=n; i++) read(pre[i]);
    for(int i=1; i<=n; i++) read(mid[i]);
    root = build(pre, mid, n);
    print(root);
    return 0;
}
