#include<iostream>
#include<vector>
using namespace std;
const int N=100001;
int num[N]= {0},temp[N];
int main() {
	int n,m,k,goal,cdn;
	cin>>n>>m;
	vector<vector<int> >cp;
    //用vector开一个二维数组，好像不能提前定义cp的长度，不然存不进数，de出来的，不懂为何。
	int a,b;
	cp.resize(n + 1);//调整cp的长度，使得为n+1，存的了所有city的cp数组；
	while(m--) {
		cin>>a>>b;
		cp[a].push_back(b);//cp[a]就是指a.city的cp城市们
		cp[b].push_back(a);
		num[a]++;
		num[b]++;
	}
	cin>>k;
	while(k--) {
		int v=n;
		while(v--){
			temp[v+1]=num[v+1];
            //用v代替n，因为n不能变，后面有用；
            //num数组不能变，因为要多次使用，用temp临时存；
		}
		cin>>cdn;
		while(cdn--) {
			cin>>goal;
			temp[goal]=0;
			for(int i=0; i<cp[goal].size(); i++) {

				temp[cp[goal][i]]--;
			}
		}
		int flag=1;
		for(int i=1; i<=n; i++) {
			if(temp[i]>0)flag=0;
		}
		if(flag==1)cout<<"YES\n";
		else cout<<"NO\n";
	}



	return 0;
}