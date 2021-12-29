#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef struct node {   
    node *parent = NULL;  
    node *left = NULL;    
    node *right = NULL;   
    int weight;         
}node,*hfmtree;

int MIN(hfmtree *nodes,int n) {
    int min = nodes[0]->weight; 
    int flag;   
    for (int i = 0; i <= n - 1; i++) {
        if (nodes[i]->weight <= min) {
            min = nodes[i]->weight;
            flag = i;
        }
    }
    return flag;

}
void deletenode(hfmtree *nodes, int n, int m) { 
    for (int i = n; i <= m - 2; i++) {
        nodes[i] = nodes[i + 1];
    }
}

void insertnode(hfmtree *nodes,hfmtree newnode,int m) {
    nodes[m] = newnode;
}

int gethfmtreelength(hfmtree tree,int depth) {
  
    if (!tree->left && !tree->right) {
        return tree->weight * depth;
    }
        
    else {
        return gethfmtreelength(tree->left, depth + 1) + gethfmtreelength(tree->right, depth + 1);
    }
}

void  creathfm(hfmtree &ht,int *w,int n) {
    hfmtree nodes[63]; 
    int m = n;
    for (int i = 0; i <= n - 1; i++) {
        hfmtree newnode = (hfmtree) malloc(sizeof(node));
        newnode->weight = w[i];    
        newnode->left = newnode->right = NULL;  
        nodes[i] = newnode;  
    }
    for (int i = 0; i <= n - 2; i++) {
        int min1, min2;
        hfmtree newhfmtree = (hfmtree) malloc(sizeof(node));
        min1 = MIN(nodes, m);
        newhfmtree->left = nodes[min1]; 
        deletenode(nodes, min1, m);
        m = m - 1;
        min2 = MIN(nodes, m);
        newhfmtree->right = nodes[min2];
        deletenode(nodes, min2, m);
        m = m - 1;
        newhfmtree->weight = newhfmtree->left->weight + newhfmtree->right->weight;
        
        insertnode(nodes, newhfmtree, m);
        m = m + 1; 
        ht = newhfmtree;
    }
}

typedef struct node2 {     
    node2 *left;    
    node2 *right;  
    int ifleaf = 0;      
}node2,*qianzhuitree;

int compare(qianzhuitree &ht,char *str) {
    int length = strlen(str); 
    qianzhuitree point = ht;
    for (int i = 0; i <= length - 1; i++) {
          if (str[i] == '0') { 
              if (!point->left) { 
                  if (point->ifleaf == 1)
                      return 1;
                  else {
                      qianzhuitree newnode = (qianzhuitree) malloc(sizeof(node2));
                      newnode->left = newnode->right = NULL;
                      point->left = newnode; 
                      point = point->left; 
                      if (i == length - 1)  
                          point->ifleaf = 1;
                  }
              } else { 
                  point=point->left;
                  if (point->ifleaf == 1)
                      return 1; 
                  if (i == length - 1) 
                      return 1;
              }
          }
          if (str[i] == '1') { 
              if (!point->right) { 
                  if (point->ifleaf == 1)
                      return 1;
                  else {
                      qianzhuitree newnode = (qianzhuitree) malloc(sizeof(node2));
                      newnode->left = newnode->right = NULL;
                      point->right = newnode; 
                      point = point->right; 
                      if (i == length - 1)  
                          point->ifleaf = 1; 
                  }
              } else { 
                  point = point->right; 
                  if (point->ifleaf == 1)
                      return 1; 
                  if (i == length - 1) 
                      return 1;
              }
          }
      }
      return 0;
}
void creatqianzhuitree(qianzhuitree &ht,char* str) { 
    qianzhuitree point = ht; 
    for (int i = 0; i <= strlen(str) - 1; i++) {
        if (str[i] == '0') { 
            qianzhuitree newnode = (qianzhuitree) malloc(sizeof(node2));
            newnode->left=newnode->right=NULL;
            point->left = newnode; 
            point = point->left; 
            if (i == strlen(str) - 1) 
                point->ifleaf = 1;
        }
        if (str[i] == '1') {
            qianzhuitree newnode = (qianzhuitree) malloc(sizeof(node2));
            newnode->left=newnode->right=NULL;
            point->right = newnode; 
            point = point->right; 
            if (i == strlen(str) - 1) 
                point->ifleaf = 1;
        }
    }
}
int main(void) {
    int n1, w[63];
    scanf("%d", &n1);
    char c; 
    int t; 
    for (int i = 0; i <= n1 - 1; i++) {
        cin >> c;
        cin >> w[i];
    }
    hfmtree tree; 
    creathfm(tree, w, n1); 
    int length = gethfmtreelength(tree, 0);
    int n2;  
    cin >> n2;
    int out[1000] = {0}; 
    int sum[1000] = {0}; 
    for (int i = 0; i <= n2 - 1; i++) { 
        qianzhuitree tree2 = (qianzhuitree) malloc(sizeof(node2));
        tree2->left=NULL;
        tree2->right=NULL;
        for (int j = 0; j <= n1 - 1; j++) {
            char str[63]; 
            cin >> c >> str; 
            sum[i] = sum[i] + w[j] * strlen(str);
            int flag = 0; 
            if (j == 0) 
                creatqianzhuitree(tree2, str);
            else 
                flag = compare(tree2, str); 
            if (flag == 1)  
                out[i] = flag; 
        }
    }
    for (int i = 0; i <= n2 - 1; i++) {
        if(out[i]==0&&sum[i]==length) printf("Yes\n");
        else printf("No\n");
    }
}

