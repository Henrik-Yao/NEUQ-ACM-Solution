#include<bits/stdc++.h>
using namespace std;
int arr[200005];

int main()
{
	int n;
	cin>>n;

	for(int i=1;i<=2*n;i++)
		cin>>arr[i];
	sort(arr+1,arr+2*n+1);

	cout<<arr[(2*n+1)/2];

	return 0;
}

