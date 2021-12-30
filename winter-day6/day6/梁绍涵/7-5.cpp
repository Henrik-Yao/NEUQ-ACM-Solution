#include<bits/stdc++.h>
using namespace std;
 
void HeapAdjust(int* a, int i, int n)  
{
    int lchild = 2 * i;       
    int rchild = 2 * i + 1;   
    int max = i;             
    if (i <= n / 2) {        
        if (lchild <= n && a[lchild] > a[max])
            max = lchild;
        if (rchild <= n && a[rchild] > a[max])
            max = rchild;
        if (max != i) {
            swap(a[i], a[max]);
            HeapAdjust(a, max, n);    
        }
    }
}
 
void BuildHeap(int* a, int n)   
{
    for (int i = n / 2; i >= 1; i--){    
        HeapAdjust(a, i, n);
    }
}
 
void HeapSort(int* a, int n) 
{
    BuildHeap(a, n);
    for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    for (int i = n; i > 1; i--){
        swap(a[1], a[i]);
        HeapAdjust(a, 1, i - 1); 
        for (int j = 1; j <= n; j++){
                cout<< a[j]<<" ";
        }
        cout << endl;
    }
}
 
int main()
{
    int a[100], n;
    while (~scanf("%d", &n)){
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        HeapSort(a, n);
    }
    return 0;
}
