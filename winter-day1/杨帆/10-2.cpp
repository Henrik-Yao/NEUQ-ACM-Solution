#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    char data;
    Node *next,*pre;
}*List;

int main(){
    char ch;
    List Start,End,temp;
    List L = new Node();
    Start = L,End = L,temp = L;
    bool Insert = 0;
    List InsertChar;
    while(scanf("%c",&ch) && ch != '\n'){
        if(ch == '['){
            temp = Start;
        }
        else if(ch == ']'){
            temp = End;
        }
        else if(ch == '{'){
            if(temp->pre)   temp = temp->pre;
        }
        else if(ch == '}'){
            if(temp->next)   temp = temp->next;
        }
        else if(ch == '-'){
            Insert = !Insert;
        }
        else if(ch == '='){
            if(temp->pre){
                List t = temp;
                temp->pre->next = temp->next;
                if(temp->next){
                    temp->next->pre = temp->pre;
                    temp = temp->pre;
                }
                else{
                    temp = temp->pre;
                    temp->next = NULL;
                }
                delete t;
            }
            if(temp->next == NULL){
                End = temp;
            }
        }
        else{
            InsertChar = new Node();
            InsertChar->data = ch;
            InsertChar->next = temp->next;
            InsertChar->pre = temp;
            temp->next = InsertChar;
            temp = InsertChar;
            if(temp->next == NULL){
                End = temp;
            }
            if(Insert && temp->next){
                List t = temp->next;
                if(t->next){
                    temp->next = t->next;
                    t->next->pre = temp;
                    delete t;
                }
                else{
                    delete t;
                    End = temp;
                    temp->next = NULL;
                }
            }
        }
    }
    temp = Start->next;
    while(temp){
        printf("%c",temp->data);
        temp = temp->next;
    }
    return 0;
}
