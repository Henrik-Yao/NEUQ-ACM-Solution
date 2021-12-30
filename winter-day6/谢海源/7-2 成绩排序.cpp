#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
struct stu
{
	string name; int mark;
};
bool cmp1(stu a, stu b)
{
	return a.mark > b.mark;
}
bool cmp2(stu a, stu b)
{
	return a.mark == b.mark && a.name < b.name;
}
int main()
{
	stu a[maxn];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].name >> a[i].mark;
	sort(a, a + n, cmp1);
	sort(a, a + n, cmp2);
	for (int i = 0; i < n; i++) cout<< a[i].name <<" "<< a[i].mark<<endl;
	return 0;
}