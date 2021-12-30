#include<bits/stdc++.h>
using namespace std;

int f[10000];

void deal(int f[],int n){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(f[i] == f[j]+1 || f[i] == f[j]-1){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> f[i];
    }
    deal(f,n);
    return 0;
}
