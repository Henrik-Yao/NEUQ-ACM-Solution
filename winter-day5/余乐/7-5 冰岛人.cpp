#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#define N 100001
using namespace std;

int n,m,t,top,f[N],xb[N];
map<string,int> id;

int find(int X , int Y){
	for(int i = 1,x = X;x;i ++,x = f[x])
		for(int j = 1,y = Y;y;j ++,y = f[y]){
			if(i >= 5 && j >= 5) return 0;
			if(x == y) return 1;
		}
	return 0;
}

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		char a[21] = {0},b[21] = {0},c[21] = {0};
		cin >> a >> b;
		int lenb = strlen(b);
		char fl = b[lenb - 1];
		if(fl == 'f' && !id[a]){
			id[a] = ++ t;
//			cout << "---" << a << id[a] << endl;
		}
		if(fl == 'm' && !id[a]){
			id[a] = ++ t;
			xb[t] = 1;
//			cout << "---" << a << id[a] << endl;
		}
		if(fl == 'n'){
			if(!id[a]){
				id[a] = ++ t;
				xb[t] = 1;
			}
			for(int j = 0;j < lenb - 4;j ++)
				c[j] = b[j];
			if(!id[c]){
				id[c] = ++ t;
				xb[t] = 1;
			}
//			cout << "---" << a << id[a] << endl;
//			cout << "---" << c << id[c] << endl;
			f[id[a]] = id[c];
		}
		if(fl == 'r'){
			if(!id[a]) id[a] = ++ t;
			for(int j = 0;j < lenb - 7;j ++)
				c[j] = b[j];
			if(!id[c]) {
				id[c] = ++ t;
				xb[t] = 1;
			}
//			cout << "---" << a << id[a] << endl;
//			cout << "---" << c << id[c] << endl;
			f[id[a]] = id[c];
		}
	}
	scanf("%d",&m);
	for(int i = 1;i <= m;i ++){
		char a[21] = {0},b[21] = {0},c[21] = {0},d[21] = {0};
		cin >> a >> b >> c >> d;
		if(!id[a] || !id[c]){
			printf("NA\n");
			continue;
		}
		if(xb[id[a]] == xb[id[c]]){
			printf("Whatever\n");
			continue;
		}
		if(find(id[a] , id[c])) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
