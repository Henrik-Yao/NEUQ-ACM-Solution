#include<bits/stdc++.h>
using namespace std;
const int k = 1e5;
bool vis[k];
int m[k];
queue <int> que;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> m[i];
    }
    int temp;
    cin >> temp;
    que.push(temp);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        if(m[now] == 0){
            cout << "True";
            return 0;
        }
        int temp = now + m[now];
        if(temp < n && !vis[temp]){
            vis[temp] = 1;
            que.push(temp);
        }
        temp = now - m[now];
        if(temp >= 0 && !vis[temp]){
            vis[temp] = 1;
            que.push(temp);
        }
    }
    cout << "False";
    return 0;
}
