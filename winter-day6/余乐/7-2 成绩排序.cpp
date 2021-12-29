#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct ss{
	string name;
	int point;
}p[21];
bool cmp(const ss &a,const ss &b){
	if(a.point == b.point){
		int lena = a.name.size();
		int lenb = b.name.size();
		int p = 0;
		while(1){
			if(p > lena) return 1;
			if(p > lenb) return 0;
			if(a.name[p] < b.name[p]) return 1;
			else p ++;
		}
	}
	return a.point > b.point;
}

int main(){
	scanf("%d",&n);
	for(int i = 0;i < n;i ++)
		cin >> p[i].name >> p[i].point;
	sort(p , p + n , cmp);
	for(int i = 0;i < n;i ++){
		cout << p[i].name << " " << p[i].point;
		if(i < n - 1) cout << endl;
	}
	return 0;
}
