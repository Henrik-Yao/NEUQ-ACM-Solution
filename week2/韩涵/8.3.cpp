/*#include<iostream>
using namespace std;

//���ݲ���̳��ṩ�����ı�
template<typename T> //����ģ��
void merge_sort(T arr[], int len) {
    T* a = arr;
    T* b = new T[len];//�����ڴ�
    for (int seg = 1; seg < len; seg += seg) {//�����������䣨һ���ż�����
        for (int start = 0; start < len; start += seg + seg) {//������ʼλ��
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);//�������Ϊ����
            int k = low;//�±�
            int start1 = low, end1 = mid;//ǰ��
            int start2 = mid, end2 = high;//���
            while (start1 < end1 && start2 < end2)//��ʼ���򣬴�С����
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];//��������С�Ĳ���ǰ��
            //��ǰ/���ʣ������˳��д��
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        //�����������ָ�뻻Ϊa����һ����Ϊb
        T* temp = a;
        a = b;
        b = temp;
    }
    //���arr���滻Ϊ�źõ�˳�򣬲�ʹaָ����
    if (a != arr) {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    //���b���ڴ�
    delete[] b;
}

int main() {
    int a;
    int ans[99];
    cin >> a;
    for (int i = 0; i < a; i++) cin >> ans[i];
    merge_sort(ans, a);//�鲢����
    for (int i = 0; i < a; i++) cout << ans[i] << " ";
}*/