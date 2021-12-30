#include<bits/stdc++.h>
using namespace std;

struct Info{
    string name;
    int goal;
};

// int get(string &str){
//     int ans;
//     for(int i=0; i<str.size(); i++){
    
//     }
// }

bool cmp(Info a,Info b){
    if(a.goal == b.goal){
        return a.name < b.name;
    }
    return a.goal > b.goal;
}

int main(){
    int n;
    Info info[100];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> info[i].name >> info[i].goal;
    }
    sort(info,info+n,cmp);
    for(int i=0; i<n; i++){
        cout << info[i].name << " " << info[i].goal;
        if(i < n-1)     cout << endl;
    }
    return 0;
}
