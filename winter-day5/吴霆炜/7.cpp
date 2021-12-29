#include <bits/stdc++.h>
using namespace std;
#define maxn 100010

int a[maxn];
int n,m,num;
bool check(int x){
    int cnt = 1,now = a[0];
    for(int i = 0;i < n;i++){
        if(a[i] - now > x){
            now = a[i];
            cnt++;
            if(cnt >= m)
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    sort(a,a + n);
    int l = 0,r = 1e5 + 1;
    bool flag = false;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid - 1; 
    }
    printf("%d",l);
    return 0;
}