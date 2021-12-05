#include<bits/stdc++.h>
using namespace std;
string start(){
    int n;
    string s="",s1;
    char c;
    while(cin>>c){
        if(c=='['){
            cin>>n;
            s1=start();
            while(n--)s+=s1;
        }
        else{
            if(c==']')return s;
            else s+=c;
        }
    }
}
int main(){
    cout<<start();
    return 0;
}
