#include<bits/stdc++.h>
using namespace std;
int t,n;
typedef struct active {
    int sstart;
    int eend;
}ac;
bool cmp(ac c,ac d){
     if(c.eend==d.eend){
         return c.sstart<d.sstart;
     }
     else return c.eend<d.eend;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        ac active[n];
        int ans=0;
        for(int i=0;i<n;i++)
        cin>>active[i].sstart>>active[i].eend;

        sort(active,active+n,cmp);

        int flag=active[0].eend;

        if(n!=0) ans=1;
        for(int i=1;i<n;i++){
           if(active[i].sstart>=flag){ 
               ans++;
               flag=active[i].eend;}
            else;
        }
        cout<<n-ans<<endl;
    }
    return 0;
}