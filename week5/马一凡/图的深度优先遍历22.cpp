#include<iostream>
#include<bits/stdc++.h>
using namespace std;


typedef char VertexType;
typedef int EdgeType;
#define MaxVex 100000
typedef struct EdgeNode 
{
    int adjvex; 
    int flag; 
    struct EdgeNode *next; 
}EdgeNode;
typedef struct VertexNode  
{
	int node;
	int vs;
    EdgeNode *firstedge; 
}VertexNode,AdjList[MaxVex];
 
typedef struct
{
    AdjList adjList;
    int numVertexes,numEdges; 
}GraphAdjList;




void CreateALGraph(GraphAdjList *G)
{
    int i,j,k;
    int x,y;
    EdgeNode *e;
    scanf("%d %d", &G->numVertexes,&G->numEdges);
    for(int i=0; i<(G->numVertexes); i++){
		G->adjList[i].vs = 0;
		G->adjList[i].firstedge = NULL;       
	}
    
    for(i=0; i< (G->numEdges); i++)	
    {
        scanf("%d %d",&x,&y);
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); 
        e->flag = 0;
        e->adjvex = y; 
        e->next = G->adjList[x].firstedge;
        G->adjList[x].firstedge = e; 
    }
    return;
}

void dfs(int x, GraphAdjList *G){
	EdgeNode *e;
	e = (EdgeNode *)malloc(sizeof(EdgeNode)); 
	e =  G->adjList[x].firstedge; 
	vector<int> v;
	while(e!= NULL){
		int i = e->adjvex;
		v.push_back(i); 
		e = e->next;
	}
	sort(v.begin(),v.end());
	for (int j=0;j<v.size();j++)
	{
	  int i = v[j];
	  if(G->adjList[i].vs == 0)
	  {
		printf("%d ",i);
		G->adjList[i].vs = 1;
		dfs(i, G);
	  }
	}
	return;
}


int main(){
	GraphAdjList *G;
	G = (GraphAdjList *)malloc(sizeof(GraphAdjList));
	CreateALGraph(G); 
	for(int i=0; i<(G->numVertexes); i++){
		if(G->adjList[i].vs == 0){
			G->adjList[i].vs = 1;
			printf("%d ",i);
			dfs(i,G);
		}
		
	}	
	return 0;
}
