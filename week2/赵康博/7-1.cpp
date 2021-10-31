#include <iostream>
using namespace std;
void move(string x,string z){
    cout<<x<<"->"<<z<<endl;
}
void f(string a,string b,string c,int n){
    if(n==1)move(a,c);
    else {
        f(a,c,b,n-1);
        move(a,c);
        f(b,a,c,n-1);
    }
}
int main() {
    int n;
    string a,b,c;
    cin>>n>>a>>b>>c;
    f(a,b,c,n);
    return 0;
}
