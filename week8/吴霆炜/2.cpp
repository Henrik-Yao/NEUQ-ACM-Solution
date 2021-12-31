#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010

int a[maxn];int n;

int _to(int left,int right){
    int _ans = left;
    for(int i = left;i <= right;i++){
        if(a[left] < a[i] + (i - _ans))
            _ans = i;
    }
    return _ans;
}

int _find(int left,int right){
    int _ans = left + 1;
    for(int i = left;i <= right;i++){
        if(a[i] > a[_ans]){
            a[_ans] = a[i];
            _ans = i;
        }
    }
    return _ans;
}

int main(){
    cin>>n;
    for(int i = 0;i < n;i++)cin>>a[i];
    int cnt = 1,pos = 0;
    while(pos + a[pos] < n - 1){
        int temp = a[pos];
        int _m = _find(pos,pos + a[pos]);
        pos= _to(_m,pos + temp);
        cnt++;
    }
    cout<<cnt;
    return 0;
}