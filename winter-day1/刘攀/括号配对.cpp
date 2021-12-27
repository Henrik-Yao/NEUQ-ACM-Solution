#include <bits/stdc++.h>
using namespace std;
deque<char>temp1,temp2;
int main(){
    string s;
    while(getline(cin,s)){
        int cnt1 = 0,cnt2 = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '(')temp1.push_back(s[i]);
            if(s[i] == ')'){
                if(!temp1.empty())
                temp1.pop_back();
                else temp2.push_back(s[i]);
            }
        }
        if(!temp2.empty()) cnt1 = temp2.size();
        if(!temp1.empty()) cnt2 = temp1.size();
        if(!cnt1 && !cnt2)puts("Match");
        else{
            cout<<cnt1 + cnt2<<endl;
            while(cnt1--)s = '(' + s;
            while(cnt2--)s = s + ')';
            cout<<s<<endl;
        }
    temp1.clear();temp2.clear();
    }
    return 0;
}

