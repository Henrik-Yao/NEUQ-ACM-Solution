#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f
#define maxn 101
typedef long long ll;

int m[maxn][maxn];
ll dis[maxn];
int n,e,a,b,c;

//floyd算法
int main(){
    while(scanf("%d%d",&n,&e) != EOF){
    memset(m,inf,sizeof(m));memset(dis,0,sizeof(dis));
    int a,b,c;
    for(int i = 1;i <= e;i++){
        scanf("%d%d%d",&a,&b,&c);
        ++a,++b;
        if(a == b)m[a][b] = 0;
        else{    
        m[a][b] = c;
        m[b][a] = c;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                if(m[j][k] > m[j][i] + m[i][k])
                m[j][k] = m[j][i] + m[i][k];
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i != j)dis[i] = dis[i] + (ll)m[i][j];
        }
    }
    int pos = 1,_min = 0x3f3f3f3f;
    for(int i = 1;i <= n;i++){
        if(dis[i] < _min){
            _min = dis[i];
            pos = i;
        }
    }
    --pos;
    printf("%d\n",pos);
    }
    return 0;
}