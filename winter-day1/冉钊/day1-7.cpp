#include<bits/stdc++.h>
using namespace std;
int main(){
    string lan;
    getline(cin,lan);
    for(int i=0;i<lan.size();i++){
        if(lan[i]=='A')
        cout<<"sae";
        else if(lan[i]=='B')
        cout<<"tsaedsae";
        else if(lan[i]=='('){
        char fir=lan[++i];
        i++;
        stack<char>ch;
        while(lan[i]!=')'){
            ch.push(lan[i]);
            i++;
        }
        while(!ch.empty()){
            cout<<fir;
            cout<<ch.top();
            ch.pop();
        }
        cout<<fir;
        }
    }

    return 0;
}