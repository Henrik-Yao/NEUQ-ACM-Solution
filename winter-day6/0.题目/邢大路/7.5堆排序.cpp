#include<iostream>
using namespace std;
 
void heapsort(int num[], int n);	//func decl.
 
int main(void)
{
	int n, *num;	//define var.
	while(cin >> n) {
		num = new int[n];	//new spaces.
		
		/*input data.*/
		for(int i = 0; i < n; ++i)
			cin >> num[i];
		/*sorting.*/
		heapsort(num, n);
 
		/*output data.*/
		for(int i = 0; i < n; ++i)
			cout << ' ' << num[i];
		cout << endl;
 
		delete[] num;	//delete spaces.
	}
	return 0;
}//main.
 
void HeapAdjust(int num[], int n)
{
	int m = n/2; //num of nodes that have child nodes.
	for(int i = m; i >= 1; --i)
	{
		if(2*i < n && num[i-1] < num[2*i]) {
			int t = num[i-1];
			num[i-1] = num[2*i];
			num[2*i] = t;
		}
		if(num[i-1] < num[2*i-1]) {
			int t = num[i-1];
			num[i-1] = num[2*i-1];
			num[2*i-1] = t;
		} 
	}
	return;
}
 
void heapsort(int num[], int n)
{
	for(int i = n; i > 0; --i) {
		//build a heap bottom-up
		//ensuring the root is the biggest one. 
		HeapAdjust(num, i);
 
		int t = num[0];
		num[0] = num[i-1];
		num[i-1] = t;
	}
	return;
}
