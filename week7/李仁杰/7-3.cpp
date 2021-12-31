#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main() {
    string s;
    while(getline(cin, s)){
        set<char> k;
        string ans = "",s1;
        getline(cin, s1);
        for(int i = 0; i < s1.length(); i++) k.insert(s1[i]); 
        for (auto i = s.begin(); i != s.end(); i++) {
            if (k.find(*i) == k.end()) ans += *i;
        }
        cout << ans << endl;
    }
}