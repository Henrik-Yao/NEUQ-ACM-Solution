#include<bits/stdc++.h>
using namespace std;
const int k=10000+5;
int a[k],b[k],book[k];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
    }
    int k;
    cin>>k;
    while(k--){
        int x,t;
        cin>>x;
        memset(book,0,sizeof(book));
        for(int i=0;i<x;i++){
            cin>>t;
            book[t]=1;
        }
        int flag=1;
        for(int i=0;i<m;i++){
            if(book[a[i]]==0&&book[b[i]]==0){
                flag=0;
                printf("NO\n");
                break;
            }
        }
        if(flag==1)
            printf("YES\n");
    }
}
