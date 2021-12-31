#include<iostream>
using namespace std;
void swap(int array[], int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
void Adjust(int array[], int i, int length)
{
	int temp = array[i], k;
	for (k = 2 * i + 1; k < length; k = 2 * i + 1)
	{
		if (k + 1 < length && array[k] < array[k + 1])
			k++;
		if (array[k] > temp)
		{
			swap(array, i, k);
			i = k;
		}
		else break;
	}
}
void sort(int array[],int length)
{
	int i;
	
	for (i = length / 2 - 1; i >= 0; i--)
	{
		Adjust(array, i, length);
	}
	for (int j = 0; j < length; j++)
	{
		cout << array[j] << " ";
	}
	cout << endl;
	for (i = length - 1; i>0; i --)
	{
		swap(array, 0, i);
		Adjust(array, 0, i);
		for (int j = 0; j < length; j++)
		{
			cout << array[j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int n, i;
	int array[10001];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> array[i];
	sort(array, n);
	return 0;
}