#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x){
    for(int i = 2;i <= sqrt(x);i++){
        if(x % i == 0)
        return false;
    }
    return true;
}

int main(){
    int N;
    cin>>N;
    while(N--){
        int a;
        cin>>a;
        if(a % 2 == 0)
        puts("2");
        else if(is_prime(a))
        puts("1");
        else{
            if(is_prime(a - 2))
            puts("2");
            else
            puts("3");
        }
    }
    return 0;
}