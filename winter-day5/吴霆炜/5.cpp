#include <bits/stdc++.h>
using namespace std;

struct people{
    char gender;
    string father;
};
map<string,people>mp;
int n,m;
bool check(string a,string b){
    int i = 1;int j;
    for(string _a = a;!_a.empty();_a = mp[_a].father,i++){
        j = 1;
        for(string _b = b;!_b.empty();_b = mp[_b].father,j++){
            if(i >= 5 && j >= 5)//如果在5代之外
            return true;
            if((i < 5 || j < 5) && _a == _b)//如果在5代之内
            return false;
        }
    }
    return true;//不够5代
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);//加快读入，不然会卡cin
    cin>>n;
    string firstname,lastname;
    for(int i = 0;i < n;i++){
        cin>>firstname>>lastname;
        if(lastname.back() == 'n'){//如果是冰岛人，且为男性
            mp[firstname] = {'m',lastname.substr(0,lastname.size() - 4)};//删去后缀sson
        }
        else if(lastname.back() == 'r')//如果是冰岛人，且为女性
            mp[firstname] = {'f',lastname.substr(0,lastname.size() - 7)};//删去后缀sdottir
        else//如果不是冰岛人，就不用记录父亲
            mp[firstname].gender = lastname.back();
    }
    cin>>m;
    for(int i = 0;i < m;i++){
        string a,b,s;
        cin>>a>>s>>b>>s;
        if(mp.find(a) == mp.end() || mp.find(b) == mp.end())puts("NA");//如果两人中至少有一个人不在名单内
        else if(mp[a].gender == mp[b].gender)puts("Whatever");//如果是楠桐/铝桐
        else{
           printf("%s\n",check(a,b) ? "Yes" : "No");
        }
    }
    return 0;
}