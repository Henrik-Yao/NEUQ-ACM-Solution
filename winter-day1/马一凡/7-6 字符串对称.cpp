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
	char a[100100];
	char num;
	int i,l,flag = 1;
	stack = InitLinkStack();
	scanf("%s",a);
	l = strlen(a);
	
	for(i=0; i<l/2; i++){
		Push(stack,a[i]);
	}
	
	if(l%2 == 0){
		for(i=l/2; i<l; i++){
			num = Pop(stack);
			if(a[i]!=num){
				flag = 0;
				break;
			}
		}
	}
	
	else{
		for(i=l/2+1; i<l; i++){
			num = Pop(stack);
			if(a[i]!=num){
				flag = 0;
				break;
			}
		}
	}
	
	if(flag == 1) cout << "yes";
	else cout << "no";
	
	
	return 0;
}
