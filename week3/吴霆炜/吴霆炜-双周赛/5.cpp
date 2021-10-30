#include <bits/stdc++.h>
using namespace std;
#define max_N 1000000

int n;
int find(int num,int arr[]){
    if(num > arr[n - 1]){
        return n + 1;
    }
    int left = 0;
    int right = n - 1;
    int mid = (left + right) >> 1;
    while(left < right){
        if(num <= arr[mid])
        right = mid;
        else if(num > arr[mid])
        left = mid + 1;
    mid = left + ((right - left) >> 1); 
    }
    return mid + 1;
}

int main(){
    int arr[max_N] = {0};
    int num;
    cin>>n>>num;
    int i;
    for(i = 0;i < n;i++)cin>>arr[i];
    cout<<find(num,arr)<<endl;
    return 0;
 }