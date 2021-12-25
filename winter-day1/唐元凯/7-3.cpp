#include <iostream>
#include <list>

using namespace std;

int main() {
	int n, m, k;
	list<int>yo;
	cin >> n >> m >> k;
	for (int i = 1; i <=n; i++)
	{
		yo.emplace_back(i);
	}
	auto it = yo.begin();
	int sum = 1; bool rev = 1;
	while (!yo.empty()) {
		if (rev) {
			if (it == yo.begin()) { it = yo.end(); --it; }
			else --it;
			++sum;
			if (sum == m) {
				cout << (*it) << " ";
				it = yo.erase(it);
				if (it != yo.begin()) --it;
				else { it = yo.end(); --it; }
				rev = false;
				sum = 1;
			}
		}
		else {
			auto it1 = it;
			if ((++it1) == yo.end()) { it = yo.begin(); }
			else ++it;
			++sum;
			if (sum == k) {
				cout << (*it) << " ";
				it = yo.erase(it);
				rev = true;
				sum = 1;
			}
		}
	}
}