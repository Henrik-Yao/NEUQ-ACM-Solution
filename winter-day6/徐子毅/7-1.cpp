#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        if(n==1){
            int num;
            cin >> num;
            cout << num << endl;
            continue;
        }
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=2;i<=n;i++){
        sort(a,a+i);
        cout << a[0];
        for(int i=1;i<n;i++) cout << " " << a[i];
        cout << endl;
    }
    }
    return 0;
}