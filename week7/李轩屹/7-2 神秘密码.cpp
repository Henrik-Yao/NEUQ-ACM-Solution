#include <bits/stdc++.h>
using namespace std;
string mima() {
    string s,mid;
    int n;
    char c;
    while(cin>>c){
        if(c=='[') {
            cin>>n;
            mid=mima();
            while(n--){
            	s+=mid;
			}
        } 
		else if(c==']') return s;
		else s+=c;
    }
}
int main() {
    cout<<mima();
    return 0;
}
