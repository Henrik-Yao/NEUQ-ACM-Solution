#include <bits/stdc++.h>
using namespace std;

void hanoi(int n,string a,string b,string c){
    if(n == 1)
    cout<<a<<"->"<<c<<endl;
    else{
    hanoi(n - 1,a,c,b);
    cout<<a<<"->"<<c<<endl;
    hanoi(n - 1,b,a,c);
    }
}
int main(){
    int n;
    string a,b,c;
    cin>>n;
    cin>>a>>b>>c;
    hanoi(n,a,b,c);
    return 0;
}