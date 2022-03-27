#include<bits/stdc++.h>
using namespace std;
int sum(string a,string b) {
	
	int sum1 = 0;
	for (int i = 0; i < a.length(); i++)
	{
		string c;
		for (int j = i; j < i + b.length(); j++) {
			c+=a[j];
		
		}
		if (c == b) {
			sum1++;
		}
	}
	return sum1;
}
int main(){
	int n;
	cin >> n;
	string a,b;
	cin >> a;
	while (n--) {
		cin >> b;
        if(n==0)
            cout<<sum(a,b);
        else
		cout << sum(a, b) << endl;
	}
}
