#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int a[N];

void BS(int n);

int main(){
    int n;
    cin >> n;
    BS(n);
    return 0;
}

void BS(int n){
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int target;
    cin >> target;
    int left = 0,right = n-1;
    int cnt = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        cnt++;
        if(a[mid] == target){
            cout << mid << endl << cnt << endl;
            return;
        }
        if(a[mid] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    if(left > right){
        cout << -1 << endl << cnt << endl;
        return;
    }
}
