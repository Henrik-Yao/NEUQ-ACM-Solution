#include<bits/stdc++.h> 
using namespace std;
typedef struct LNode {
    char ch;
    LNode* next;
    LNode* prev;
} * List;

int main() {
    char ch;
    List start, end, tmp;  
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
        } else if (ch == '=') {  
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
                if (tmp->next == NULL) end = tmp;  
            }
        } else {  
            ins = new LNode();
            ins->ch = ch;
            ins->next = tmp->next;
            ins->prev = tmp;
            tmp->next = ins;
            tmp = ins;
            if (tmp->next == NULL) end = tmp;  
            if (!isInsert && tmp->next) {  
                List t = tmp->next;
                if (t->next) {
                    tmp->next = t->next;
                    t->next->prev = tmp;
                    delete t;
                } else {	
                    delete t;
                    end = tmp;  
                    tmp->next = NULL;
                }
            }
        }
     
    }

    tmp = start->next;
    while (tmp) {
        printf("%c", tmp->ch);
        tmp = tmp->next;
    }
   

    return 0;
}

