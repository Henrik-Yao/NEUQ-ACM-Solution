#include <bits/stdc++.h>
using namespace std;
#define maxn 1010

int a[maxn];
int ans[maxn];
int main(){
    //freopen("data.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        fill(ans,ans + n,1);
        for(int i = 0;i < n;i++)cin>>a[i];
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(a[j] < a[i])
                ans[i] = max(ans[i],ans[j] + 1);
            }
        }
        int Max = 0;
        for(int i = 0;i < n;i++)
            Max = max(Max,ans[i]);
        cout<<Max<<endl;
        if(T != 0)
        puts("");
    }
    return 0;
}