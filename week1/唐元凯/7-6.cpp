#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, T,max=-9999;
	cin >> n >> T;
	vector<int>happy, time; happy.reserve(100000); time.reserve(100000);
	int temp1, temp2;
	for (size_t i = 0; i < n; i++)
	{
		cin >> temp1 >> temp2;
		happy.push_back(temp1);
		time.push_back(temp2);
	}
	for (size_t i = 0; i < n; i++)
	{
		if (time[i] <= T) {
			if (happy[i] > max)max = happy[i];
		}
		if (time[i]>T) {
			temp1 = happy[i] - (time[i] - T);
			if (temp1 > max)max = temp1;
		}
	}
	cout << max;
}