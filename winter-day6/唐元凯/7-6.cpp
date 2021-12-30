#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int n;

void quicksort(int *A, int begin, int end) {
	if (begin >= end)return;
	int temp = A[begin];
	int i = begin, j = end;
	while (i != j) {
		while (A[j] > temp && j > i)j--;
		while (A[i] <= temp && j > i)i++;
		if (j > i) {
			int t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}
	A[begin] = A[i];
	A[i] = temp;
	for (int i = 0; i < n; i++)cout << A[i] << " ";
	cout << endl;
	quicksort(A, begin, i - 1);
	quicksort(A, i + 1, end);
}

int main() {
	int A[1001];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	quicksort(A, 0, n-1);
	for (int i = 0; i < n; i++)cout << A[i] << " ";
	cout << endl;
}