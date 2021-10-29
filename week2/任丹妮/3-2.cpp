#include <bits/stdc++.h>
using namespace std;
multimap<int,int>path;
multimap<int,int>::iterator lower,upper,it;
int main(){
    int N,M,cnt1[10001],cnt2[10001];
    cin>>N>>M;
    while(M--){
        int a,b;
        cin>>a>>b;
        path.insert(make_pair(a,b));
        path.insert(make_pair(b,a));
        cnt1[a]++;
        cnt1[b]++;
    }
    int k,i;
    cin>>k;
    while(k--){
        for(i=1;i<=N;i++){
            cnt2[i]=cnt1[i];
        }
        int n;
        cin>>n;
        while(n--){
            int c;
            cin>>c;
            cnt2[c]=0;
            lower=path.lower_bound(c);
            upper=path.upper_bound(c);
            for(it=lower;it!=upper;it++){
            	int d=it->second;
            	if(cnt2[d]!=0) cnt2[d]--; 
			}
        }
        for(i=1;i<=N;i++){
            if(cnt2[i]!=0) {
                cout<<"NO"<<endl;
                break;}
        }
        if(i>N) cout<<"YES"<<endl;
    }
    return 0;
}
