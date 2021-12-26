#include <bits/stdc++.h>
using namespace std;
const string A = "sae";
string B = 't' + A + 'd' + A;
string sum;
int main(){
    string s;
    getline(cin,s);
    for(int i = 0;s[i] != '#';i++){
        if(s[i] == 'B') sum += B;
        if(s[i] == '('){
            int pos1 = i + 1;
            i++;
            char head = s[i];
            sum += head;
            while(s[i] != ')')i++;
            int pos2 = i;
            while(i != pos1 + 1){
                i--;
                sum += s[i];
                sum += head;
            }
            i = pos2;
        }
    }
    cout<<sum<<endl;
    return 0;
}

