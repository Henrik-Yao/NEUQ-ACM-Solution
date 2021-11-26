#include<bits/stdc++.h>
using namespace std;


int main(){
	string s,pat;
    while(getline(cin,s)){
        unordered_map<char,int> occ;
        getline(cin,pat);
        int len = s.size();
        for(int i=0; i<pat.size(); i++){
            occ[pat[i]]++;
        }
        for(int i=0; i<len; i++){

            if(occ.count(s[i])){
                continue;
            }
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
