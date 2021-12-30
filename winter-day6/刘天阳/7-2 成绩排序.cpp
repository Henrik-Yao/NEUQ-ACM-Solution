#include <bits/stdc++.h>
using namespace std;
struct Std{
	string name;
	int chengji;
};
Std stu[1009];
bool cmp(Std stu1,Std stu2)
{
	if(stu1.chengji > stu2.chengji) return 1;
	else if(stu1.chengji < stu2.chengji) return 0;
	else return stu1.name < stu2.name;
}
int main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stu[i].name >> stu[i].chengji;
	}
	sort(stu+1, stu+n+1,cmp);
	for (int i = 1; i <= n; i++)
	{
		cout << stu[i].name  << " " << stu[i].chengji << endl;
	}
	
	return 0;
}
