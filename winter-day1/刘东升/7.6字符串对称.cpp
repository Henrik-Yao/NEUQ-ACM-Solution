#include<bits/stdc++.h>
using namespace std;
#define MaxSize 60
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;  //设置栈顶指针
}SqStack;  //定义顺序栈类型
void InitStack(SqStack *&s){
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;//空栅 
}
void DestroyStack(SqStack *&s){
       free(s);
}
bool StackEmpty(SqStack *s){
    	return(s->top==-1);
}//判断栅是不是空了 
bool Push(SqStack *&s,ElemType n){
    if(s->top==MaxSize-1)  //进栈判满
    	return false;
    s->top++; //指针加一
    s->data[s->top]=n;
    return true;
}
bool Pop(SqStack *&s,ElemType &e){
    if(s->top==-1)  //出栈判空
    	return false;
    e=s->data[s->top]; //取栈顶元素
    s->top--; //指针减一
    return true;
}
bool symmetry(string str){
    ElemType e;
    SqStack *st;
    InitStack(st);   //初始化栈
    for(int i=0;i<str.length();i++)
	{
          Push(st,str[i]); //进栅 
    }
    for(int i=0;i<str.length();i++){
        Pop(st,e); //头尾比 
    	if(e!=str[i])
		{  //不同
    		DestroyStack(st);  //销毁栈
    		  return false;
    	}
    }
       DestroyStack(st);
       return true;
}
int main()
{
    string str;
    cin>>str;
    bool flag;
    flag=symmetry(str);
    if(flag)
    	cout<<"Yes"<<endl;
    else
    	cout<<"No"<<endl;
}
