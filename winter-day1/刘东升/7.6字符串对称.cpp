#include<bits/stdc++.h>
using namespace std;
#define MaxSize 60
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;  //����ջ��ָ��
}SqStack;  //����˳��ջ����
void InitStack(SqStack *&s){
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;//��դ 
}
void DestroyStack(SqStack *&s){
       free(s);
}
bool StackEmpty(SqStack *s){
    	return(s->top==-1);
}//�ж�դ�ǲ��ǿ��� 
bool Push(SqStack *&s,ElemType n){
    if(s->top==MaxSize-1)  //��ջ����
    	return false;
    s->top++; //ָ���һ
    s->data[s->top]=n;
    return true;
}
bool Pop(SqStack *&s,ElemType &e){
    if(s->top==-1)  //��ջ�п�
    	return false;
    e=s->data[s->top]; //ȡջ��Ԫ��
    s->top--; //ָ���һ
    return true;
}
bool symmetry(string str){
    ElemType e;
    SqStack *st;
    InitStack(st);   //��ʼ��ջ
    for(int i=0;i<str.length();i++)
	{
          Push(st,str[i]); //��դ 
    }
    for(int i=0;i<str.length();i++){
        Pop(st,e); //ͷβ�� 
    	if(e!=str[i])
		{  //��ͬ
    		DestroyStack(st);  //����ջ
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
