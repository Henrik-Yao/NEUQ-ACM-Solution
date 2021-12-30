#include<bits/stdc++.h>
using namespace std;
const int N = 2333;
int cnt, ok;
char aft[N], mid[N];
struct node {
    char v;
    int l,r;
}tree[N];

vector<char> ans;

int build(char aft[], char mid[], int len) {
    if(!len) return 0;
    int now = ++cnt;
    tree[now].v = aft[len-1];
    int i;
    for(i=0; i<len; i++)
        if(mid[i]==tree[now].v) break;
    if(i==len) {
        ok = 0;
        return -1;
    }
    ans.push_back(tree[now].v);
    tree[now].l = build(aft, mid, i);
    tree[now].r = build(aft+i, mid+i+1, len-i-1);
    return now;
}

int getdep(int now) {
    if(!now) return 0;
    return max(getdep(tree[now].l), getdep(tree[now].r)) + 1; 
}

int main() {
    while(cin>>aft>>mid) {
        cnt = 0, ok = 1;
        memset(tree, 0, sizeof(tree));
        ans.clear();
        int rt = build(aft, mid, strlen(aft));
        if(!ok) {puts("INVALID"); continue;}
        else {
            cout << getdep(rt) - 1 << "\n";
            for(auto x: ans) cout << x;
            cout << "\n";
        }
    }
    return 0;
}
