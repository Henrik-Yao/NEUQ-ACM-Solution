#include <bits/stdc++.h>
using namespace std;
int N,M;
string s1,s2;
map <string,string> mp;
int main() {
    cin>>N>>M;
    for (int i=1; i<=N; ++i) {
        cin>>s1;
        cin>>s2;
        mp[s2]=s1;
    }
    for (int i=1; i<=M; ++i) {
        cin>>s1;
        if (mp[s1]=="") puts("eh");
        else cout<<mp[s1]<<endl;
    }
    return 0;
}
