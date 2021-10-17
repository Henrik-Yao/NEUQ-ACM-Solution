#include <bits/stdc++.h>
using namespace std;

const int max_N = 1e6 + 5;
int a[max_N];
int b1[max_N],b2[max_N];
int sum1 = 0,sum2 = 0,sum = 0;
int main(){
    int n;
    int i;
    cin>>n;
    for(i = 1;i <= n;i++){
    cin>>a[i];
    if(i >= 2){
        if(b2[a[i]] == 0){
            sum2++;
        }
        b2[a[i]]++;
    }}
    sum1 = 1;
    b1[a[1]]++;
    for(i = 2;i <= n;i++){
        if(b1[a[i]] == 0){
            b1[a[i]]++;
            sum1++;
        }
        else{
            b1[a[i]]++;
        }
        if(b2[a[i]] > 1){
            b2[a[i]]--;
        }
        else if(b2[a[i]] == 1){
            b2[a[i]]--;
            sum2--;
        }
        if((sum1 + sum2) >= sum)
        sum = sum1 + sum2;
    }
    cout<<sum;
    return 0;
}