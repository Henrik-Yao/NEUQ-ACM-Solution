
#include<bits/stdc++.h>
using namespace std;/*
typedef long long ll;
const ll N=1000000;
int n,a[N],b[N];
ll cnt=0;
void f(int L,int R){
    if(L==R) return;
    int m=(L+R)/2;
    int k1=L,k2=m+1,k=L;
    f(L,m);f(m+1,R);
    while(k1<=m&&k2<=R){
        if(a[k1]<=a[k2]){
            b[k]=a[k1];
            k++,k1++;
        }
        else{
            b[k]=a[k2];
            k++,k2++;
            cnt=cnt+m-k1+1;
        }
    }
    while(k1<=m){
         b[k]=a[k1];
         k++,k1++;
    }
    while(k2<=R){
         b[k]=a[k2];
         k++,k2++;
    }
    for(int i=L;i<=R;i++)
        a[i]=b[i];
}
int main(){
    int i;
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    f(1,n);
    cout<<cnt;
    return 0;
}
long long i,j,k,n,m,tot,ans,sum[100005<<2],f[100005],a[100005];
void up(int node){
    sum[node]=sum[node<<1]+sum[node<<1|1];
}
long long read(){
    char c;
    while(c=getchar(),(c<'0'||c>'9')&&c!='-');
    long long x=0,y=1;
    if(c=='-') y=-1;
    else x=c-'0';
    while(c=getchar(),c>='0'&&c<='9')
        x=x*10+c-'0';
    return x*y;
}
void updata(int node,int l,int r,int p,int ad){
    if(l==r){
        sum[node]+=ad;
        return;
    }
    int mid=(l+r)/2;
    if(mid>=p) updata(node<<1,l,mid,p,ad);
    else updata(node<<1|1,mid+1,r,p,ad);
    up(node);
}
long long query(int node,int l,int r,int le,int ri){
    if(le<=l&&r<=ri){
        return sum[node];
    }
    long long ans=0;
    int mid=(l+r)/2;
    if(le<=mid) ans+=query(node<<1,l,mid,le,ri);
    if(ri>=mid+1) ans+=query(node<<1|1,mid+1,r,le,ri);
    return ans;
}
void build(int node,int l,int r){
    if(l==r){
        sum[node]=f[l];
        return;
    }
    int mid=(l+r)/2;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    up(node);
}
int main()
{
    n=read();for(int i=1;i<=n;i++) a[i]=read();
    build(1,1,100005);
    for(int i=1;i<=n;i++){
        updata(1,1,100005,a[i],1);
        tot+=query(1,1,100005,1,a[i])-1;
    }
    k=1;
    while(k<n){
        ans+=k;
        k++;
    }
    cout<<ans-tot;
    return 0;
}*/
const long long max_n=1000000;
int arr[max_n];
int temparr[max_n];
long long cnt = 0;
void f(int l,int r){
    if(l==r) return;
        int mid=(l+r)>>1;
    f(l,mid);f(mid+1,r);
    int l_pos=l,r_pos=mid+1,pos=l;
    while(l_pos<=mid && r_pos<=r){
        if(arr[l_pos]<=arr[r_pos])
            temparr[pos++]=arr[l_pos++];
        else{
            temparr[pos++]=arr[r_pos++];
            cnt=cnt+(mid-l_pos)+1;
        }
    }
    while(l_pos<=mid)
        temparr[pos++]=arr[l_pos++];
    while(r_pos<=r)
        temparr[pos++]=arr[r_pos++];
    for(int i=l;i<=r;i++)
        arr[i]=temparr[i];
}
int main(){
    int n,i;
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr[i];
        f(0,n-1);
    cout<<cnt;
    return 0;
}
