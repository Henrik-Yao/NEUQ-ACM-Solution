#include <bits/stdc++.h>
using namespace std;
struct Node
{
	char ch;
	Node *last = NULL;
	Node *next = NULL;
};
int main()
{
	string str;
	getline(cin, str);
	int len = str.size();

	Node *head = new Node; //头指针
	Node *pointer = head;  //光标

	bool insert = false;

	for (int i = 0; i < len; i++)
	{
		int word = str[i];
		if (word == '[')
		{
			pointer = head;
		}
		else if (word == ']')
		{
			while (pointer->next != NULL)
			{
				pointer = pointer->next;
			}
		}
		else if (word == '{')
		{
			if (pointer->last != NULL) //若前不为空
				pointer = pointer->last;
		}
		else if (word == '}')
		{
			if (pointer->next != NULL) //若后不为空
				pointer = pointer->next;
		}
		else if (word == '-')
		{
			if (insert == false)
				insert = true;
			else
				insert = false;
		}
		else if (word == '=')
		{
			Node *zan = pointer;	 //临时工
			pointer = pointer->last; //光标退格
			if (zan->next != NULL)
			{
				zan->next->last = zan->last;
				zan->last->next = zan->next;
			}
			else if (zan->next == NULL)
			{
				zan->last->next = zan->next;
			}
		}
		else
		{
			if(insert&&pointer->next!=NULL)
			{
				pointer=pointer->next; //光标上移
				pointer->ch=word;		//实现更新
			}
			else if (!insert)
			{
				Node *p = new Node;
				p->ch = word;
				p->last = pointer;
				p->next = pointer->next;
				if(pointer->next!=NULL)
				{
					p->next->last=p;//若有元素在前，则关联。
				}
				pointer->next=p;
				pointer=pointer->next;
			}
		}
	}
	pointer=head->next;
	while(pointer!=NULL)
	{
		cout<<pointer->ch;
		pointer=pointer->next;
	}
	return 0;
}