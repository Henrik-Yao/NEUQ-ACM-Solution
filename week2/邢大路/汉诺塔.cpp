#include<bits/stdc++.h>
using namespace std;
void F(int n,string a,string b,string c){
    if(n>0){ 
        F(n-1,a,c,b);
        cout<<a<<"->"<<b<<endl;
        F(n-1,c,b,a);
}
}
int main(){
    int n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;
    F(n,a,c,b);
    return 0;
}
