#include<bits/stdc++.h>
using namespace std;
vector<int>a[2];
int main(){
    int count=0;
    int num[100005];
    while(cin>>num[count++]);
    sort(num,num+count);
    for(int i=0;i<count;i++){
        if(num[i]!=0){
        cout<<num[i];
        if(i!=count-1)cout<<"->";
        if(num[i]%2==0)a[0].push_back(num[i]);
        else a[1].push_back(num[i]);
    }
    }
    cout<<endl;
    for(int i=0;i<a[1].size();i++){
        if(a[1][i]!=0){
        cout<<a[1][i];
        if(i!=a[1].size()-1)cout<<"->";
    }
    }
    cout<<endl;
    for(int i=0;i<a[0].size();i++){
        if(a[0][i]!=0){
        cout<<a[0][i];
        if(i!=a[0].size()-1)cout<<"->";
        }
    }
    return 0;
}
