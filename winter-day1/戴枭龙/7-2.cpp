#include <iostream>
#include <vector>
using namespace std;

struct linkNode {
	char data;
	linkNode *prior;
	linkNode *next;
	linkNode(char c) : data(c) {}
};

int main() {
	linkNode *head = new linkNode(0);
	head->next = head->prior = head;
	linkNode *cur = head;
	char x;
	int k = 0;//插入状态
	while (x = getchar()) {
		if (x == '\n')
			break;
		else if (x == '[')//回到第一个位置
			cur = head;
		else if (x == ']')//到最后一个位置
			cur = head->prior;
		else if (x == '{') {//左移
			if (cur != head)
				cur = cur->prior;
		} else if (x == '}') {//右移
			if (cur->next != head)
				cur = cur->next;
		} else if (x == '-')//改变状态
			k = 1 - k;
		else if (x == '=') {//删除前一个节点，如果是头节点则没有上一个节点
			if (cur != head) {
				cur = cur->prior;
				cur->next = cur->next->next;
				cur->next->prior = cur;
			}
		} else {
			if (k == 1) {//替换当前值
				cur->next->data = x;
				cur = cur->next;
				continue;
			}
			linkNode *temp = new linkNode(x);
			temp->data = x;
			temp->next = cur->next;
			temp->next->prior = temp;
			cur->next = temp;
			temp->prior = cur;
			cur = temp;
		}
	}
	for (linkNode *p = head->next; p != head; p = p->next) {
		cout << p->data;
	}
	return 0;
}