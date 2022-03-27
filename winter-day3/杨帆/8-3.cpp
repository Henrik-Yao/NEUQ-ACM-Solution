#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> temp;

void dfs(int cnt,int last,vector<int> &num){
    if(cnt == num.size()){
        if(temp.size() >= 2){
            ans.push_back(temp);
        }
        return;
    }
    if(num[cnt] >= last){
        temp.push_back(num[cnt]);
        dfs(cnt+1,num[cnt],num);
        temp.pop_back();
    }
    if(num[cnt] != last){
        dfs(cnt+1,last,num);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> num;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        num.push_back(a);
    }
    dfs(0,INT_MIN,num);
    cout << ans.size();
}
