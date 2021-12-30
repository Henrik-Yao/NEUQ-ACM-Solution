#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cur = n;
	vector<int>Heap(n), ans(n);
	for (int i = 0; i < n; i++)
		cin >> Heap[i];
	while (!Heap.empty()) {
		make_heap(Heap.begin(), Heap.end());
		for (auto &c : Heap) {
			cout << c << " ";
		}
		for (int i = Heap.size(); i < n; i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
		ans[--cur] = Heap.front();
		pop_heap(Heap.begin(), Heap.end());
		Heap.pop_back();
	}
}