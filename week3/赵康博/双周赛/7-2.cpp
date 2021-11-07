#include <iostream>
using namespace std;
void move(string a,string b){
    cout<<a<<"->"<<b<<endl;
}
void p(string a,string b,string c,int n){
    if(n==1)move(a,c);
    else {
        p(a,c,b,n-1);
        move(a,c);
        p(b,a,c,n-1);
    }
}
int main(){
    int n;
    string a,b,c;
    cin>>n>>a>>b>>c;
    p(a,b,c,n);
    return 0;
}