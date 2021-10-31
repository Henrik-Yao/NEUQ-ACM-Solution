#include <bits/stdc++.h>
using namespace std;

const int max_N = 1e5 + 10;
int MaxSubsequenceSum(int a[],int n){
    int tempsum = 0,maxsum = 0;
    int ans = 0;
    for(int j = 0;j < n;j++){
    tempsum = (tempsum + a[j]) > a[j] ? (tempsum + a[j]) : a[j];
    if(tempsum > maxsum)
    maxsum = tempsum;
}
    return maxsum;
}
int main(){
    int arr[max_N] = {};
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)cin>>arr[i];
    cout<<MaxSubsequenceSum(arr,n)<<endl;
    return 0;
}