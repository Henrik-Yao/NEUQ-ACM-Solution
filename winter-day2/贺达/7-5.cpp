#include<bits/stdc++.h>
using namespace std;
typedef int Status;
typedef struct HTNode{
    unsigned int weight;
    unsigned int parent;
    unsigned int lchild,rchild;
}HTNode,*HuffmanTree;
typedef char ** HuffmanCode;
Status Select(HuffmanTree &HT,int n,int &s1,int &s2);
void HuffmanTree_Create(HuffmanTree &HT, int *w,int n)
{
    int i,m,s1,s2;
    m = 2*n-1;
    HT = (HTNode*)malloc((m+1)*sizeof(HTNode));
    HTNode *p;
    for(p = HT+1,i = 1;i <= n;++i,++p,++w){
        p->weight = *w;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    }
    for(;i <= m;++i,++p,++w){
        p->weight = 0;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    }
    for(i = n+1;i <= m;++i){
        Select(HT,i-1,s1,s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

void Huffman_coding(HuffmanTree HT,HuffmanCode &HC,int n)
{
    int i,c,f,start;
    char *cd;
    HC = (HuffmanCode)malloc((n+1)*sizeof(char*));
    cd = (char*)malloc(n*sizeof(char));
    cd[n-1] = '\0';
    for(i = 1;i <= n;++i){
        start = n-1;
        for(c = i,f = HT[i].parent;f != 0;c = f,f = HT[f].parent){
            if(HT[f].lchild == c)
            cd[--start] = '0';
            else cd[--start] = '1';
			}
            HC[i] = (char*)malloc((n-start)*sizeof(char));
            strcpy(HC[i],&cd[start]);

    }
    free(cd);
}

Status Select(HuffmanTree &HT,int n,int &s1,int &s2)
{
	int i,min1 = -1,min2 = -1,j,temp;
	for(i = 1;i <= n;++i){
		if(HT[i].parent == 0){
			min1 = i;
			break;
		}
	}
	for(j = i+1;j <= n;++j){
		if(HT[j].parent == 0){
			min2 = j;
			break;
		}
	}
	for(i = j+1;i <= n;++i){
		if(HT[i].parent == 0&&HT[i].weight<HT[min1].weight)min1 = i;
		else if(HT[i].parent == 0&&HT[i].weight < HT[min2].weight&&HT[i].weight >= HT[min1].weight)min2 = i;
	}
	s1 = min1;
	s2 = min2;
	return 0;
}
int main()
{
    int a[2000],i,n,m,k,j,m1,i1,min,sum2,sum1,l;
    char s[2000],s2[2000];
    int s1[2000];
    scanf("%d",&n);
    for(i=0;i<n;++i){
        getchar();
        scanf("%s",s+i);
        scanf("%d",a+i);
    }
    scanf("%d",&k);
    HuffmanTree HT;
    HuffmanCode HC;
    HuffmanTree_Create(HT,a,n);
	Huffman_coding(HT,HC,n);
    HuffmanCode HC1;
    HC1=(HuffmanCode)malloc((n+1)*sizeof(char*));
    for(j=0;j<k;++j){
    for(i=1;i<=n;++i){
        HC1[i]=(char*)malloc(n*sizeof(char));
        getchar();
        scanf("%s",s2+i);
        scanf("%s",HC1[i]);

    }
    min=1;
    for(l = 1;l <= n;++l)
    {
        if(min == 0)break;
    for(i=l+1;i<=n;++i)
    {
        m = strlen(HC1[l]);
        m1 = strlen(HC1[i]);
        if(m >= m1)//一定不要忘记等于的情况
            if(strncmp(HC1[i],HC1[l],m1) == 0){min = 0;break;}
        else if(m1>m)
            if(strncmp(HC1[l],HC1[i],m) == 0){min = 0;break;}
    }
    }
    if(min == 1)s1[j] = 1;
    else s1[j] = 0;
        sum1 = 0;
        sum2 = 0;
    for(i = 1;i <= n;++i){
        m = strlen(HC1[i]);
        m1 = strlen(HC[i]);
        sum1+=m1*a[i-1];
        sum2+=m*a[i-1];
    }
    if(sum1 == sum2);
    else s1[j] = 0;
}
    for(i = 0;i<k;++i){
        if(s1[i] == 1)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
