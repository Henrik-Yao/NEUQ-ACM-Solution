#include <algorithm>  //7-1 小明打字 (10分)
#include <cstring>
#include <iostream>
using namespace std;

typedef struct lb {//构建链表结构体
    char ch;
   lb* next;
   lb* prev;
} *jd;//节点数据

int main() {
    char ch;
   jd start, end, tmp;  //带空头节点链表, 每次插入tmp后面
    jd L = new lb();
    start = L;
    end = L;
    tmp = L;

    bool isInsert = true;//初始现在是insert（输入）状态，false就是替换状态

   jd ins;
    while ((ch=getchar())!= '\n') {
        if (ch == '[') {
            tmp = start;
        }
        else if (ch == ']') {
            tmp = end;
        }
        else if (ch == '{') {
            if (tmp->prev) tmp = tmp->prev;
        }
        else if (ch == '}') {
            if (tmp->next) tmp = tmp->next;
        }
        else if (ch == '-') {
            isInsert = !isInsert;
        }
        else if (ch == '=') {  //删除tmp
            if (tmp->prev) {
               jd t = tmp;
                tmp->prev->next = tmp->next;
                if (tmp->next) {
                    tmp->next->prev = tmp->prev;
                    tmp = tmp->prev;
                }
                else {
                    tmp = tmp->prev;
                    tmp->next = NULL;
                }
                delete t;
                if (tmp->next == NULL) end = tmp;  //如果是删除最后的, 更新end
            }
        }
        else {  // tmp后面添加
            ins = new lb();
            ins->ch = ch;
            ins->next = tmp->next;
            ins->prev = tmp;
            tmp->next = ins;
            tmp = ins;
            if (tmp->next == NULL) end = tmp;  //如果插入在最后, 更新end
            if (!isInsert && tmp->next) {  //如果是替换, 且tmp下一个存在, 再删除tmp下一个
               jd t = tmp->next;
                if (t->next) {
                    tmp->next = t->next;
                    t->next->prev = tmp;
                    delete t;
                }
                else {	//删除元素在末尾
                    delete t;
                    end = tmp;  //更新end
                    tmp->next = NULL;
                }
            }
        }
        
    }

    tmp = start->next;
    while (tmp) {
       cout<< tmp->ch;
        tmp = tmp->next;
    }
    cout << endl;

    return 0;
}

