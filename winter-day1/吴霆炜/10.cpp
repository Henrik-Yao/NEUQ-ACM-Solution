#include <bits/stdc++.h>
using namespace std;
#define maxn 100

queue<int>q[maxn];
vector<int>v;
int cnt = 0;
int n;
int main(){
    scanf("%d",&n);
    v.resize(n + 1);
    for(int i = 0;i < n;i++)scanf("%d",&v[i]);
    q[0].push(v[0]);
    for(int i = 1;i < n;i++){
        bool flag = false;
        for(int j = 0;j <= cnt;j++){
            if(q[j].back() > v[i]){
                q[j].push(v[i]);
                flag = true;
                break;
            }
        }
        if(!flag){
            cnt++;
            q[cnt].push(v[i]);
        }
    }
    int pos;
    vector<int>a;
    for(int i = 0;i <= cnt;i++){
        if(q[i].back() == 1){
        pos = i;break;
        }
    }
    while(!q[pos].empty()){
        a.push_back(q[pos].front());
        q[pos].pop();
    }
    for(int i = 0;i < a.size() - 1;i++) printf("%d ",a[i]);
    printf("%d\n",a[a.size() - 1]);
    printf("%d\n",cnt + 1);
    return 0;
}