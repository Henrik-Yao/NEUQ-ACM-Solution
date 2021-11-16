#include<bits/stdc++.h>
using namespace std;

bool prime(int x){
    for(int i=3; i<=x/i; i++){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int temp;
        cin >> temp;
        if(temp % 2 == 0){
            cout << 2 << "\n";
        }
        else if(prime(temp)){
            cout << 1 << "\n";
        }
        else if(prime(temp-2)){
            cout << 2 << "\n";
        }
        else{
            cout << 3 << "\n";
        }
    }
}
