
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f
#define maxn 101
typedef long long ll;

int mp[maxn][maxn];
int n,m,a,b,c;
int ans;
//floyd算法
int main(){
    while(scanf("%d%d",&n,&m) != EOF){
    memset(mp,inf,sizeof(mp));
    int a,b,c;
    for(int i = 0;i < n;i++){
        scanf("%d%d",&a,&c);
        for(int j = 0;j < c;j++){
            scanf("%d",&b);
            if(a == b)mp[a][b] = 0;
            else{    
            mp[a][b] = 1;
            //mp[b][a] = 1;
        }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < n;k++){
                if(mp[j][k] > mp[j][i] + mp[i][k])
                mp[j][k] = mp[j][i] + mp[i][k];
            }
        }
    }
    int from,to;
    for(int i = 0;i < m;i++){
        scanf("%d%d",&from,&to);
    ans = mp[from][to];
    if(ans > 0x3f)puts("connection impossible");
    else
    printf("%d\n",ans);
    }
    }
    return 0;
}