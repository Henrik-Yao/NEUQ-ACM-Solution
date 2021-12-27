#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef char StackData,QueueData;
 
typedef struct node{
    StackData data;
    struct node *link;
}StackNode,QueueNode;
 
typedef struct linkStack{
    StackNode* top;
}LinkStack;
 
typedef struct{
    QueueNode *rear,*front;
}LinkQueue;
 
void InitStack(LinkStack *s)
{
    s->top=NULL;
}
int Push(LinkStack *S,StackData x) 
{
    StackNode *p=(StackNode*)malloc(sizeof(StackNode));
    if(!p) return 0;
    p->data=x;
    p->link=S->top;
    S->top=p;
    return 1;
}
int PoP(LinkStack *s,StackData *x) 
{
    if(s==NULL||s->top==NULL)
        return 0;
    StackNode *p=s->top;
    *x=p->data;
    s->top=p->link;
    free(p);
    return 1;
}
void InitQueue(LinkQueue *q)
{
    q->rear=q->front=NULL;
}
int EnQueue(LinkQueue *Q,QueueData x)
{
    QueueNode *p=(QueueNode*)malloc(sizeof(QueueNode));
    if(!p) return 0;
    p->data=x;
    p->link=NULL;
    if(Q->front==NULL) 
        Q->front=Q->rear=p;
    else
        Q->rear->link=p;
    Q->rear=p;
    return 1;
}
int DeQueue(LinkQueue *Q,QueueData *x)
{
    if(Q->front==NULL) return 0;
    QueueNode *p=Q->front;
    *x=p->data;
    Q->front=Q->front->link;
    free(p);
    return 1;
}
int main(int argc, const char * argv[]) {
    char c;
    char demon[MAX_SIZE];
    char data;
    LinkStack S;
    LinkQueue Q;
    InitQueue(&Q);
    InitStack(&S);
    
    int i=0;
    while((c=getchar())!='#') 
    {
        demon[i]=c;
        i++;
    }
    for(int j=i-1;j>=0;j--)  
        Push(&S,demon[j]);
    while(PoP(&S,&data))
    {
        if(data=='A')
            printf("sae");
        else if(data=='B')
            printf("tsaedsae");
        else if(data=='(')
        {
            char frontdata;
            while(data!=')')
            {
                PoP(&S,&data);
                EnQueue(&Q, data);
            }
            DeQueue(&Q,&data); 
            frontdata=data;
            while(DeQueue(&Q, &data))
            {
                Push(&S,frontdata);
                Push(&S,data);
            }
        }
        else if(data==')')
        {}
        else
            printf("%c",data);
    }
    return 0;
}
