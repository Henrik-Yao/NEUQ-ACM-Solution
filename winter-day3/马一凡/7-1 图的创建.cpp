#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//结点的定义
typedef char VertexType;
typedef int EdgeType;
#define MaxVex 100000

typedef struct EdgeNode //边表结点
{
    int adjvex; //邻接点域，存储邻接顶点对应的下标
    int flag; //用于存储权值，对于非网图可以不需要
    struct EdgeNode *next; //链域，指向下一个邻接点
}EdgeNode;

typedef struct VertexNode  //顶点表结点
{
	int node;
	int vs;
    EdgeNode *firstedge; //边表头指针
}VertexNode,AdjList[MaxVex];
 
typedef struct
{
    AdjList adjList;
    int numVertexes,numEdges; //图中当前顶点数和边数
}GraphAdjList;



//建立无向图的邻接表结构
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
		G->adjList[i].firstedge = NULL;       //将边表置为空表
	}
    
    for(i=0; i< (G->numEdges); i++)	
    {
        scanf("%d %d %d",&x,&y,&z);
        p = G->adjList[x].firstedge; 
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); //向内存申请空间，生成边表结点
        e->flag = z;
        e->adjvex = y; //邻接序号为j	
        if(p == NULL){
			G->adjList[x].firstedge = e;
			e->next = NULL;
		} 
        else{
        	while(p->next != NULL&&p->next->adjvex < e->adjvex){
        		p = p->next;
			}
			if (p==G->adjList[x].firstedge) //要考虑一下如果当前的p是头指针,就是要判断这个e到底是插在p前还是p后,p前就要再用e更新一下头指针
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

int main(){
	GraphAdjList *G;
	EdgeNode *e;
	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	G = (GraphAdjList *)malloc(sizeof(GraphAdjList));
	CreateALGraph(G); 
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

 
/*
7 3
0 3 7
0 1 5
0 6 6
*/

