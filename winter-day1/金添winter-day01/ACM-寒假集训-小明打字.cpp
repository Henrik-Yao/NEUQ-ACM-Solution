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

	Node *head = new Node; //ͷָ��
	Node *pointer = head;  //���

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
			if (pointer->last != NULL) //��ǰ��Ϊ��
				pointer = pointer->last;
		}
		else if (word == '}')
		{
			if (pointer->next != NULL) //����Ϊ��
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
			Node *zan = pointer;	 //��ʱ��
			pointer = pointer->last; //����˸�
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
				pointer=pointer->next; //�������
				pointer->ch=word;		//ʵ�ָ���
			}
			else if (!insert)
			{
				Node *p = new Node;
				p->ch = word;
				p->last = pointer;
				p->next = pointer->next;
				if(pointer->next!=NULL)
				{
					p->next->last=p;//����Ԫ����ǰ���������
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