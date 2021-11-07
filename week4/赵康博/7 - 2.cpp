#include <iostream>
using namespace std;

int main(){
    int n;
    int a;
    cin>>n;
    long long f[41];
    f[1] = 0;
    f[2] = 1;
    f[3] = 2;
    for (int i = 4; i <= 40; ++i) {
        f[i] = f[i-1] + f[i-2];
    }
    for (int i = 0; i < n; ++i) {
        cin>>a;
        cout<<f[a];
        if(i!=n-1)cout<<endl;
    }
    return 0;
}