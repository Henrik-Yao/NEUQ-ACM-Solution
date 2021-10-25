#include<iostream>
#include<string>
using namespace std;

void solve(int rest, string fir, string sec, string thi)
{
	if(rest==1)
		cout<<fir<<"->"<<thi<<endl;
	else
	{
		solve(rest-1, fir, thi, sec);
		solve(1, fir, sec, thi);
		solve(rest-1, sec, fir, thi);
	}
	return;
}

int main()
{
	int rest;
	string fir, sec, thi;
	cin>>rest;
	cin>>fir>>sec>>thi;
	solve(rest, fir, sec, thi);
	return 0;
}
