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
	char a[100100];
	while(~scanf("%s",a)){
	StackNode *stack;
	char e,num;
	int i,l,sum=0,flag=1;
	int x=1,y=1;
	stack = InitLinkStack();
	l = strlen(a);
	for(i=0; i<l; i++){
		if(a[i] == '('){
			Push(stack,a[i]);
		}
		else{
			if(stack->next == NULL){
				sum++;
				x++;
				flag=0;
				continue;
			}
			num = Pop(stack);
		}
	}
	
	if(i == l){
		if(stack->next == NULL && flag==1){
			cout << "Match" << endl;
		}	 
		else{
			while(stack->next != NULL){
				sum++;
				y++;
				flag = 0;
				num=Pop(stack);
			}
		}
	}
	if(flag == 0){
		cout << sum << endl;
		while(--x){
			cout << "(";
		}
		cout << a;
		while(--y){
			cout << ")";
		}
        cout << endl;
	}
}
	return 0;
} 
