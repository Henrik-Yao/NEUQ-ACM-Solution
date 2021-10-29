#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int max_n = 1e5;
ll arr[max_n];
int main(){
    int n;
    while(cin>>n){
        arr[0] = 2;
        int i;
        for(i = 0;i < n;i++)
        arr[i] = arr[i - 1] * 3 + 2;
        cout<<arr[n - 1]<<endl;
    }
    return 0;
}