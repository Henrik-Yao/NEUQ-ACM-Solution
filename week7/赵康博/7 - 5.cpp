#include <bits/stdc++.h>

using namespace std;
int f[20];
int main()
{
    int n,v;
    cin>>n>>v;
    int m[10],k[10];
    for(int i = 0; i < n; i++)cin>>m[i];
    for(int i = 0; i < n; i++)cin>>k[i];
    for(int i = 0; i < n; i++){
        for(int j = v; j >= 0; j--){
            if(j-m[i]>=0)
            f[j] = max(f[j],f[j-m[i]]+k[i]);
        }
    }
    cout<<f[v]<<endl;
    system("pause");
    return 0;
}