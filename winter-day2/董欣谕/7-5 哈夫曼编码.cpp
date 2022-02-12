#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
priority_queue<int,vector<int>,greater<int>>q;
int sum=0,n,w[100];
char ch[100],c[100];
string str[100];
bool check(){
	int weight=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			int len=min(str[i].length(),str[j].length());
			if (str[i].substr(0,len)==str[j].substr(0,len)) return 0;
		}
		weight+=w[i]*str[i].length();
	}
	if (weight!=sum) return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>c[i];
		cin>>w[i];
		q.push(w[i]);
	}
	while (q.size()>1){
		int temp=q.top();
		q.pop();
		temp+=q.top();
		q.pop();
		sum+=temp;
		q.push(temp);
	}
	int q;
	cin>>q;
	while (q--){
		for (int i=1;i<=n;i++)
			cin>>ch[i]>>str[i];
		if (check()) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 
