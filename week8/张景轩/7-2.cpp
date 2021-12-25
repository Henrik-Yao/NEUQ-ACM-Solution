#include<iostream>
using namespace std;
const int Max = 100000;
int a[Max];
int findN(int x, int y){
	int ans = x+1;
	for(int i=x; i<=y; i++){
		if(a[x] < a[i]){
			a[x] = a[i];
			ans = i;
		}
	}
	return ans;
}
int link(int x, int y){
	int ans = x;
	for(int i=ans;i<=y;i++){
		if(a[x] < a[i]+(i-x)){
			x = i;
		}
	}
	return x;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
    {
		cin >> a[i];
	}
	int k = 0, tmp = 1;
	while(k+a[k] < n-1)
    {
        int p = a[k];
		int m = findN(k,a[k]+k);
		k = link(m,p+k);
		tmp ++;
	}
	cout << tmp << endl;
    return 0;
}