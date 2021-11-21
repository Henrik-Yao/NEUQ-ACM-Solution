#include <iostream>
using namespace std;

long long h(int n, long long now){
    if(n == 1) return now + 2;
    return h(n-1, now)*3 +2;
}

int main(){
    int n;
    while(cin >> n){
        cout << h(n, 0) << endl;
    }
}