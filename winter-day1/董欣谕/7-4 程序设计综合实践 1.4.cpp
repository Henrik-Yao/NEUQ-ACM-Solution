#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
void print(vector<int>a){
	cout<<a[0];
	for (int i=1;i<a.size();i++){
		cout<<"->"<<a[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int x;
	vector<int>a;
	while (cin>>x){
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	vector<int>b,c;
	for (auto x:a){
		if (x%2==0) c.push_back(x);
		else b.push_back(x);
	}
	print(a);
	cout<<endl;
	if (b.size()!=0) print(b);
	cout<<endl;
	if (c.size()!=0) print(c);
	return 0;
} 
