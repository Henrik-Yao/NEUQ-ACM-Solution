#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll max=10001;
int solution(int a[],int n){
    int suml=0,sum=0;
    for(int i=0;i<n;i++){
        if(suml+a[i]>a[i])
            suml=suml+a[i];
        else suml=a[i];
        if(suml>sum)
            sum=suml;
    }
    return sum;
}
int main(){
    int i,n,a[10001]={0};
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<solution(a,n)<<endl;
    return 0;
}
