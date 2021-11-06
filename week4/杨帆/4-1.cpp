#include<bits/stdc++.h>
using namespace std;
const int k=10000+5;
int n,m;
int book[k],temp[k],p;
int main(){
    while(cin>>n>>m){
        p=0;
        memset(book,0,sizeof(book));
        memset(temp,0,sizeof(temp));
        for(int i=2;i<=m;i++){
            if(!book[i]){
                temp[++p]=i;
                for(int j=2;j*temp[p]<=m;j++)
                    book[j*temp[p]]=1;
            }
        }
        for(int i=1;i<=p;i++){
            if(temp[i]>=n){
                cout<<temp[i];
                if(i!=p)    cout<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
