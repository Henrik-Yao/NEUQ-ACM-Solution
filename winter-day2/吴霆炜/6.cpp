#include <bits/stdc++.h>
using namespace std;
#define maxn 100

int a[maxn],b[maxn];
int n;
void build(int l1,int r1,int l2,int r2){
    if(l1 > r1 || l2 > r2)return;
    else{
    for(int i = l2;i <= r2;i++){
        if(b[i] == a[l1]){
            build(l1 + 1,l1 + i - l2,l2,i - 1);
            build(l1 + i - l2 + 1,r1,i + 1,r2);
            cout<<a[l1]<<' ';
            return;
        }
    }
    }
}
int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++)scanf("%d",&a[i]);
    for(int i = 0;i < n;i++)scanf("%d",&b[i]);
    int l = n - 1;
    build(0,l,0,l);
    return 0;
}