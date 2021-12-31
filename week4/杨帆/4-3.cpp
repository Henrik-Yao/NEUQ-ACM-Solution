#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int k=10000000;
bool book[k];
int temp[k],p;
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        if(!book[i])
            temp[++p]=i;
        for(int j=1;i*temp[j]<=n&&j<=p;j++){
            book[i*temp[j]]=1;
            if(i%temp[j]==0)    break;
        }
    }
    cout<<p;
    return 0;
}
