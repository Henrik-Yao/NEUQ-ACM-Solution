#include<bits/stdc++.h>
using namespace std;
string printout(){
	int n;
    string str1={},str2={};
    char a;
    while(cin>>a){
        if(a=='['){
            cin>>n;
            str2=printout();
            for(int i=0;i<n;i++) s1+=s2;
        }
        else if(a==']') return str1;
        else str1+=a;
    }
}
int main(){
	ios::sync_with_stdio(false);
    cout<<printout();
    return 0;
}
