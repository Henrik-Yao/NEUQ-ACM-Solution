#include <bits/stdc++.h>
using namespace std;

map<int,bool>m;
int main(){
    string s1,s2;
    while(getline(cin,s1),getline(cin,s2)){
    for(int i = 0;i < s2.size();i++){
    int pos = 0,a = 0;
        while(1){
            a = s1.find(s2[i],pos);
            if(a == string::npos)
            break;
            m[a] = true;
            pos += a - pos + 1;
        }
    }
    for(int i = 0;i < s1.size();i++)
        if(m[i] != true)
        cout<<s1[i];
    puts("");
    m.clear();
    }
    return 0;
}