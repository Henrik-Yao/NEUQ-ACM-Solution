#include<bits/stdc++.h>
using namespace std;
struct times{
    int a,b;
}p[105];
bool cmp(times s1, times s2){
    return s1.b<s2.b;
}
int main(){
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++) cin>>p[j].a>>p[j].b;
        sort(p,p+n,cmp);
        int j=0,count=1;
        for(int k=1;k<n;k++)
            if(p[k].a>=p[j].b) j=k;count++;
        n-=count;
        cout<<n<<endl;
    }
}
