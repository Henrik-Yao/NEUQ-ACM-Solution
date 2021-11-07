#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+1],f=0;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        if(f>=0) f+=a[i];
        if(f<0) { 
            f=a[i];
        }
        ans=max(ans,f);
    }//注意题目要求，当所给均为负数时，定义字段和为0；
    cout<<ans<<endl;

    return 0;
}