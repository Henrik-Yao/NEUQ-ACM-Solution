#include<bits/stdc++.h>
using namespace std;
int a[200001],t[200001];
void sort(int l,int r){
    if(l==r) return ;
    int mid=(l+r)/2;
    sort(l,mid);sort(mid+1,r);
    int p=l,q=mid+1,now=0;
    while(p<=mid && q<=r){
        if(a[p]<a[q]) t[++now]=a[p],p++;
        else t[++now]=a[q],q++;
    }
    while(p<=mid)t[++now]=a[p],p++;
    while(q<=r)t[++now]=a[q],q++;
    for(int i=l;i<=r;i++)
    a[i]=t[i-l+1];
}

int main(){
    int t,i,j,m,n;
    ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>m;
        for(j=1;j<=m;j++)
            cin>>a[j];
        cin>>n;
        for(j=m+1;j<=m+n;j++)
            cin>>a[j];
        sort(1,m+n);
        for(j=1;j<=m+n-1;j++)
            cout<<a[j]<<" ";
        cout<<a[m+n];
        cout<<endl;
    }
    //for(i=1;i<=m+n;i++)
    //    cout<<a[i]<<" ";
    //cout<<endl;

}
