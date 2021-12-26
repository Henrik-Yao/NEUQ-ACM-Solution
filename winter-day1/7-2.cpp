#include <algorithm> 
#include <cstring>
#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define Status int

typedef struct LNode 
{
    char ch;
    LNode* next;
    LNode* pre;
} * List;


int main() {
    char ch;
    List start, end, temp;
    List L = new LNode();
    start = L;
    end = L;
    temp = L;

    bool isInsert = true;

    List ins;
    while (scanf("%c", &ch) && ch != '\n')
    {
        if (ch == '[') 
        {
            temp = start;
        } 
        else if (ch == ']') 
        {
            temp = end;
        } 
        else if (ch == '{') 
        {
            if (temp->pre)
            {
                temp = temp->pre;
            }
        } 
        else if (ch == '}') 
        {
            if (temp->next)
            {
                temp = temp->next;
            }
        } 
        else if (ch == '-') 
        {
            if(isInsert)
            {
                isInsert = false;
            }
            else
            {
                isInsert  = true;
            }
        } 
        else if (ch == '=') 
        {
            if (temp->pre) 
            {
                List t = temp;
                temp->pre->next = temp->next;
                if (temp->next) 
                {
                    temp->next->pre = temp->pre;
                    temp = temp->pre;
                } 
                else 
                {
                    temp = temp->pre;
                    temp->next = NULL;
                }
                free(t);
                if (temp->next == NULL) 
                {
                    end = temp;
                }
            }
        } 
        else 
        {  // temp后面添加
            ins = new LNode();
            ins->ch = ch;
            ins->next = temp->next;
            ins->pre = temp;
            temp->next = ins;
            temp = ins;
            if (temp->next == NULL) end = temp;
            if (!isInsert && temp->next) {  //如果是替换, 且temp下一个存在, 再删除temp下一个
                List t = temp->next;
                if (t->next) {
                    temp->next = t->next;
                    t->next->pre = temp;
                    free(t);
                }
                else 
                {	
                    free(t);
                    end = temp;
                    temp->next = NULL;
                }
            }
        }
    }

    temp = start->next;
    while (temp) {
        printf("%c", temp->ch);
        temp = temp->next;
    }
    // 注意清理内存, 这里节省运行时间不清理

    return 0;
}
