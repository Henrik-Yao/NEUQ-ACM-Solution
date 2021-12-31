#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//���Ķ���
typedef char VertexType;
typedef int EdgeType;
#define MaxVex 100000
int k;

typedef struct EdgeNode //�߱���
{
    int adjvex; //�ڽӵ��򣬴洢�ڽӶ����Ӧ���±�
    int flag; //���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ
    struct EdgeNode *next; //����ָ����һ���ڽӵ�
}EdgeNode;

typedef struct VertexNode  //�������
{
	int node;
	int vs;
    EdgeNode *firstedge; //�߱�ͷָ��
}VertexNode,AdjList[MaxVex];
 
typedef struct
{
    AdjList adjList;
    int numVertexes,numEdges; //ͼ�е�ǰ�������ͱ���
}GraphAdjList;



//��������ͼ���ڽӱ�ṹ
void CreateALGraph(GraphAdjList *G)
{
    int i,j,k;
    int x,y,z;
    EdgeNode *e;
    EdgeNode *p;
    scanf("%d %d", &G->numVertexes,&G->numEdges);
    p = (EdgeNode *)malloc(sizeof(EdgeNode));
    for(int i=0; i<(G->numVertexes); i++){
		G->adjList[i].vs = 0;
		G->adjList[i].firstedge = NULL;       //���߱���Ϊ�ձ�
	}
    
    for(i=0; i< (G->numEdges); i++)	
    {
        scanf("%d %d %d",&x,&y,&z);
        p = G->adjList[x].firstedge; 
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); //���ڴ�����ռ䣬���ɱ߱���
        e->flag = z;
        e->adjvex = y; //�ڽ����Ϊj	
        if(p == NULL){
			G->adjList[x].firstedge = e;
			e->next = NULL;
		} 
        else{
        	while(p->next != NULL&&p->next->adjvex < e->adjvex){
        		p = p->next;
			}
			if (p==G->adjList[x].firstedge) //Ҫ����һ�������ǰ��p��ͷָ��,����Ҫ�ж����e�����ǲ���pǰ����p��,pǰ��Ҫ����e����һ��ͷָ��
			{
				if (p->adjvex > e->adjvex)
				{
					e->next=p;
					G->adjList[x].firstedge=e;
				}
				else
				{
					e->next=p->next;
				    p->next=e;
				}
			}
			else
			{
				e->next=p->next;
				p->next=e;
			}
			//printf("%d %d %d\n",e->adjvex,p->adjvex,e->adjvex);
		}
    }
    return;
}

void DeleteArc(GraphAdjList *G)
{
	int i,j;
	EdgeNode *p,*pre,*del; //delΪ��ɾ����㣬preΪdelǰ��
	for(int t=0; t<k; t++){
		scanf("%d %d",&i,&j);
		pre = G->adjList[i].firstedge;
		for(p=G->adjList[i].firstedge; ; p=p->next)
		{
			
			if(p->adjvex==j)
			{
				if(p == G->adjList[i].firstedge)	//��ɾ�������Ϊ��һ�����
				{
					del = p;
					p = p->next;
					G->adjList[i].firstedge = p;
					free(del);	//ɾ�������
					pre = NULL;
	
					G->numEdges--;	//��������һ
					break;
				}
				else		//��ɾ������㲻�ǵ�һ�����
				{
					del = p; 
					p = p->next;
					pre->next = p;
					free(del);	//ɾ�������
	
					G->numEdges--;	//��������һ
					break;
				}
			}
			pre=p;
		}
	}
	return;
}


int main(){
	GraphAdjList *G;
	EdgeNode *e;

	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	G = (GraphAdjList *)malloc(sizeof(GraphAdjList));
	CreateALGraph(G); 
	cin >> k;
	DeleteArc(G);
	
	for(int i=0; i<(G->numVertexes); i++){
		e = G->adjList[i].firstedge;
		if (e!=NULL)
		{
		  printf("%d:",i);
		  while(e != NULL){
			printf("(%d,%d,%d)",i,e->adjvex,e->flag);
			e = e->next;
	 	  }
		  printf("\n");
 	   } 
	} 	
	return 0;
}


