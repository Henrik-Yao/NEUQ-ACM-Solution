#include <iostream>
#include <vector>
#include <cstdio>
#define N 1001
using namespace std;

int n,t1,t2,L[N],R[N],a[N]; 

void change(int &a , int &b){int c = a;a = b;b = c;}

void sort(int l , int r){
	if(l >= r) return;
	int x = a[l],p1 = l,p2 = r;
	while(p1 < p2){
		while(p1 < p2 && a[p2] > x)
			p2 --;
		while(p1 < p2 && a[p1] <= x)
			p1 ++;
		change(a[p1] , a[p2]);
	}
	change(a[p1] , a[l]);
	for(int i = 1;i <= n;i ++)
		printf("%d ",a[i]);
	printf("\n");
	sort(l , p1 - 1);sort(p1 + 1 , r);
}

int main(){
    scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
    sort(1 , n);
    for(int i = 1;i <= n;i ++)
    	printf("%d ",a[i]);
    printf("\n");
    return 0;
}
