#include<bits/stdc++.h>
using namespace std;
void move(string A,string B)
{
	cout<<A<<"->"<<B;
}
void Hanoi(int n,string A,string B,string C)
{
	if(n==1)
		move(A,C);
	else
	{
		Hanoi(n-1,A,C,B);
		cout<<endl;
		move(A,C);
		cout<<endl;
		Hanoi(n-1,B,A,C);
	}
}
int main()
{
	int a;
	cin>>a;
	string A,B,C;
	cin>>A>>B>>C;
	Hanoi(a,A,B,C);
	return 0;
}
