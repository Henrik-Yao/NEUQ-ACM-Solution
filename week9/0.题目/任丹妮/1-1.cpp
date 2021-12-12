#include<bits/stdc++.h>
using namespace std;
int n;
long long arr[51];
int main()
{
	arr[0]=1;
    arr[1]=2;
    arr[2]=4;
	for(int i=3;i<50;i++)
	arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    while(cin>>n)
    {
    	cout<<arr[n-1]<<endl;
	}
}

