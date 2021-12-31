#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int a[100001],ans;
vector<int>in;
void inorder(int x,int depth){
	if (a[x]!=0){
		inorder(x*2,depth+1);
		in.push_back(a[x]);
		inorder(x*2+1,depth+1);
	}
	else {
		ans=max(ans,depth);
		return;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		in.clear();
        memset(a,0,sizeof a);
		for (int i=1;i<=n;i++)
			cin>>a[i];
		ans=-1;
		inorder(1,0);
		for (int i=0;i<in.size();i++)
			if (i!=in.size()-1) cout<<in[i]<<" ";
			else cout<<in[i];
		cout<<endl<<ans<<endl;
	}
	return 0;
} 
