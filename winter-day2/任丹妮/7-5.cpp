#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>>q;
int main(){
    int n;
    char s[65];
    int p[65];
    cin>>n;
    for(int i=0;i<n;i++)
    {
    cin>>s[i]>>p[i];
    q.push(p[i]);
    }
    int ans=0;
    while(q.size()!=1){
    int a=q.top();
    q.pop();
    int b=q.top();
    q.pop();
    ans+=a+b;
    q.push(a+b);
    }
    int m;
    cin>>m;
    while(m--){
    char ss[65][65];
    int sum=0;
    for(int i=0;i<n;i++){
    char ch;
    cin>>ch;
    cin>>ss[i];
    sum+=strlen(ss[i])*p[i];
    }
    if(sum!=ans) cout<<"No"<<endl;
    else {
        bool flag=false;
        for(int i=0;i<n;i++){
            int len=strlen(ss[i]);
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(strstr(ss[j],ss[i])==&ss[j][0]){
                    flag=true;
                    break;
                    }
                }
            } 
            if(flag) break;
        }   
    if(flag) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    }
    }
    return 0;
}
