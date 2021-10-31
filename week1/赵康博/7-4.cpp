#include <iostream>
using namespace std;

int f(int n){
    if(n==1||n==0)return 1;
    int sum = 0;
    for (int i = 0; i <= n/2; ++i) {
        if(i==0||n%i==0)sum = sum + f(i);
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}