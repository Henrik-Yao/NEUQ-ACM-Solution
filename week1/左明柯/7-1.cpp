#include <bits/stdc++.h> 
using namespace std;
int main(){
int n;cin>>n;
    string s,s1;
    cin>>s;
    int L=s.length();
    for(int i=0;i<n;i++){
     cin>>s1;int count=0;
        int l=s1.length();
        for(int j=0;j<L;j++){
            int flag=0;
            for(int k=0;k<l;k++){
                if(s[k+j]==s1[k]) flag++;
            }
            if(flag==l) count++;
        }
        cout<<count<<endl;
    }

    return 0;
}
