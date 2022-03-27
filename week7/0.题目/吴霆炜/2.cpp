#include <bits/stdc++.h>
using namespace std;

string solve(){
    string s = "",str = "";
    char ch;
    int k;
    while(cin>>ch){
        if(ch == '['){
            cin>>k;
            str = solve();
            while(k--)s += str;
        }
        else if(ch == ']')
        return s;
        else
        s += ch;
    }
}

int main(){
    cout<<solve()<<endl;
    return 0;
}