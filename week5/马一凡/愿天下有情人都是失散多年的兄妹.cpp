#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5 + 10;
int N, Q;
int prefa[maxn], premot[maxn];
int sex[maxn];
 
void init() {
    memset(prefa, -1, sizeof(prefa));
    memset(premot, -1, sizeof(premot));
}
 
bool CanMerry(int x, int y, int step) {
    if(x == -1 && y == -1) return true;
    if((prefa[x] != -1 && prefa[x] == prefa[y]) || (premot[x] != -1 && premot[x] == premot[y]))
        return false;
 
    step ++;
    if(step >= 4) return true;
 
    return CanMerry(premot[x], premot[y], step) &&
            CanMerry(prefa[x], prefa[y], step) &&
            CanMerry(prefa[x], premot[y], step) &&
            CanMerry(premot[x], prefa[y], step);
}
 
int main() {
    scanf("%d", &N);
    init();
    for(int i = 0; i < N; i ++) {
        int child, fa, mot;
        string s;
        scanf("%d", &child);
        cin >> s;
        scanf("%d%d", &fa, &mot);
        if(s == "M") sex[child] = 1;
        else if(s == "F") sex[child] = 0;
 
        prefa[child] = fa;
        premot[child] = mot;
 
        if(fa != -1) sex[fa] = 1;
        if(mot != -1) sex[mot] = 0;;
    }
 
    scanf("%d", &Q);
    while(Q --) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(sex[a] == sex[b]) printf("Never Mind\n");
        else {
            if(CanMerry(a, b, 0)) printf("Yes\n");
            else printf("No\n");
        }
    }
 
    return 0;
}

