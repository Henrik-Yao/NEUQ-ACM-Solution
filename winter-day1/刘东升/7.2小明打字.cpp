#include <bits/stdc++.h> 
using namespace std ;
typedef struct in{
    char ch;
    in* next;
    in* prev;
} * List;
int main()
{
    char ch;//�����ַ� 
    List start,end,tmp;//����ͷ�ڵ㣬��ֹ�ڵ㣬���ڵ㡣 
    List L = new in();
    start = L;end = L;tmp = L;
    bool Insert = true;//��������״̬ �����뻹���滻 
    List ins;
    while (scanf("%c", &ch) && ch != '\n') 
	{
        if (ch == '[')
		{
            tmp = start;//����ƶ�����ͷ 
        }
		else if (ch == ']')
		{
            tmp = end;//����ƶ�����β 
        }
		else if (ch == '{')
		{
            if (tmp->prev)
				tmp = tmp->prev;//�����ǰ�ƶ� 
        }
		else if (ch == '}')
		{
            if (tmp->next)
				tmp = tmp->next;//�������ƶ� 
        }
		else if (ch == '-')
		{
            Insert = !Insert;//��������״̬ 
        }
		else if (ch == '=')//ɾ����� 
		{
            if (tmp->prev)
			{
                List t = tmp;
                tmp->prev->next = tmp->next;
                if (tmp->next)
				{
                    tmp->next->prev = tmp->prev;
                    tmp = tmp->prev;
                }
				else
				{
                    tmp = tmp->prev;
                    tmp->next = NULL;
                }
                delete t;
                if (tmp->next == NULL) end = tmp;  //����ǽ����һ��ɾ����, ������ֹ 
            }
        }
		else {  //ֱ�ӿ�ʼ���� 
            ins = new in();
            ins->ch = ch;
            ins->next = tmp->next;
            ins->prev = tmp;
            tmp->next = ins;
            tmp = ins;
            if (tmp->next == NULL) end = tmp;  //������������, ������ֹ
            if (!Insert && tmp->next)
			{  //������滻״̬, ��tmp��һ������, ��ɾ��tmp��һ��
                List t = tmp->next;
                if (t->next)
				{
                    tmp->next = t->next;
                    t->next->prev = tmp;
                    delete t;
                }
				else
				{	//���治���� 
                    delete t;
                    end = tmp;  //��ֹ
                    tmp->next = NULL;
                }
            }
        }
    }
    tmp = start->next;
    while (tmp)
	{
        printf("%c", tmp->ch);
        tmp = tmp->next;
    }
}

