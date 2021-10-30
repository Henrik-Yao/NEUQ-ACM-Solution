#include<bits/stdc++.h> 
using namespace std;
const int M=9;
char number[M];
int main()
{
    cin>>number;//输入排序的字符串 
    int n=strlen(number);//统计长度 
    sort(number,number+n);//进行初排续 
    do//防止只有一个 
    {
     for(int i=0;i<n;i++)
     {
        cout<<number[i];
	}		
        cout<<endl;
    }
	while( next_permutation(number,number+n));//调用next_permutation进行排序 
    return 0;
}

