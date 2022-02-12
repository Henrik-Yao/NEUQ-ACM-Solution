#include<bits/stdc++.h>
#define M 100
using namespace std;


typedef struct
{
    char *base;
    char *top;
    int stacksize;
}sqstack;

void InitStack(sqstack &S)
{
    S.base = new char[M];
    if(!S.base) exit(0);
    S.top = S.base;
    S.stacksize=M;
}

bool stackempty(sqstack S)
{
    if(S.base==S.top)
    {
        return true;//为空
    }
    else
    {
        return false;
    }
}

int stacklength(sqstack S)
{
    return S.top-S.base;
}

void clearstack(sqstack S)
{
    if(S.base)
    {
        S.top=S.base;
    }
}

void destorystack(sqstack &S)
{
    if(S.base)
    {
        delete S.base;
        S.stacksize=0;
        S.base=S.top=NULL;
    }
}

void push(sqstack &S,char e)
{
    if(S.top-S.base==S.stacksize)
    {
        cout<<"error"<<endl;
    }
    *S.top=e;
    S.top++;
}

char pop(sqstack &S)
{
    char e;
    if(S.top==S.base)
    {
        e='1';
    }
    else
    {
        S.top--;
        e=*S.top;
    }

    return e;
}

int main()
{
    sqstack S;
    InitStack(S);
    char c[M];
    cin.getline(c,M,'\0');
    for(int i=0;i<M;i++)
    {
        if(c[i]=='('||c[i]=='['||c[i]=='{')
            {
                push(S,c[i]);
            }
        else if(c[i]==')')
        {
            if(pop(S)!='(')
            {
                cout<<"no";
                return 0;
            }
        }
        else if(c[i]==']')
        {
            if(pop(S)!='[')
            {
                cout<<"no";
                return 0;
            }
        }
        else if(c[i]=='}')
        {
            if(pop(S)!='{')
            {
                cout<<"no";
                return 0;
            }
        }
        if(c[i]=='\0')
        {
            if(stackempty(S))
            {
                cout<<"yes";
            }
            else
            {
                cout<<"no";
            }
            break;
        }
    }


    return 0;
}
