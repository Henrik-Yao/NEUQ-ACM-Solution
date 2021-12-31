#include <algorithm>  //7-1 С������ (10��)
#include <cstring>
#include <iostream>
using namespace std;

typedef struct lb {//��������ṹ��
    char ch;
   lb* next;
   lb* prev;
} *jd;//�ڵ�����

int main() {
    char ch;
   jd start, end, tmp;  //����ͷ�ڵ�����, ÿ�β���tmp����
    jd L = new lb();
    start = L;
    end = L;
    tmp = L;

    bool isInsert = true;//��ʼ������insert�����룩״̬��false�����滻״̬

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
        else if (ch == '=') {  //ɾ��tmp
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
                if (tmp->next == NULL) end = tmp;  //�����ɾ������, ����end
            }
        }
        else {  // tmp�������
            ins = new lb();
            ins->ch = ch;
            ins->next = tmp->next;
            ins->prev = tmp;
            tmp->next = ins;
            tmp = ins;
            if (tmp->next == NULL) end = tmp;  //������������, ����end
            if (!isInsert && tmp->next) {  //������滻, ��tmp��һ������, ��ɾ��tmp��һ��
               jd t = tmp->next;
                if (t->next) {
                    tmp->next = t->next;
                    t->next->prev = tmp;
                    delete t;
                }
                else {	//ɾ��Ԫ����ĩβ
                    delete t;
                    end = tmp;  //����end
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

