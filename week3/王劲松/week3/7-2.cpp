 #include<bits/stdc++.h>
using namespace std;
int f(int s);
int a[600],b[600];
vector<int>tu[600];
int main(){
	 int n,m,i;
	 cin>>n>>m;
	 for(i=0;i<m;i++){
	 	int j,k;
	 	cin>>j>>k;
	 	tu[j].push_back(k);
	 }
	int A,B;
	cin>>A>>B;
	a[B]=1;
	cout<<f(A)<<' ';
	for(i=1;i<=n;i++){
		if(!a[i]&&b[i]){
		cout<<"No";
		break;
		}
		else if(i==n)cout<<"Yes";
	}
    cout<<endl;
	return 0;
}
int f(int s){
	b[s]=1;
	if(a[s])return a[s];
	else {
		for(int num=0;num<tu[s].size();num++){
			a[s]+=f(tu[s][num]);
		}return a[s];
	}
}
