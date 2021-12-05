#include<bits/stdc++.h>
using namespace std;

string func(){
    string s1 = "",s2 = "";
    char ch;
    while(cin >> ch){
        if(ch == '['){
            int n;
            cin >> n;
            s2 = func();
            while(n--){
                s1 += s2;
            }
        }
        else if(ch == ']'){
            return s1;
        }
        else{
            s1 += ch;
        }
    }
}

int main(){
    cout << func();
    return 0;
}
