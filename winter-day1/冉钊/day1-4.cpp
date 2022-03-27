#include<bits/stdc++.h>
using namespace std;
const int ma=1e7;
int flag,fla;
int a[ma];
int main(){
    int i=0;
    while(cin>>a[i++]);
    sort(a,a+i-1);
    for(int j=0;j<i-1;j++){
        cout<<a[j];
        if(j!=i-2)cout<<"->";
    }
    cout<<endl;
    queue<int>od,ou;
    for(int j=0;j<i-1;j++){
        if(a[j]&1==1){
            od.push(a[j]);
            fla++;
        }
        else{
            ou.push(a[j]);
            flag++;
        }
    }
    while(fla--){
        cout<<od.front();
        od.pop();
        if(fla>=1)cout<<"->";
    }
    cout<<endl;
    while(flag--){
        cout<<ou.front();
        ou.pop();
        if(flag>=1)cout<<"->";
    }
    return 0;
}