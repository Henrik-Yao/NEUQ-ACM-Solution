#include <iostream>
using namespace std;
 
struct linknode {
	int data;
	linknode* next;
	linknode* prior;
};
 
int main()
{
	int n, m, k,i;
	cin>>n>>m>>k;
	struct linknode* p,*q,*g;
	p = (struct linknode*)malloc(sizeof(struct linknode)); g = q = p;//创建循环链表
	p->data = 1; p->next = p;
	for (i = 2; i <= n; i++)
	{
		q = (q->next = (struct linknode*)malloc(sizeof(struct linknode)));
		q->prior = g;//g用来存储上一个指针
		q->data = i;
		q->next = p;//新添加节点指向初始节点
		g = g->next;//将g指向新创建的节点
	}
	//将首元素的prior指针指向最后一个节点
	p->prior = g;
	//双向链表创建完毕
	q = p;
	//进行出队
	while (q != q->next)//当队列中不只剩一个人时进行出队
	{
		//首先逆时针出队
		if (m == 1)
		{
			printf("%d", q->data);
			q->next->prior = q->prior;
			q->prior->next = q->next;
			q = q->prior;
		}
		else
		{
			for (i = 2; i < m; i++)
				q = q->prior;
			printf("%d ", q->prior->data);
			q->prior = q->prior->prior;
			q->prior->next = q;//输出并删除该节点
			q = q->prior;//将指针指向删除后的下一位
		}
		//然后顺指针出队
		if (k == 1)
		{
			printf("%d", q->data);
			q->next->prior = q->prior;
			q->prior->next = q->next;
			q = q->next;
		}
		else
		{
			for (i = 2; i < k; i++)
				q = q->next;
			printf("%d ", q->next->data);
			q->next = q->next->next                                                                                                    ;
			q->next->prior = q;//输出并删除该节点
			q = q->next;//将指针指向删除后的下一位
		}
	}
	if (n % 2 == 1)
		printf("%d", p->data);//若为奇数个最后输出单节点
	return 0;
}