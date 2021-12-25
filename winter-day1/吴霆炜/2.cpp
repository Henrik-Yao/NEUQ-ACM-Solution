#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node *pre,*next;
    Node(char _data) : data(_data){}
};

typedef Node *List;

List CreateList(){
    List l = new Node(0);
    l -> next = l -> pre = l;
    return l;
}

int main(){
    List lis = CreateList(),p =  lis;
    char data;
    int is_insert = 1;
    while(scanf("%c",&data) != EOF){
        if(data == '\n')break;
        if(data >= 'a' && data <= 'z' || data == ' '){
            if(!is_insert){
                p -> next -> data = data;
                p = p -> next;
                continue;
            }
        List q = new Node(data);
        q -> data = data;
        q -> next = p -> next;
        q -> next -> pre = q;
        p -> next = q;
        q -> pre = p;
        p = q;  
        }
        else if(data == '[')
            p = lis;
        else if(data == ']')
            p = lis -> pre;
        else if(data == '{'){
            if(p != lis)
                p = p -> pre;
        }
        else if(data == '}'){
            if(p -> next != lis)
                p = p -> next;
        }
        else if(data == '-')
            is_insert ^= 1;
        else{
            if(p != lis){
                p = p -> pre;
                p -> next = p -> next -> next;
                p -> next -> pre = p;
            }
        }
    }
    for(List p = lis -> next;p != lis;p = p -> next)
    printf("%c",p -> data);
    return 0;
}