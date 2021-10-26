#include <iostream>
using namespace std;
int a[1000001];
int main(){
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]>=d) {
            for(int i=mid-1;i>=1;i--){
                if(a[i]>=d) mid=min(mid,i);
            }
            cout<<mid<<endl;
            break;
        }
        else l=mid+1;
    }
    if(l>r) cout<<n+1<<endl;
    return 0;
}
