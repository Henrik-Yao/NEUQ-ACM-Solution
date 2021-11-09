#include <bits/stdc++.h>
using namespace std;
int start,n;
int vis[50001],m[50001];
queue<int>q;
int main() {
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>m[i];
	cin>>start;
	q.push(start);
	vis[start]=1;
	while (!q.empty()) {
		int now=q.front();
		q.pop();
		if (m[now]==0) {
			cout<<"True";
			return 0;
		}
		if (now+m[now]<n&&!vis[now+m[now]]) {
			vis[now+m[now]]=1;
			q.push(now+m[now]);
		}
		if (now-m[now]>=0&&!vis[now-m[now]]) {
			vis[now-m[now]]=1;
			q.push(now-m[now]);
		}
	}
	cout<<"False";
	return 0;
}
