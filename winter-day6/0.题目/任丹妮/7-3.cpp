#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num[100001],cnt[100001],i=0;
    bool visit[100001];
    memset(num,0,sizeof(num));
    memset(visit,0,sizeof(visit));
    while(n--){
        int a;
        cin>>a;
        if(!visit[a]) {
            visit[a]=true;
            cnt[i++]=a;
        }
        num[a]++;
    }
    sort(cnt,cnt+i);
    for(int j=0;j<i;j++)
    {
        cout<<cnt[j]<<":"<<num[cnt[j]]<<endl;
    }
    return 0;
}
