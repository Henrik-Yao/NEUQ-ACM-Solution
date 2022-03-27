#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	int T, n,temp,maxlen;
	int flag = 0;
	cin >> T ;
	vector<int>data; data.reserve(1000);
	while (T--) {
		cin >> n;
		data.clear(); maxlen = 1; vector<int>sum(1005, 1);
		while (n--) {
			cin >> temp;
			data.emplace_back(temp);
		}
		sum[0] = 1;
		for (size_t i = 1,length=data.size(); i < length; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				if (data[i] > data[j])sum[i] = max(sum[j]+1, sum[i]);
			}
			maxlen = max(maxlen, sum[i]);
		}
		cout << maxlen;
		if (T != 0)cout << endl << endl;
	}
}