#include <iostream>
#include <vector>
#include <cstdio>
#define N 1001
using namespace std;

int n,a[N]; 

void adjust(int len , int x)
{
    int ls = 2 * x + 1,rs = 2 * x + 2;
    int maxIdx = x;
    if(ls < len && a[ls] > a[maxIdx]) maxIdx = ls;
    if(rs < len && a[rs] > a[maxIdx]) maxIdx = rs;
    if(maxIdx != x){
        swap(a[maxIdx] , a[x]);
        adjust(len , maxIdx);
    }
}
 
int main(){
    scanf("%d",&n);
	for(int i = 0;i < n;i ++) scanf("%d",&a[i]);
    for(int i = n / 2 - 1;i >= 0;i --)
        adjust(n , i);
 	for(int i = 0;i < n;i ++)
 		printf("%d ",a[i]);
 	printf("\n");
    for(int i = n - 1; i >= 1; i--)
    {
        swap(a[0] , a[i]);           
        adjust(i , 0);
        for(int j = 0;j < n;j ++)
 			printf("%d ",a[j]);
 		printf("\n");
    }
    return 0;
}
