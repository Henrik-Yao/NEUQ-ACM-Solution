#include <iostream>
using namespace std;

int main(){
    int t,m,n;
    cin>>t;
    for (int i = 0; i < t; ++i) {
        cin>>m;
        int f[m];
        for (int j = 0; j < m; ++j) {
            cin>>f[j];
        }
        cin>>n;
        int s[n];
        for (int j = 0; j < n; ++j) {
            cin>>s[j];
        }
        int t1 = 0,t2 = 0;
        int k = 0;
        int sum[m+n];
        while (t1<m&&t2<n){
            if(f[t1]<s[t2]){
                sum[k] = f[t1];
                t1++;
                k++;
            } else{
                sum[k] = s[t2];
                k++;
                t2++;
            }
        }
        if(t1==m){
            for (int j = t2; j < n; ++j) {
                sum[k] = s[j];
                k++;
            }
        } else{
            for (int j = t1; j < m; ++j) {
                sum[k] = f[j];
                k++;
            }
        }
        for (int j = 0; j < k; ++j) {
            if(j==0)cout<<sum[j];
            else cout<<" "<<sum[j];
        }
        cout<<endl;
    }
    return 0;
}