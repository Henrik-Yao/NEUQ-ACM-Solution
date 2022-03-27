#include <bits/stdc++.h>
using namespace std;

int n;
void HeapAdjust(vector<int>&a,int s,int m){//构造大根堆
    int x = a[s];
    for(int i = s * 2;i <= m;i *= 2){
        if(i < m && a[i] < a[i + 1]) i++;
        if(x >= a[i])break;
        a[s] = a[i];
        s = i;
    }    
    a[s] = x;
}

void CreateHeap(vector<int>&a){
    for(int i = n / 2;i > 0;i--){
        HeapAdjust(a,i,n);
    }
}

void Heapsort(vector<int>&a){
    CreateHeap(a);//将输入的数构造成大根堆
    for(int i = 1;i <= n;i++)
    printf("%d ",a[i]);
    puts("");
    for(int i = n;i > 1;i--){
        swap(a[1],a[i]);//将第一个数与未排序好的最后一个数交换
        HeapAdjust(a,1,i - 1);//将前面所有数构造成大根堆
        for(int i = 1;i <= n;i++)
        printf("%d ",a[i]);
        puts("");
    }
    
}
int main(){
    vector<int>a;
    scanf("%d",&n);
    a.resize(n + 1);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    Heapsort(a);
    return 0;
}