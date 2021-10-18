#include <bits/stdc++.h>
using namespace std;

int fun(int x){
    if(x == 1)return 1;
    int sum = 1;
    int i;
    for(i = 1;i <= x / 2;i++){
    if(x % i == 0){
            sum += fun(i);
    }
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    fun(n);
    if(n != 0)
    cout<<fun(n);
    else
    puts("0");
    return 0;
}