#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);//装逼专用，加快cin和cout
	char num[9];
	cin>>num;
	int i;
	int l = strlen(num);
	sort(num,num + l);
	do{
		for(i = 0;i < l;i++)
		cout<<num[i];
		cout<<endl;
	}while(next_permutation(num,num + l));//调用stl库next_permutation()函数
	return 0;
}