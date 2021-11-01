#include <iostream>

using namespace std;
long long p(int n){
    if(n==1)return 2;
    else return 3*p(n-1)+2;
}
int main(){
    int n;
    while(cin>>n){
        cout<<p(n)<<endl;
    }
    return 0;
}