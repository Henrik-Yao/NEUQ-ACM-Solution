#include <bits/stdc++.h>
using namespace std;
struct person{
	string name;
	int face;
}per[100001];
int main(){
	int n,m,i,dir,dis;
	string str[100001];
	cin>>n>>m;
	for (i=1;i<=n;i++)
		cin>>per[i].face>>per[i].name;
	int flag=1;
	while (m--){
		cin>>dir>>dis;
		if (dir==0) {
			if (per[flag].face==0) flag-=dis;
			else flag+=dis;
			if (flag<=0) flag+=n;
			if (flag>n) flag-=n;
		}
		if (dir==1){
			if (per[flag].face==1) flag-=dis;
			else flag+=dis;
			if (flag<=0) flag+=n;
			if (flag>n) flag-=n;
		}
	}
	cout<<per[flag].name;
	return 0;
}
