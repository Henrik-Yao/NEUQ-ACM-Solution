#include <bits/stdc++.h>
#define max 10000
using namespace std;
bool sushu(int n){
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        if(sushu(a)) cout<<"1"<<endl;
        else if(a%2==0||sushu(a-2)) cout<<"2"<<endl;
        else cout<<"3"<<endl;
    }
}
