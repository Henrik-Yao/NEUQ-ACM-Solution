#include<iostream>
#include<string>
using namespace std;

struct node{
	char it;
	node *pre, *nex;
	
	node(void)
	{
		it='\0';
		pre=nex=NULL;
	}
};

class tex{
	node *head, *tail;
	node *oper;
	
	public:
	tex(void)
	{
		head=new node;
		tail=new node;
		head->nex=tail;
		tail->pre=head;
		oper=tail;
	}
	
	void add(char ch, bool insert)
	{
		if(insert||oper==tail)//���ڲ���״̬�����ߵ�ǰ�����ַ���tailʱ 
		{
			node *self=new node;
			self->it=ch;
			self->pre=oper->pre;
			self->nex=oper;
			self->pre->nex=self;
			oper->pre=self;
		}
		else
		{
			oper->it=ch;//���ڸ�д״̬
			oper=oper->nex;//���������һλ 
		}
		return;
	}
	void del(void)//ɾ����ǰ����λ��ǰ���ַ�
	{
		if(oper->nex==head)	return;
		node *it=oper->pre;
		oper->pre->pre->nex=oper;
		oper->pre=oper->pre->pre;
		delete it;
		return;
	} 
	
	void left(void)//ǰ��һλ 
	{
		if(oper->pre!=head)	oper=oper->pre;
		return;
	}
	void righ(void)//����һλ 
	{
		if(oper->nex!=NULL)	oper=oper->nex;
		return;
	}
	
	void home(void)//�Ƶ���ͷ 
	{
		oper=head->nex;
		return;
	}
	void endd(void)//�Ƶ���β 
	{
		oper=tail;
		return;
	}
	
	string give(void)//ת���ַ��� 
	{
		string stri;
		node *self=head->nex;
		while(self!=tail)
		{
			stri+=self->it;
			self=self->nex;
		}
		return stri;
	}
	
	~tex(void)
	{
		oper=tail;
		while(oper->pre!=head)	del();
		delete head;
		delete tail;
	}
};

int main()
{
	string con;
	tex text;
	bool insert=true;
	getline(cin, con);
	for(int i=0; con[i]!='\0'; i++)
	switch(con[i])
	{
		case '[':
			text.home();
			break;
		case ']':
			text.endd();
			break;
		case '{':
			text.left();
			break;
		case '}':
			text.righ();
			break;
		case '-':
			insert=!insert;
			break;
		case '=':
			text.del();
			break;
		default:
			text.add(con[i], insert);
	}
	cout<<text.give();
	return 0;
}
