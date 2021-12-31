#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int a;
	while(cin>>a){
	long long sum = 2;
	for (int i = 1; i < a; i++)
	{
		sum = 3 * sum + 2;
	}
	cout << sum << endl;}
}