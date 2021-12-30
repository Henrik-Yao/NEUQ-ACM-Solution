#include <bits/stdc++.h>
using namespace std;
int a[1009];
int main()
{
	int n; 
	while(cin >> n){
		
	
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 3; i <= n+1; i++)
		{
			sort(a+1,a+i);
			for (int j = 1; j <= n; j++)
			{
				cout << a[j];
				if(j < n) cout << " ";
				else cout << endl;
			}
		}
	}
	return 0;
}
