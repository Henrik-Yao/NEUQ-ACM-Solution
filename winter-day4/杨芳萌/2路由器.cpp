#include<bits/stdc++.h>
using namespace std;
const int N = 2333;
int n, m;
int f[N][N];void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}
void floyd() {
     for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
}

int main() {
    while(cin >> n >> m) {
        memset(f, 0x3f, sizeof(f));
        for(int i = 1; i <= n; ++i) f[i][i] = 0;
        for(int i = 1; i <= n; ++i) {
            int u, k, v;
            read(u) read(k);
            ++u;
            while(k--) {
                read(v);
				++v;
                f[u][v] = 1;
            }
        }
        floyd();
        while(m--) {
            int u, v;
            read(u), read(v);
            ++u, ++v;
            if(f[u][v] == 0x3f3f3f3f) puts("connection impossible");
            else cout << f[u][v] << "\n";
        }
    }
    return 0;
}
