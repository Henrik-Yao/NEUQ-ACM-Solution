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
	int k = 0;//����״̬
	while (x = getchar()) {
		if (x == '\n')
			break;
		else if (x == '[')//�ص���һ��λ��
			cur = head;
		else if (x == ']')//�����һ��λ��
			cur = head->prior;
		else if (x == '{') {//����
			if (cur != head)
				cur = cur->prior;
		} else if (x == '}') {//����
			if (cur->next != head)
				cur = cur->next;
		} else if (x == '-')//�ı�״̬
			k = 1 - k;
		else if (x == '=') {//ɾ��ǰһ���ڵ㣬�����ͷ�ڵ���û����һ���ڵ�
			if (cur != head) {
				cur = cur->prior;
				cur->next = cur->next->next;
				cur->next->prior = cur;
			}
		} else {
			if (k == 1) {//�滻��ǰֵ
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