#include<iostream>
using namespace std;
bool tag = true;
typedef struct Node
{
	char data;
	Node* next, * pre;
}*LinkList;
int main() 
{
	LinkList now, first, end;
	LinkList head = (LinkList)malloc(sizeof(Node));
	head->data = NULL;
	head->pre = NULL;
	head->next = NULL;
	now = head, first = head, end = head;
	char c;
	for (; (c = getchar()) != '\n';)
	{
		if (c == '[') now = first;
		else if (c == ']') now = end;
		else if (c == '{')
		{
			if (now->pre) now = now->pre;
		}
		else if (c == '}')
		{
			if (now->next)now = now->next;
		}
		else if (c == '-') tag = !tag;
		else if (c == '=')
		{
			if (now->pre)
			{
				LinkList tmp = now;
				now->pre->next = now->next;
				if (now->next)
				{
					now->next->pre = now->pre;
					now = now->pre;
				}
				else
				{
					now = now->pre;
					now->next = NULL;
				}
				delete tmp;
				if (now->next == NULL) end = now;
			}
		}
		else
		{
			LinkList newL = (LinkList)malloc(sizeof(Node));
			newL->data = c;
			newL->next = now->next;
			newL->pre = now;
			now->next = newL;
			now = newL;
			if (now->next == NULL) end = now;
			if (!tag && now->next)
			{
				LinkList t = now->next;
				if (t->next)
				{
					now->next = t->next;
					t->next->pre = now;
					delete t;
				}
				else
				{
					delete t;
					end = now;
					now->next = NULL;
				}
			}
		}
	}
	now = first->next;
	while (now)
	{
		cout << now->data;
		now = now->next;
	}
	return 0;
}