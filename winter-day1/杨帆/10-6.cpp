#include<bits/stdc++.h>
using namespace std;

bool is(string &text){
    for(int i=0,j=text.size()-1; i<j; i++,j--){
        if(text[i] != text[j]){
            return false;
        }
    }
    return true;
}

int main(){
    string text;
    cin >> text;
    if(is(text)){
        cout << "yes";
    }
    else {
        cout << "no";
    }
    return 0;
}
