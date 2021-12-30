#include<bits/stdc++.h>
using namespace std;
const int k = 1e5+10;
int vis[k];

int main(){
    int n;
    cin >> n;
    int max_ = -2;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        vis[temp]++;
        if(max_ < temp)
            max_ = temp;
    }
    for(int i=0; i<=max_; i++){
        if(vis[i]){
            cout << i << ":" << vis[i] << endl;
        }
    }
}
