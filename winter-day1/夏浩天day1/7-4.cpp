#include<iostream>
#include<stack>
#include<string.h>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<list>
using namespace std;

struct node
{
	int data;
	struct node *next;
};
 
int main()
{
	struct node *head,*end,*p;
	int t,a;
	head=(struct node*)malloc(sizeof(struct node));
	end=head;
	while(scanf("%d",&a)!=EOF)
	{
	    p=(struct node*)malloc(sizeof(struct node));
	    p->data=a;
		end->next=p;
		end=p;
	}
	end->next=NULL;
	struct node *p1,*p2,*p3;
	for(p1=head->next;p1!=NULL;p1=p1->next)
	{
		for(p2=p1->next;p2!=NULL;p2=p2->next)
		{
			if(p1->data>p2->data)
			{
				t=p1->data;
				p1->data=p2->data;
				p2->data=t;
			}
		}
	}
	struct node *o,*j,*oshu,*jishu;
	oshu=(struct node*)malloc(sizeof(struct node));
	jishu=(struct node*)malloc(sizeof(struct node));
	o=oshu;
	j=jishu;
	head=head->next;
	while(head!=NULL)
    {
        printf("%d",head->data);
		if(head->next!=NULL)printf("->");
        if(head->data%2!=0)//将奇数存入一个新链表
        {
            jishu->next=head;
            jishu=head;
        }
        else//将偶数存入一个新链表
        {
            oshu->next=head;
            oshu=head;
        }
        head=head->next;
    }
	printf("\n");
    oshu->next=NULL;
    jishu->next=NULL;
    j=j->next;
    while(j!=NULL)//输出奇数
	{
		printf("%d",j->data);
		if(j->next!=NULL)printf("->");
		j=j->next;
	}
	printf("\n");
	o=o->next;
	while(o!=NULL)//输出偶数
	{
		printf("%d",o->data);
		if(o->next!=NULL)printf("->");
		o=o->next;
	}
	cout << endl;;
}