#include <bits/stdc++.h>
using namespace std;

deque<char>temp_l,temp_r;
int main(){
    string s;
    while(getline(cin,s)){
        int cnt_l = 0,cnt_r = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '(')temp_l.push_back(s[i]);
            if(s[i] == ')'){
                if(!temp_l.empty())
                temp_l.pop_back();
                else temp_r.push_back(s[i]);
            }
        }
        if(!temp_r.empty())cnt_l = temp_r.size();
        if(!temp_l.empty())cnt_r = temp_l.size();
        if(!cnt_l && !cnt_r)puts("Match");
        else{
            cout<<cnt_l + cnt_r<<endl;
            while(cnt_l--)s = '(' + s;
            while(cnt_r--)s = s + ')';
            cout<<s<<endl;
        }
    temp_l.clear();temp_r.clear();
    }
    return 0;
}