#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int ans[1001];
vector <int> res;
void dfs(int x){
    if (ans[x]!=0) {
        res.push_back(ans[x]);
        dfs(ans[x]);
    } 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    int n;
    int a[1001];
    cin>>n;
    set<int>s;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        auto it=s.lower_bound(a[i]);
    	if (it!=s.end()) {
    		ans[*it]=a[i];
            s.erase(*it);
    		s.insert(a[i]);
		}
        else s.insert(a[i]);
	}
    res.push_back(a[1]);
    dfs(a[1]);
    for (int i=0;i<res.size();i++)
        if (i!=res.size()-1) cout<<res[i]<<" ";
        else cout<<res[i];
	cout<<endl<<s.size();
	return 0;
}
