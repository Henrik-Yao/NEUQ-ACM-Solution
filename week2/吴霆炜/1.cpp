#include <bits/stdc++.h>
using namespace std;

void hanoi(int num,string begin,string transfer,string end){
	if(num == 1)
	cout<<begin<<"->"<<end<<endl;
	else{
	hanoi(num - 1,begin,end,transfer);
	cout<<begin<<"->"<<end<<endl;
	hanoi(num - 1,transfer,begin,end);
}}
int main(){
	int n;
	string n1,n2,n3;
	cin>>n>>n1>>n2>>n3;
	hanoi(n,n1,n2,n3);
	return 0;
}