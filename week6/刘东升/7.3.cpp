#include <bits/stdc++.h>
using namespace std;
const int maxn=10001;
string a,b;
string S[maxn];
int main()
{
    getline(cin,a);//cin���ܶ���ո�getline���� 
    getline(cin,b);
    int f=0,ans=0;
    for(int i=0;i<b.length();i++)//��b����Ԥ������ת��ΪСд��ʽ�� 
    {
		if(b[i]>='A'&&b[i]<='Z')
        {
        	b[i]+=32;
    	}
	}	
    for(int i=0;i<a.length();i++)//��a���� 
    {
        if(a[i]<'A'||a[i]>'z'||(a[i]>'Z'&&a[i]<'a'))
        {
            if(f==1)
			{
				f=0;
			}
        }    
        else 
        {
            if(a[i]>='A'&&a[i]<='Z')
            {
                a[i]+=32;
        	}
            if(f==0)
            {
                f=1;
                ans++;
            }
            S[ans]+=a[i];//������ϱ�׼���ַ���
        }
    }
    int s=0;//��� 
    for(int i=0;i<=ans;i++)
    {
        if(S[i].find(b)!=-1)
        s++;
    }
    cout<<s;
    return 0;
}
