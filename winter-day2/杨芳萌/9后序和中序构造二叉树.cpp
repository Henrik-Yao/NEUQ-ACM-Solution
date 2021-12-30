#include<bits/stdc++.h>
using namespace std;
const int N = 2333;
int n,cnt,aft[N],mid[N],root,maxd;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

struct node {
    char v;
    int l,r;
}tree[N];

vector<int> ans;

int build(int aft[], int mid[], int len) {
    if(!len) return 0;
    int now = ++cnt;
    tree[now].v = aft[len-1];
    int i;
    for(i=0; i<len; i++) if(mid[i]==tree[now].v) break;
    ans.push_back(tree[now].v);
    tree[now].l = build(aft, mid, i);
    tree[now].r = build(aft+i, mid+i+1, len-i-1);
    return now;
}

int main() {
    read(n);
    for(int i=0; i<n; i++) read(aft[i]);
    for(int i=0; i<n; i++) read(mid[i]);
    root = build(aft, mid, n);
    for(int i=0; i<ans.size(); i++) printf("%d ",ans[i]);
    return 0;
}
