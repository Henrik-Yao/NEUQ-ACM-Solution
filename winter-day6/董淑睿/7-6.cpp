#include <bits/stdc++.h>
using namespace std;
const int _=2e5+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n,arr[_];
void F(int arr[],int begin,int end){
    if(begin>=end) return;
    int i=begin,j=end,temp=arr[begin];
    while(i!=j) {
        while(arr[j]>temp&&i<j) j--;
        while(arr[i]<=temp&&i<j) i++;
        if(j>i) swap(arr[j],arr[i]);
    }
    arr[begin]=arr[i];
    arr[i]=temp;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"\n";
    F(arr,begin,i-1);
    F(arr,i+1,end);
}
int main(){
    n=read();
    for(int i=0;i<n;i++) arr[i]=read();
    F(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}