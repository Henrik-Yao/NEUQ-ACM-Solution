 #include<iostream>
 #include<stdlib.h> 
using namespace std;
int b[100]={0};
    typedef struct Tree
{
	int data;
	struct Tree *lchild,*rchild;
}Tree,*tree;
tree CreateBiTree1(){
    int Data;
    tree node;
    scanf("%d",&Data);
    if (Data == 0) {
        node = NULL;
    }
    else{
        node = (tree)malloc(sizeof(Tree));
        node->data = Data;
        node->lchild = CreateBiTree1();
        node->rchild =CreateBiTree1();
    }
	return node;
}
 
int sum=0;
int ii=1;
void P( tree BT ){
	if(BT){
		 
		if(BT->lchild==NULL&&BT->rchild==NULL)
			b[ii]+=BT->data;
			 
		P(BT->lchild); 
		P(BT->rchild); 
		 if(BT->lchild!=NULL&&BT->rchild!=NULL)ii++;
	}
	return ;
}
int  compare(int *a,int k){
	int i, j, temp=a[0],l=0;
	for (j = 1; j < k ; j++)
	{
		 if(temp<=a[j]){
			temp = a[j];
			 l=j;}	 
	}
	
	return l;
}
int main(){
	
     tree T = NULL;
     T = CreateBiTree1();
     
     if(T->lchild==NULL&&T->rchild==NULL){cout<<"0";return 0;}
      P(T);
      
   int l=  compare(b,ii);
      
      cout<<l<<endl;
      
    return 0;
}

