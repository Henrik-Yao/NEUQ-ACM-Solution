#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll f[65],F[65];
void han(){
    	f[1]=1;
	for(int i=2;i<=64;i++)
		f[i]=2*f[i-1]+1;
	F[1]=1,F[2]=3,F[3]=5;
	for(int i=4;i<=64;i++){
		F[i]=f[i];
		for(int j=1;j<i;j++)
			if(2*F[j]+f[i-j]<F[i])
				F[i]=2*F[j]+f[i-j];
	}
}
int main()
{
	int n;
    ios::sync_with_stdio(false);
    han();
	while(cin>>n)
		cout<<F[n]<<endl;
	return 0;
}
