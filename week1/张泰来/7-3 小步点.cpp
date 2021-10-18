#include <bits/stdc++.h>
using namespace std;
int r,d,n;
double ans;
int main()
{
	scanf("%d%d%d",&r,&d,&n);
	d = abs(d);
	n = abs(n);
	if (r < n)	ans = 2.0 * sqrt(d * d + (n - r) * (n - r)) - r; 
	else ans = 2.0 * d - r;
	
	printf("%.2f\n",ans);
	return 0;
}
