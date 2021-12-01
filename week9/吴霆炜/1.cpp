#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fd(i,l,r) for(register int i = l;i <= r;i++)

vector<int>p;
int n;
signed main(){
    p.resize(51);
    p[1] = 1;p[2] = 2;p[3] = 4;
    fd(i,4,50)
    p[i] = p[i - 1] + p[i - 2] + p[i - 3];
    while((scanf("%lld",&n)) != EOF)
    printf("%lld\n",p[n]);
    return 0;
}
