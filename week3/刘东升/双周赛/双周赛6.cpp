#include<bits/stdc++.h> 
using namespace std;
const int M=9;
char number[M];
int main()
{
    cin>>number;//����������ַ��� 
    int n=strlen(number);//ͳ�Ƴ��� 
    sort(number,number+n);//���г����� 
    do//��ֹֻ��һ�� 
    {
     for(int i=0;i<n;i++)
     {
        cout<<number[i];
	}		
        cout<<endl;
    }
	while( next_permutation(number,number+n));//����next_permutation�������� 
    return 0;
}

