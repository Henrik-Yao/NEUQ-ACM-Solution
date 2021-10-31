#include<bits/stdc++.h>
using namespace std;
int n,book[10];
char a[10],b[10];
void print(void){
    for(int i=0;i<n;i++)
        cout<<b[i];
    cout<<endl;
}
void dfs(int x){
    if(x>=n){
        print();
        return;
    }
    for(int i=0;i<n;i++){
        if(!book[i]){
            book[i]=1;
            b[x]=a[i];
            dfs(x+1);
            book[i]=0;
        }
    }
}
int main(){
    cin>>a;
    n=strlen(a);
    sort(a,a+n);
    dfs(0);
    return 0;
}
