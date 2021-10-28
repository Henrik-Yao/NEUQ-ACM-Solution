#include <bits/stdc++.h>
using namespace std;
#define max_n 1000000

int arr[max_n];
int temparr[max_n];
long long cnt = 0;
void fun(int left,int right){
    if(left == right)
    return;
    int mid = (left + right) >> 1;
    fun(left,mid);
    fun(mid + 1,right);
    int l_pos = left;
    int r_pos = mid + 1;
    int pos = left;
    while(l_pos <= mid && r_pos <= right){
        if(arr[l_pos] <= arr[r_pos])
        temparr[pos++] = arr[l_pos++];
        else{
            temparr[pos++] = arr[r_pos++];
            cnt = cnt + (mid - l_pos) + 1;////此时l_pos指向当前段中mid左端最大数，mid指向当前端段最小数的左边一位
        }}
    while(l_pos <= mid)
    temparr[pos++] = arr[l_pos++];
    while(r_pos <= right)
    temparr[pos++] = arr[r_pos++];
    for(int i = left;i <= right;i++)
    arr[i] = temparr[i];
}
int main(){
   
    int n;
    cin>>n;
    int i;
    for(i = 0;i < n;i++)cin>>arr[i];
    fun(0,n - 1);
    cout<<cnt;
    return 0;
}
