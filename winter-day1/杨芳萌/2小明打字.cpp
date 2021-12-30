#include<bits/stdc++.h>
using namespace std;
int p,flag=1;
string s;
vector<char> v;
int main() {
    getline(cin, s);
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '[') p = 0;
        else if(s[i] == ']') p = v.size();
        else if(s[i] == '{') p = max(0, p-1);
        else if(s[i] == '}') p = min((int)v.size(), p+1);
        else if(s[i] == '-') flag *= -1;
        else if(s[i] == '=') {
        	if(v.size()) {
        		v.erase(v.begin()+p-1);
				p--;
			}
		}
        else {
            if(p==v.size()-1) v.push_back(s[i]);
            else if(flag==-1) v[p] = s[i];
            else v.insert(v.begin()+p, s[i]);
            p++;
        }
    }
    vector<char>::iterator it; 
	for(it=v.begin(); it!=v.end(); it++) cout<<*it;
    return 0;
}
