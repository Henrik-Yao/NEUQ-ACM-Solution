#include <bits/stdc++.h>
using namespace std;

const string A = "sae";
string B = 't' + A + 'd' + A;
string ans;
int main(){
    string s;
    getline(cin,s);
    for(int i = 0;s[i] != '#';i++){
        if(s[i] == 'B') ans += B;
        if(s[i] == '('){
            int l_pos = i + 1;
            i++;
            char head = s[i];
            ans += head;
            while(s[i] != ')')i++;
            int r_pos = i;
            while(i != l_pos + 1){
                i--;
                ans += s[i];
                ans += head;
            }
            i = r_pos;
        }
    }
    cout<<ans<<endl;
    return 0;
}