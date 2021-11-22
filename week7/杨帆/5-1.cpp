#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string> occ;
int main(){
    int m,n;
    cin >> n >> m;
    while(n--){
        string a,b;
        cin >> a >> b;
        occ[b] = a;
    }
    while(m--){
        string a;
        cin >> a;
        if(occ.count(a)){
            cout << occ[a] <<"\n";
        }
        else{
            cout << "eh\n";
        }
    }
    return 0;
}
