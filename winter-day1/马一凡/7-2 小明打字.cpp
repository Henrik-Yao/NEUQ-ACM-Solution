#include <iostream>
#include <cstring>
using namespace std;

typedef struct Node{
	char data;
	struct Node* pre, *next;
	Node(char _data) : data(_data) {} 
}*List;

List Insert_List(){
	List L = new Node(0); 
 	L->next = L->pre = L; 
	return L;
}

int main(){
	List L = Insert_List();
	List p = L; 
	char c; 
	int is_insert = 1; 
	while(1){
		scanf("%c",&c);
		if(c == '\n') break; 
		if('a' <= c && c <= 'z' || c == ' '){
			if(!is_insert) {
				p->next->data = c; 
				p = p->next; 
			}
			else{
				List q = new Node(c);
				q->data = c;
				q->next = p->next;
				q->next->pre = q;
				p->next = q;
				q->pre = p;
				p = q;
			}
		}
		else if(c == '[')
			p = L;
		else if(c == ']')
			p = L->pre; 
		else if(c == '{'){
			if(p != L){	
				p = p->pre; 
			} 	
		}
		else if(c == '}') 
		{
			if(p->next != L)
				p = p->next; 
		}
		else if(c == '-')
			is_insert ^= 1; 
		else{
			if(p != L){
				p = p->pre;
				p->next = p->next->next;
				p->next->pre = p;
			}
		}
	}
	for(List p = L->next; p != L; p = p->next)
		printf("%c" , p->data);
}


