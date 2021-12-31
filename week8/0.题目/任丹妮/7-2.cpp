#include<bits/stdc++.h>
using namespace std;
#define MAX 10000001
int arr[MAX];
int find_max(int n, int m){
	int index = n+1;
	for(int i = n; i <= m; i ++){
		if(arr[n] < arr[i]){
			arr[n] = arr[i];
			index = i;
		}
	}
	return index;
}
int to(int n, int m){
	for(int i = n; i <= m; i ++){
		if(arr[n] < arr[i]+(i-n)){
			n = i;
		}
	}
	return n;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> arr[i];
	}
	int k = 0;
    int tmp = 1;
	while(k+arr[k] < n-1){
        int p = arr[k];
		int m = find_max(k,arr[k]+k);
		k = to(m,p+k);
		tmp ++;
	}
	cout << tmp << endl;
}

