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
void Quick_sort(int arr[],int begin,int end){
    if(begin >= end)//����Ҫ���ϵ��ڣ�������ظ�һ�������������
    return;
    int i = begin;
    int j = end;
    int temp = arr[begin];
    while(i != j){
        while(arr[j] > temp && i < j)//����arr[j] > temp���ܼ��ϵȺţ����ϵȺź��൱�ڰ�j��Ӧ�����ŵ����ұߣ����Ǵ�Ҫ�����ͬ����������ߣ������Գ����ģ�û�취��ҪôWA1�Σ�ҪôAC��
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
    free(arr);
    return 0;
}
