#include<bits/stdc++.h>
using namespace std;
string prints(string partten);
int main()
{
    string partten;cin>>partten;cout<<prints(partten);
}
string prints(string partten)
{
    int i=0;
    while(partten[i]!='\0')
    {
        if(partten[i]=='[')//�����ж��Ƿ���Ҫ���д��� 
        {
        	bool other=false;//�������ǲ��ǻ��б��[��
			int flo=1;//[�ŵĸ���������]ʱ-1 //
			int first=0;//����[�ŵ��±� 
			int j=i;
            for(j=i+1; flo; j++)//���ҵ�ƥ���]�ŵ�λ�� 
            {
            	if(partten[j]=='[')
            	{
            		other=true;//������һ��[ 
            		flo+=1;
            		if(first==0)
					{
						first=j;
					}
				}
				if(partten[j]==']')
				{
					flo-=1;//������ 
				}
			}
			int begin=i+2;	//�ӵڶ�����ʼ�� 
			int times=partten[i+1]-'0';
			if((partten[i+2]>='0')&&partten[i+2]<='9')
			{
				times*=10;
				times+=partten[i+2]-'0';
				begin=i+3;
			}
			if(other)//������з��� 
			{
				string re, h_re, tr;
				for(int k=begin; k<first; k++){
				h_re+=partten[k];
				}
				for(int k=first; k<j-1; k++){
				re+=partten[k];
				}
				re=prints(re);//�ٴ��ظ��������� 
				re=h_re+re;
				for(int i=0; i<times; i++){
				tr+=re;}
				string up_part, dw_part;
				for(int k=0; k<i; k++){
				up_part+=partten[k];}
				for(int k=j; partten[k]!='\0'; k++){
				dw_part+=partten[k];}
				partten=up_part+tr+dw_part;
			}
			else
			{
				string re, tr;
				for(int k=begin; k<j-1; k++)
				{
					re+=partten[k];
				}
				for(int i=0; i<times; i++)	tr+=re;
				string up_part, dw_part;
				for(int k=0; k<i; k++)	up_part+=partten[k];
				
				for(int k=j; partten[k]!='\0'; k++)	dw_part+=partten[k];
				partten=up_part+tr+dw_part;
			}
        }
        i+=1;
    }
    return partten;
}
