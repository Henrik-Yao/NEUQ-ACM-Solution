#include <bits/stdc++.h>
using namespace std;
int main(){
    const string A="sae";
    string B="t"+A+"d"+A;
    string s;
    cin>>s;
    int i=0;
    string ans;
    char ch;
    while(s[i]!='#'){
        if(s[i]=='B'){
            ans+=B;
        }
        else if(s[i]=='A'){
            ans+=A;
        }
        else if(s[i]=='('){
            i++;
            ch=s[i];
            int j=i+1;
            while(s[j]!=')'){
                j++;
            }
            int end=j;
            while(i<j-1){
                ans=ans+ch+s[--j];
            }
            ans+=ch;
            i=end;
        }
        i++;
    }
    cout<<ans<<endl;
}
