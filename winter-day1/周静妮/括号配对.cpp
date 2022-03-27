#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
#define MAX 1001
typedef char ElementType;

typedef struct stack {
	ElementType  a;
	struct stack *next;
} List,*lp;

struct stack *create();
int Push(lp L,ElementType x);
int Pop(lp L,ElementType e);

int main(void) {

	char s[MAX];//新建一个数组并存储输入的代码
	gets(s);
	int i=0,flag=1;
	lp L=NULL;
	L=create();

	while(s[i]!='\0') {//开始对数组遍历
	//在遍历过程中，只对括号元素反应。
		if(s[i]=='(') {
			Push(L,'(');//遇到左括号就进行压栈
		} else if(s[i]=='[') {
			Push(L,'[');
		} else if(s[i]=='{') {
			Push(L,'{');
		} else if(s[i]==')') {
			if(Pop(L,'(')!=1) flag=0 ;//这里我直接用相应的左括号去配对
		} else if(s[i]==']') {
			if(Pop(L,'[')!=1) flag=0 ;
		} else if(s[i]=='}') {
			if(Pop(L,'{')!=1) flag=0 ;
		}
		i++;
	}
    if(L->next!=NULL) flag=0;

	if(flag==1) {
		printf("yes\n");
	} else {
		printf("no\n");
	}
}

struct stack *create() {
	lp s=NULL;
	s=(lp)malloc(sizeof(lp));
	s->next=NULL;
	return s;
}

int Push(lp L,ElementType x) {
	lp p=(lp)malloc(sizeof(lp));
	p->a=x;
	p->next=L->next;
	L->next=p;
	return 1;
}

int Pop(lp L,ElementType e) {
	lp p=(lp)malloc(sizeof(lp));
	if(L->next==NULL) return 0;
	p=L->next;
	if(p->a==e) {
		L->next=p->next;
		free(p);
		return 1;
	} else {
		return 0;
	}
}

