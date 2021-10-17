#include<bits/stdc++.h>
using namespace std;

struct stu{
	int to;
	string name;
}s[100000];

int main() {
	int n, m;
	int num;
	string name;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		cin >> num >> name;
		s[i].to = num;
		s[i].name = name;
	}
//	for(int i = 0; i < n; i++){
//		cout << s[i].to << s[i].name <<endl;	
//	}
	int dir, data;
	int index = 0;
	for(int i = 0; i < m; i++){
		cin >> dir >> data;
		if(s[index].to != dir){//ÄæÊ±Õë 
			index = (index + data) % n;
		}
		else{
			if(index >= data) index -= data;
			else {
				index = n - (data - index);
			}
		} 
	}
	cout << s[index].name;
}
//7 1
//0 ymh
//0 lc
//0 zx
//1 wjq
//1 ld
//0 hhj
//1 yh
//0 3
