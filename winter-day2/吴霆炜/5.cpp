#include <bits/stdc++.h>
using namespace std;

vector<int>a;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	a.resize(100);
	int sum = 0,n,m,x;
	char ch;
	cin>>n;
	getchar();//清缓存
	for(int i = 0;i < n;i++){
		cin>>ch>>x;
		a[i] = x;
		q.push(x);
	}
	while(q.size() > 1){
		int x = q.top();q.pop();
		int y = q.top();q.pop();
		sum = sum + x + y;
		q.push(x + y);
	}
	cin>>m;
	while(m--){
		int _sum = 0;
		string str[100];
		for(int i = 0;i < n;i++){
			cin>>ch>>str[i];
			_sum = _sum + str[i].size() * a[i];
		}
		if(sum == _sum){
			bool flag = true;//用于判断是否为正确的haffman编码
			for(int i = 0;i < n - 1;i++){
				for(int j = i + 1;j < n;j++){
					bool _flag = false;//用于判断是否不为前缀数
					int _size = str[i].size() > str[j].size() ? str[j].size() : str[i].size();
					for(int k = 0;k < _size;k++)
					if(str[i][k] != str[j][k])
					_flag = true;
					if(!_flag)
					flag = false;
				}
			}
			if(flag)puts("Yes");
			else puts("No");
		}
		else
		puts("No");
	}
	return 0;
}