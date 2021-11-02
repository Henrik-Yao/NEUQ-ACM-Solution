#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e5+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int L, R, N, vis[_];
void Euler() {
    vis[1] = 0;
    for(int i = 2; i <= N; ++i) {
        if(!vis[i]) {
            for(int j = i + i; j <= N; j += i) {
                vis[j] = 1;
            }
        }
    }
}
int main() {
    N = 10000;
    Euler();
    while(~scanf("%d%d", &L, &R)) {
        vector<int> a;
        for(int i = L; i <= R; ++i) {
            if(!vis[i]) a.push_back(i);
        }
        for(int i = 0; i < (int)a.size(); ++i) {
            cout << a[i];
            if(i == (int)a.size() - 1);else {
                cout << " ";
            }
        }
        puts("");
    }
    return 0;
}