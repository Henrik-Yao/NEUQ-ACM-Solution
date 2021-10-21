#include<iostream>
#include<algorithm>
using namespace std;
int n,a[1000001];
int main() {
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1; i<=n; i++) cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}
