#include <bits/stdc++.h>
using namespace std;


void swap(int a[], int x, int y);
void HeapSort(int a[], int size);
void Build(int a[], int size);
void D(int a[], int i, int n);
 
int main() 
{
    int n,a[1001],i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    HeapSort(a,n);
    return 0;
}

void swap(int a[], int x, int y){
    int key  = a[x];
    a[x] = a[y];
    a[y] = key;
}

void HeapSort(int a[], int size){
    Build(a, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = size - 1; i > 0; i--) {
        swap(a, 0, i); 
        D(a, 0, i);
        for (int i = 0; i < size; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

void Build(int a[], int size){
    for (int i = size / 2 - 1; i >= 0; i--) { 
        D(a, i, size);                 
    }
}

void D(int a[], int i, int n){ 
    int par = i;
    int child  = 2 * i + 1;            
    while (child < n) {
        if (child + 1 < n && a[child] < a[child + 1]) { 
            child++;
        }
        if (a[par] < a[child]) { 
            swap(a, par, child); 
            par = child;                 
        }
        child = child * 2 + 1; ;
    }
}
