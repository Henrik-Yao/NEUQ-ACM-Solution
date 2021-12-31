#include <bits/stdc++.h>
using namespace std;

struct linkNode {
	int data;
	linkNode *prior;
	linkNode *next;
};

int main() {
	int n, m, k, f = 0, cnt = 0;
	cin >> n >> m >> k;
	linkNode *tmp = new linkNode;
	linkNode *cur = tmp;
	tmp->data = 1;
	for (int i = 2; i <= n - 1; i++) {
		linkNode *temp = new linkNode;
		temp->data = i;
		temp->prior = cur;
		cur->next = temp;
		cur = temp;
	}
	linkNode *p = new linkNode;
	cur->next = p;
	p->prior = cur;
	p->data = n;
	p->next = tmp;
	tmp->prior = p;
	cur = tmp;
	while (n > 1) {
		if (!f) {
			while (1) {
				cnt++;
				if (cnt == m) {
					cout << cur->data << " ";
					cur->prior->next = cur->next;
					cur->next->prior = cur->prior;
					cur = cur->prior;
					f = 1 - f;
					n--;
					cnt = 0;
					break;
				}
				cur = cur->prior;
			}
		} else {
			while (1) {
				cnt++;
				if (cnt == k) {
					cout << cur->data << " ";
					cur->prior->next = cur->next;
					cur->next->prior = cur->prior;
					cur = cur->next;
					f = 1 - f;
					n--;
					cnt = 0;
					break;
				}
				cur = cur->next;
			}
		}
	}
	cout << cur->data;
	return 0;
}