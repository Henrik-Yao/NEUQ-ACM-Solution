#include <bits/stdc++.h>
using namespace std;

const int max_n = 1e4;
int a[max_n];
int main(){
    int T,m,n;
    cin>>T;
    int i;
    while(T--){
        cin>>m;
        for(i = 0;i < m;i++)cin>>a[i];
        cin>>n;
        for(i = m;i < m + n;i++)cin>>a[i];
        sort(a,a + m + n);
        for(i = 0;i < m + n - 1;i++){
            cout<<a[i]<<' ';
        }
        cout<<a[m + n - 1]<<endl;
    }
    return 0;
}