#include <bits/stdc++.h>
using namespace std;

int n;
void read(int &x){
	 int f=1;x=0;
	 char ch=getchar();
	 while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	 while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	 x*=f;
}

// void print_arr(int arr[],int n){
//     for(int i = 0;i < n;i++)cout<<arr[i]<<' ';
//     puts("");
//     return;
// }

void Quick_sort(int arr[],int begin,int end){
    if(begin >= end)//这里要加上等于，否则会重复一次无意义的排序
    return;
    int i = begin;
    int j = end;
    int temp = arr[begin];
    while(i != j){
        while(arr[j] > temp && i < j)//这里arr[j] > temp不能加上等号，加上等号后相当于把j对应的数放到了右边，但是答案要求把相同的数放在左边（这是试出来的，没办法，要么WA1次，要么AC）
        j--;
        while(arr[i] <= temp && i < j)
        i++;
        if(j > i)
        swap(arr[j],arr[i]);
    }
    arr[begin] = arr[i];
    arr[i] = temp;
    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }
    puts("");
    Quick_sort(arr,begin,i - 1);
    Quick_sort(arr,i + 1,end);
}


int main(){
    //freopen("more data.txt","r",stdin);
    ios::sync_with_stdio(false);
    cout.tie(0);
    read(n);
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0;i < n;i++)read(arr[i]);
    Quick_sort(arr,0,n - 1);
    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }
    puts("");
    // print_arr(arr,n);
    free(arr);
    return 0;
}