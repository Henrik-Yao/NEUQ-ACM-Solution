#include<iostream>
#include<malloc.h> 
#include<cstring>
using namespace std;

typedef struct StackNode
	{
		char data ;
		struct StackNode *next ;
	} StackNode;
	
StackNode * InitLinkStack(void)
	{
		StackNode *top ;
		top = (StackNode *)malloc(sizeof(StackNode )) ;
		top->next = NULL ;
		return(top) ;
	}
	
void Push(StackNode *top , char e)
	{
		StackNode *p ;
		p = (StackNode *)malloc(sizeof(StackNode)) ;
		p->data = e ;
		p->next = top->next;
		top->next = p ;
	}
	
char Pop(StackNode *top ){
		StackNode *p;
		p = (StackNode *)malloc(sizeof(StackNode)) ;
		char e;
		p = top->next;
		e = p->data;
		top->next = p->next;
		free(p);
		return e;
	}

	

int main(){
	StackNode *stack;
	char e,num,a[10000];
	int i,l,ll=0;
	stack = InitLinkStack();
	scanf("%s",a);
	l = strlen(a);
	for(i=0; i<l; i++){
		if(a[i] == '('|| a[i] =='['|| a[i]=='{' || a[i]==')' || a[i]==']' || a[i]=='}'){
		ll++;
		if(a[i] == '('|| a[i] =='['|| a[i]=='{'){
			Push(stack,a[i]);
		}
		else{
			if(stack->next == NULL){
				cout << "no";
				break;
			}
			num = Pop(stack);
			if(num == '[') num = ']';
			if(num == '(') num = ')';
			if(num == '{') num = '}';
			if(num != a[i]){
				cout << "no";
				break;
			}
			 
		}
	}
	}
	if(i == l){
		if(stack->next == NULL)
			 cout << "yes";
		else cout << "no";
	}
	
	return 0;
} 
