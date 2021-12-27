#include <algorithm>  
#include <cstring>
#include <iostream>
using namespace std;

typedef struct LNode {
    char ch;
    LNode* next;
    LNode* prev;
} * List;

int main() {
    char ch;
    List start, end, tmp;  //带空头节点链表, 每次插入tmp后面
    List L = new LNode();
    start = L;
    end = L;
    tmp = L;

    bool isInsert = true;

    List ins;
    while (scanf("%c", &ch) && ch != '\n') {
        if (ch == '[') {
            tmp = start;
        } else if (ch == ']') {
            tmp = end;
        } else if (ch == '{') {
            if (tmp->prev) tmp = tmp->prev;
        } else if (ch == '}') {
            if (tmp->next) tmp = tmp->next;
        } else if (ch == '-') {
            isInsert = !isInsert;
        } else if (ch == '=') {  //删除tmp
            if (tmp->prev) {
                List t = tmp;
                tmp->prev->next = tmp->next;
                if (tmp->next) {
                    tmp->next->prev = tmp->prev;
                    tmp = tmp->prev;
                } else {
                    tmp = tmp->prev;
                    tmp->next = NULL;
                }
                delete t;
                if (tmp->next == NULL) end = tmp;  //如果是删除最后的, 更新end
            }
        } else {  // tmp后面添加
            ins = new LNode();
            ins->ch = ch;
            ins->next = tmp->next;
            ins->prev = tmp;
            tmp->next = ins;
            tmp = ins;
            if (tmp->next == NULL) end = tmp;  //如果插入在最后, 更新end
            if (!isInsert && tmp->next) {  //如果是替换, 且tmp下一个存在, 再删除tmp下一个
                List t = tmp->next;
                if (t->next) {
                    tmp->next = t->next;
                    t->next->prev = tmp;
                    delete t;
                } else {	//删除元素在末尾
                    delete t;
                    end = tmp;  //更新end
                    tmp->next = NULL;
                }
            }
        }
        // end->next = NULL;	//保险, 但没必要
    }

    tmp = start->next;
    while (tmp) {
        printf("%c", tmp->ch);
        tmp = tmp->next;
    }
    // 注意清理内存, 这里节省运行时间不清理

    return 0;
}

