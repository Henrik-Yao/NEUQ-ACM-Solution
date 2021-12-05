#include <bits/stdc++.h>
using namespace std;

long f[100],n;

int main(){
    f[1] = 1,f[2] = 2,f[3] = 4;
    for(int i=4; i<=50; i++){
        f[i] = f[i-1] + f[i-2] + f[i-3];
    }
    while(cin >> n){
        cout << f[n] << endl;
    }
    return 0;
}
