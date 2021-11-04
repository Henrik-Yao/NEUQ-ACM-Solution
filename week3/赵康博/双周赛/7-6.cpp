#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;//4231
bool cmp2(int a,int b){
    return a<b;
}
void h(int f[],int a,int b,int m){
    if(a!=b) {
        int t;
        t = f[a];
        f[a] = f[b];
        f[b] = t;
        sort(f + a + 1, f + m, cmp2);
    }
}
void p(int f[],int n,int m,char s[]){
    if(n==m){
        for (int i = 0; i < n; ++i) {
            cout<<s[f[i]];
        }
        cout<<endl;
    }
    else {
        for (int i = n; i < m; ++i) {
            h(f,n,i,m);
            p(f,n+1,m,s);
            if(n == m - 1 ||i == n)h(f,n,i,m);
            else h(f,n,n+1,m);
        }//acbd
    }
}
bool cmp(char a,char b){
    return a<b;
}
int main(){
    int n;
    char s[8];
    cin>>s;
    sort(s,s+ strlen(s),cmp);
    n = strlen(s);
    int f[n];
    for (int i = 0; i < n; ++i) {
        f[i] = i;
    }
    p(f,0,n,s);
    return 0;
}