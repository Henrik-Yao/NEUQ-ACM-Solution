#include <iostream>
using namespace std;
int minnu;
void Find(int a[],int f,int front,int end){
    if(front==end) {
    	minnu=min(minnu,end);
	}
    else{
		int mid=(front+end)/2;
  	  if(a[mid]>=f) Find(a,f,front,mid);
  	  else if(a[mid]<f) Find(a,f,mid+1,end);
  }
}
int main(){
    int Nu,fi;
    scanf("%d %d",&Nu,&fi);
    int a[Nu];
    minnu=Nu;
    for(int i=0;i<Nu;i++) scanf("%d",&a[i]);
    if(a[Nu-1]<fi) {
    	printf("%d",minnu+1);
    	return 0;
	}
    Find(a,fi,0,Nu-1);
    printf("%d",minnu+1);
}
