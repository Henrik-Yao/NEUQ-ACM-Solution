#include<iostream>
using namespace std;

int main(){
	int n,m,i,j;
	int k,t;
	struct {
		int x;
		int y;
	}a[10010];
	cin >> n >> m;
	for(i=0; i<m; i++){
		cin >> a[i].x >>a[i].y;
	}
	
	cin >> k;
	
	for(i=0; i<k; i++){
		int flag = 0;
		int r,h;
		int p[1010] = {0};
		cin >> t;
		
		for(j=0; j<t; j++){
			cin >> r;
			p[r] = 1;
		}
		
		for(h=0; h<n; h++){
			if(p[a[h].x]==0&&p[a[h].y]==0){
				cout << "NO" << endl;
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			cout << "YES" << endl;
		
	}
	
	
	
	
	
	return 0;
} 
