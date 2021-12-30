#include <bits/stdc++.h>
using namespace std;


void display(int a[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int a[], int x, int y) {
    int key  = a[x];
    a[x] = a[y];
    a[y] = key;
}

void Down(int a[], int i, int n) { // ��������Ǵ󶥶�
    int parent = i;                    // ���ڵ��±�
    int child  = 2 * i + 1;            // �ӽڵ��±�
    while (child < n) {
        if (child + 1 < n && a[child] < a[child + 1]) { // �ж��ӽڵ��Ǹ��󣬴���븸�ڵ�Ƚ�
            child++;
        }
        if (a[parent] < a[child]) { // �жϸ��ڵ��Ƿ�С���ӽڵ�
            swap(a, parent, child);     // �������ڵ���ӽڵ�
            parent = child;                 // �ӽڵ��±� ���� ���ڵ��±�
        }
        child = child * 2 + 1; // ���У��Ƚ�����ĸ��ڵ���ӽڵ�
    }
}

void BuildHeap(int a[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) { // �����ڶ��ſ�ʼ, �����󶥶ѣ�����������ϱȽ�
        Down(a, i, size);                 // �����еĲ����ϴ󶥶Ѷ���
    }
}

void HeapSort(int a[], int size) {
    BuildHeap(a, size); // ��ʼ����
    display(a, size);   // �鿴��ʼ�����
    for (int i = size - 1; i > 0; i--) 
    {
        swap(a, 0, i); // ��������͵� i ������
        Down(a, 0, i); // ���½����󶥶�
        display(a, size);
    }
}

int main() 
{
    int n,array[1001],i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>array[i];
    HeapSort(array,n);
    return 0;
}
