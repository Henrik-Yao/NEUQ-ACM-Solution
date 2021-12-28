#include<bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],x,u;
queue<int>que;
struct node{
	int l,r;
}vec[100010];
void print(int x){
	que.push(x);
	while(que.size()){
		u=que.front();
		que.pop();
		cout<<u<<' ';
		if(vec[u].l!=-1)
		que.push(vec[u].l);
		if(vec[u].r!=-1)
		que.push(vec[u].r);
	}
}
int dfs(int l1,int r1,int l2,int r2){
	//printf("%d %d %d %d\n",l1,r1,l2,r2);
	if(l1==r1&&l2==r2){
		vec[a[l1]].l=-1;
		vec[a[l1]].r=-1;
		return a[l1];
	}
	int root=a[l1];
	int mid;
	for(int i=l2;i<=r2;i++){
		if(b[i]==root){
			mid=i;
			break;
		}
	}
	if(mid-1<l2||l1+mid-l2<l1+1)vec[root].l=-1;
	else vec[root].l=dfs(l1+1,l1+mid-l2,l2,mid-1);
	if(r2<mid+1||r1<r1-r2+mid+1)vec[root].r=-1;
	else vec[root].r=dfs(r1-r2+mid+1,r1,mid+1,r2);
	return root;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	dfs(1,n,1,n);
	//while(cin>>x)cout<<vec[x].l<<' '<<vec[x].r;
	print(a[1]);
	return 0;
}
