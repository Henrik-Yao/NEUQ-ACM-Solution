#include <bits/stdc++.h>
using namespace std;
bool vis[1009];
int main()
{
	int n, m, k; cin >> n >> m >> k;
	int sum = 0, s = 2;
	while(sum < n)
	{
		int t = 0;
		if(!(sum%2)) // m
		{
			while(t<m) 
			{
				s--;
				if(!s) s+=n;
				if(!vis[s]) t++;
				
 			}
 			vis[s] = 1;
 			cout << s << " ";
 			if(sum != n-1)
 			{
 				while(1) 
				{
					s--;
					if(!s) s+=n;
					if(!vis[s]) break;
 				}
 				s--; if(!s) s+=n;
			}
		}
		else // k
		{
			while(t<k) 
			{
				s++;
				if(s>n) s %= n;
				if(!vis[s]) t++;
 			}
 			vis[s] = 1;
 			cout << s << " ";
 			if(sum != n-1) 
			{
			 	while(1) 
				{
					s++;
					if(s>n) s %= n;
					if(!vis[s]) break;
				}
				s++; if(s>n) s %= n;
			}
 			
		} 
		sum++;
	}
//	for(int i = 1; i <= n; i++) cout << vis[i];
	return 0;
}
