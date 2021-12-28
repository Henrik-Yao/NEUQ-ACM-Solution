
#include <bits/stdc++.h>
using namespace std;
#define maxn 101

int n,m;
int in[maxn];
vector<int>edge[maxn];
vector<int>ans;
queue<int>q;
int main(){
    while(scanf("%d%d",&n,&m) != EOF){
        bool flag = false;
        int cnt_in = 0;
        for(int i = 1;i <= m;i++){
            int d,u;
            scanf("%d%d",&d,&u);
            edge[d].push_back(u);
            in[u]++;
        }
        for(int i = 1;i <= n;i++){
            if(in[i] == 0){
                q.push(i);
                cnt_in++;
            }
        }
        if(cnt_in > 1) flag = true;
        while(!q.empty()){
            int p = q.front();q.pop();
            ans.push_back(p);
//            int cnt_inn = 0;
            for(int i = 0;i < edge[p].size();i++){
                int y = edge[p][i];
                in[y]--;
                if(!in[y]){
                    q.push(y);
//                    cnt_inn ++;
                }
            }
//            if(cnt_inn > 1)flag = true;
        }
        if(ans.size() == n){
            if(!flag)
            puts("1");
            else 
            puts("2");
        }
        else puts("0");
        for(int i = 0;i < m;i++)
        edge[i].clear();
        ans.clear();while(!q.empty())q.pop();memset(in,0,sizeof(in));
    }
    return 0;
}