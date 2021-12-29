#include <bits/stdc++.h>
using namespace std;
#define maxn 1010

int a[maxn];
int n,num,cnt,ans;
int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&num);
    int l = 0,r = n - 1;
    bool flag = false;
    while(l <= r){
        cnt++;
        int mid = (l + r) >> 1;
        if(a[mid] == num) {ans = mid;flag = true;break;}
        else if(num < a[mid]) r = mid - 1;
        else l = mid + 1; 
    }
    if(flag)
    printf("%d\n%d\n",ans,cnt);
    else
    printf("-1\n%d\n",cnt);
    return 0;
}