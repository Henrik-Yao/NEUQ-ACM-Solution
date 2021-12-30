#include<bits/stdc++.h>
using namespace std;
int a[100000];

bool check(int d,int n,int m);

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int left = 0,right = a[n] - a[1];
    while(left <= right){
        int mid = (left + right) / 2;
        if(check(mid,n,m)){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << right;
}

bool check(int d,int n,int m){
    int pre = 1,cnt = 1;
    for(int i=2; i<=n; i++){
        if(a[i] - a[pre] >= d){
            cnt++;
            pre = i;
        }
    }
    return cnt >= m;
}
