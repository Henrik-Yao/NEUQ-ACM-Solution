#include<bits/stdc++.h>
using namespace std;
int issu(int n) {
	if (n == 1)
		return 0;
	else {
		int flag = 1;
		for (int i = 2; i <= sqrt(n); i++) {
			if (n%i == 0) {
				flag = -1;
				break;
			}
		}
		if (flag == 1)
			return 1;
		else
			return 0;
	}
}
int func(int n) {
	int sum = 0;
	if (issu(n))
		sum += 2;
	else {
		for (int i = 1; i < n; i++) {
			if (n%i == 0 && i != 1 && !issu(i))
				sum += func(i);
			else if (i == 1)
				sum += 1;
			else if (n%i == 0 && issu(i))
				sum += 2;
			
		}
	}
	return sum+1;
}
int main() {
    int n;
    cin>>n;
    if(!issu(n))
	cout << func(n);
	else
	cout<<2;
	
}

