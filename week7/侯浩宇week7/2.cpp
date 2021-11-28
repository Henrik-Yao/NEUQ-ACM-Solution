#include <bits/stdc++.h>
using namespace std;
string dg(){
    string a,b;
    int n;
    char c;
    while(cin>>c){
        if(c=='['){
            cin>>n;
            b=dg();
            for(int i=0;i<n;i++)
			a+=b;
        } 
		else{
            if(c==']')return a;
            else a+=c;
        }
    }
}
int main(){
	string ans=dg();
    cout<<ans;
    return 0;
}
