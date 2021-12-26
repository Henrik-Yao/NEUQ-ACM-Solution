#include<bits/stdc++.h>
using namespace std;
struct SeqStack
{
	char data[1000];
	int top;
};
void InitStack(SeqStack *&s)
{
    s=(SeqStack *)malloc(sizeof(SeqStack));
    s->top=-1;
}
void push(SeqStack *s,char ch)
{
	s->top++;
    s->data[s->top]=ch;
}
char pop(SeqStack *s)
{
	return (s->data[s->top--]);
}
int main()
{
	SeqStack *s;
	int flag=1;
	char str[1000];
	cin>>str;
	int length=strlen(str);
	int mid=length/2-1;
	InitStack(s);
	for(int i=0;i<=mid;i++)
	{
		push(s,str[i]);
	}
	if(length%2!=0)
	{
		mid+=1;
	}
	for(int i=1;i<=length/2;i++)
	{
		if(str[mid+i]!=pop(s))
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		cout<<"yes"<<endl;
	}
	else
    {
    	cout<<"no"<<endl;
	}
	return 0;
}
