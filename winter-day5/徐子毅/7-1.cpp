#include <iostream>
#include <algorithm>
using namespace std;
int num[10005];
int main(){
    int n;
    cin >> n;
	for(int i=0;i<n;i++){
		int j;
		cin >> j;
		num[j]++;
	}
	int sum=0;
	for(int i=0;i<10000;i++){
		sum+=num[i]*num[i+1];
	}
    cout << sum << endl;
}