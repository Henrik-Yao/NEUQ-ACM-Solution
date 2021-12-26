#include <bits/stdc++.h> 
using namespace std ;
typedef struct in{
    char ch;
    in* next;
    in* prev;
} * List;
int main()
{
    char ch;//输入字符 
    List start,end,tmp;//定义头节点，终止节点，光标节点。 
    List L = new in();
    start = L;end = L;tmp = L;
    bool Insert = true;//定义输入状态 ，插入还是替换 
    List ins;
    while (scanf("%c", &ch) && ch != '\n') 
	{
        if (ch == '[')
		{
            tmp = start;//光标移动至开头 
        }
		else if (ch == ']')
		{
            tmp = end;//光标移动至结尾 
        }
		else if (ch == '{')
		{
            if (tmp->prev)
				tmp = tmp->prev;//光标向前移动 
        }
		else if (ch == '}')
		{
            if (tmp->next)
				tmp = tmp->next;//光标向后移动 
        }
		else if (ch == '-')
		{
            Insert = !Insert;//更改输入状态 
        }
		else if (ch == '=')//删除光标 
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
                if (tmp->next == NULL) end = tmp;  //如果是将最后一个删除了, 更新终止 
            }
        }
		else {  //直接开始输入 
            ins = new in();
            ins->ch = ch;
            ins->next = tmp->next;
            ins->prev = tmp;
            tmp->next = ins;
            tmp = ins;
            if (tmp->next == NULL) end = tmp;  //如果插入在最后, 更新终止
            if (!Insert && tmp->next)
			{  //如果是替换状态, 且tmp下一个存在, 再删除tmp下一个
                List t = tmp->next;
                if (t->next)
				{
                    tmp->next = t->next;
                    t->next->prev = tmp;
                    delete t;
                }
				else
				{	//后面不存在 
                    delete t;
                    end = tmp;  //终止
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

