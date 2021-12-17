/*
 * @Author: ComplexPug
 * @Email: 3010651817@qq.com
 * @Date: 2021-12-10 14:14:54
 * @LastEditTime: 2021-12-10 14:15:16
 */
#include<bits/stdc++.h>
using namespace std;
long long f[1001];
int main() {
    int n;
    f[0]=1;f[1]=1;f[2]=2;f[3]=4;
    for(int i=4;i<=50;++i) {
        f[i]=f[i-1]+f[i-2]+f[i-3];
    }
    while(cin>>n) cout<<f[n]<<"\n";
    return 0;
}