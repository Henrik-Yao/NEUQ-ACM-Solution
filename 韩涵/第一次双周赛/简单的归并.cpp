/*#include<iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a[10001], b[10001];
        int a1, b1;//���鳤��
        int aa = 0, bb = 0;//�����±�
        cin >> a1;
        for (int i = 0; i < a1; i++) cin >> a[i];
        cin >> b1;
        for (int i = 0; i < b1; i++) cin >> b[i];
        while (aa < a1 && bb < b1) cout << (a[aa] < b[bb] ? a[aa++] : b[bb++]) << " ";//���������бȽ�
        //����һ��ȫ�������
        if (aa == a1) while (bb < b1) cout << b[bb++] << " ";
        if (bb == b1) while (aa < a1) cout << a[aa++] << " ";
        cout << endl;
    }
}*/
