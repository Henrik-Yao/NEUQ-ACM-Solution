#include <bits/stdc++.h>
using namespace std;

int sum[100000];
int main(){
    int n,T;
    cin>>n>>T;
    int v,t;
    for(int i = 0;i < n;i++){
        cin>>v>>t;
        if(t > T){
            sum[i] += (v - (t - T));
        }
        else 
        sum[i] += v;
        if(i != 0)
        sum[i] = max(sum[i],sum[i - 1]);
    }
    cout<<sum[n - 1]<<endl;
    return 0;
}