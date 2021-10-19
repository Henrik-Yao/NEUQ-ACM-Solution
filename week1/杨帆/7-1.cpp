#include<bits/stdc++.h>
using namespace std;
int  cnt[30];
string str,s[30];
int main(){
    int n;
    cin>>n;
    cin>>str;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        int len=str.find(s[i]);
        if(len!=string::npos){
            cnt[i]++;
            len=str.find(s[i],len+1);
            while(len!=string::npos){
                cnt[i]++;
                len=str.find(s[i],len+1);
            }
        }
    }
    for(int i=1;i<=n-1;i++)
        cout<<cnt[i]<<endl;
    cout<<cnt[n];
    return 0;
}
