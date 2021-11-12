#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
bool c[N];
int main()
{
	int a,b,i,j,n,m=0;
	c[0] = c[1] = 1;
	for(i = 2;i <= N;i++)
		if(!c[i]) 	
		for (j = 2, a = 1; a <= N; j++) {
				a = i*j;
				if(a <= N)	c[a] = 1;}
	cin>>b;
	n=0;
	for(i = 2;i <= b;i++)
		if(!c[i])	n++;
	cout<<n<<endl;	
	return 0;
}
