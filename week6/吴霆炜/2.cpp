#include <bits/stdc++.h>
using namespace std;

const int base = 36;
map<string,string>login;
map<string,vector<int>>hasher;
vector<int>get_hash(string s){
    for(int i = 0;i < s.size();i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
        s[i] = s[i] - 'A' + 'a';
    }
    int x;
    vector<int>number,res;
    for(int i = 0;i < s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            x = s[i] - '0';
        }
        else{
            x = s[i] - 'a' + 10;
        }
        number.push_back(x);
    }
    int mul = s.size() / 4;
    int sum = mul * 4;
    int pos = 0;
    for(int k = 0;k < 4;k++){
        int length = mul;
        if(sum < s.size()){
            sum++;
            length++;
        }
        int n = 0;
        for(int j = pos;j <= length + pos - 1;j++){
            n += number[j];
        }
        pos += length;
        res.push_back(n % base);
    } 
    return res;
}

int main(){
    int N;
    cin>>N;
    while(N--){
        char opt;string username;string password;
        cin>>opt>>username>>password;
        if(opt == 'R'){
            if(login.count(username))
            cout<<"Repeated!"<<endl;
            else{
                login[username] = password;
                hasher[username] = get_hash(password);
                cout<<"Signed!"<<endl;
            }
        }
        else{
            if(!login.count(username)){
            cout<<"Failed!"<<endl;
            continue;
            }
            if(login[username] == password){
                cout<<"Success!"<<endl;
                continue;
            }
            if(hasher[username] == get_hash(password))
            cout<<"Attention!"<<endl;
            else
            cout<<"Failed!"<<endl;
        }
    }
    return 0;
}