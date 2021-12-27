#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec;
    int a[100];
    int ans = 0,n;
    cin >> n;
    a[0] = n+1;
    for(int i=1; i<=n; i++){
        int iden = 0,x;
        cin >> x;
        for(int j=1; j<=ans; j++){
            if(a[j] > x && a[j] < a[iden]){
                iden = j;
            }
        }
        if(iden == 0){
            a[++ans] = x;
        }
        else{
            a[iden] = x;
        }
        if(iden == 1 || iden == 0 && ans == 1){
            vec.push_back(x);
        }
    }
    for(int i=0; i<vec.size()-1; i++){
        cout << vec[i] << " ";
    }
    cout << vec[vec.size()-1] << endl << ans;
    return 0;
}
