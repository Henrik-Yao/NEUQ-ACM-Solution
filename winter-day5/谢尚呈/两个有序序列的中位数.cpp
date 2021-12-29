#include<iostream>
#include<cstdlib>
using namespace std;
const int langt=200001;
int list[langt];
int cmp(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n, t=0;
	cin>>n;
	for(int i=0; i<2*n; i++)	cin>>list[i];
	qsort(list, n*2, sizeof(int), cmp);
	cout<<list[(2*n-1)/2];
	return 0;
}
