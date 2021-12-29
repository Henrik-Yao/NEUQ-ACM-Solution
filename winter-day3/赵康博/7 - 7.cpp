#include<bits/stdc++.h>

using namespace std;
#define N 200

typedef struct Nofe
{
    int length;
    int tt;
    int ww;
}nofe;
int s[50];
bool  cmp(nofe a,nofe b){
    return a.length < b.length;
}
void Buil()
{
    for(int i = 0; i < 51; i++)s[i] = i;
}
int find(int x){
    if(x==s[x])return x;
    return s[x] = find(s[x]);
}
int p(int a,int b)
{
    int x = find(a);
    int y = find(b);
    if(x!=y)s[y] = x;
    else return 0;
    return 1;
}
nofe f[N];
int main() {
    int n,v,m;
    cin>>n>>v>>m;
    while (1)
    {
        Buil();
        for(int i = 0; i < m; i++)cin>>f[i].tt>>f[i].ww>>f[i].length;
        int num = 0;
        int sum = 0;
        int nun = 0;
        sort(f,f+m, cmp);
        for(int i = 0; i < m; i++)
        {
            if((f[i].tt==v||f[i].ww==v)&&num < 2)
            {
                if(p(f[i].tt,f[i].ww)){
                    sum+=f[i].length;
                    num++;
                    nun++;
                }
            } else if(f[i].tt!=v&&f[i].ww!=v)
            {
                if(p(f[i].tt,f[i].ww)){
                    sum+=f[i].length;
                    nun++;
                }
            }
            if(nun== n - 1)break;
        }
        if(nun==n - 1)cout<<sum;
        else cout<<"-1";
        if(cin>>n>>v>>m)cout<<endl;
        else break;
    }
    return 0;
}