#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    int flag=1;
    cin>>a;
    for(int i=0;i<=a.size()/2;i++)
        if(a[i]!=a[a.size()-i-1]) flag=0;
    if(flag) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
