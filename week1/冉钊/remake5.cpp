#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m,now=1,flag=0;
	cin>>n>>m;
	int a[n+1],b[m+1][2];
	string name[n+1];
	for(int i=1; i<=n; i++) {

		cin>>a[i]>>name[i];
	}
	for(int i=1; i<=m; i++) {
		cin>>b[i][0]>>b[i][1];
	}
	for(int i=1; i<=m; i++) {
		int x=b[i][1];
		if(a[now]==1) {
			if(b[i][0]==1) {
				x=x%n;
				flag=now-x;
				if(flag<=0) {
					flag=fabs(flag);
					now=n-flag;
				} else {

					now=flag;
				}

			} else {
				x=x%n;
				flag=now+x;
				if(flag>n) {
					flag=flag-n;
				} else {
					now=flag;
				}

			}

		}

		else {
			if(b[i][0]==1) {
				x=x%n;
				flag=now+x;
				if(flag>n) {
					flag=flag-n;
				} else {
					now=flag;
				}

			} else {
				x=x%n;
				flag=now-x;
				if(flag<=0) {
					flag=fabs(flag);
					now=n-flag;
				} else {

					now=flag;
				}


			}

		}

	}
	cout<<name[now];


	return 0;
}
