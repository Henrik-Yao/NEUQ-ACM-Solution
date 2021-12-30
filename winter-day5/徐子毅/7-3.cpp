#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    int pa=0,pb=0;
    while(pa+pb<(2*n+1)/2-1){
        if(a[pa]>=b[pb]) pb++;
        else pa++;
    }
    if(a[pa]>b[pb]) cout << b[pb] << endl;
    else cout << a[pa] << endl;
    return 0;
}