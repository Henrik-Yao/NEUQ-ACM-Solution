#include<iostream>
using namespace std;
const int maxn = 20000+5;
typedef struct ENode *Edge;
struct ENode
{
    int idx;
    int w;
    Edge nextEdge;
};
struct VNode
{
    Edge firstEdge;
}nodes[maxn];

void print(int idx)
{
    if(nodes[idx].firstEdge->nextEdge==NULL) return ;

    printf("%d:",idx);
    Edge edge=nodes[idx].firstEdge->nextEdge;
    while(edge)
    {
        printf("(%d,%d,%d)",idx,edge->idx,edge->w);
        edge=edge->nextEdge;
    }
    puts("");
}
//在单链表的有序插入 把edge 插入到 nodes[idx].firstEdge所指向的链表里（以升序的形式）
void insert(int idx,Edge edge)
{
    Edge tmp=nodes[idx].firstEdge;

    int curridx=edge->idx;
    while(tmp->nextEdge&&tmp->nextEdge->idx<curridx) tmp=tmp->nextEdge;//找到按照升序排列该插入的位置
    edge->nextEdge=tmp->nextEdge;
    tmp->nextEdge=edge;
}
int main()
{
    for(int i=0;i<maxn;++i)
    {
        Edge edge=(Edge)malloc(sizeof(Edge));
        edge->nextEdge=NULL;
        nodes[i].firstEdge=edge;
    }

    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;

        Edge edge=(Edge)malloc(sizeof(Edge));
        edge->idx=b,edge->w=w;
        edge->nextEdge=NULL;

        insert(a,edge);
    }
    for(int i=0;i<n;++i) print(i);
}
