#include<iostream>
#include<string>
using namespace std;

string realese(string it)
{
    int i=0;
    while(it[i]!='\0')
    {
        if(it[i]=='[')
        {
        	bool other=false;//�������ǲ��ǻ��б��[��
			int flo=1;//�����ĵ���[�Ŵ���������]ʱ-1 
			int fir=0;//��;�����ĵ�һ������[�ŵ��±� 
			int j=i+1;
			//���ҵ�ƥ���]�ŵ�λ�� 
            for(j=i+1; flo; j++)
            {
            	if(it[j]=='[')
            	{
            		other=true;
            		flo+=1;
            		if(fir==0)	fir=j;
				}
				if(it[j]==']')	flo-=1;
			}
			
			int begin=i+2;
			
			int times=it[i+1]-'0';
			if((it[i+2]>='0')&&it[i+2]<='9')
			{
				times*=10;
				times+=it[i+2]-'0';
				begin=i+3;
			}
			
			if(other)
			{
				string re, h_re, tr;
				for(int k=begin; k<fir; k++)	h_re+=it[k];
				for(int k=fir; k<j-1; k++)	re+=it[k];
				//cout<<"re="<<re<<endl;
				re=realese(re);
				re=h_re+re;
				//cout<<"re="<<re<<endl;
				for(int i=0; i<times; i++)	tr+=re;
				string up_part, dw_part;
				for(int k=0; k<i; k++)	up_part+=it[k];
				for(int k=j; it[k]!='\0'; k++)	dw_part+=it[k];
				it=up_part+tr+dw_part;
				//dw_part="\0";
				//for(int l=0; l<times; l++)
				//for(int k=i; it[k]!='\0'; k++)	dw_part+=it[k];
				//it=up_part+re+dw_part;
			}
			else
			{
				string re, tr;
				for(int k=begin; k<j-1; k++)
				{
					re+=it[k];
				}
				for(int i=0; i<times; i++)	tr+=re;
				string up_part, dw_part;
				for(int k=0; k<i; k++)	up_part+=it[k];
				
				for(int k=j; it[k]!='\0'; k++)	dw_part+=it[k];
				it=up_part+tr+dw_part;
			}
        }
        i+=1;
    }
    return it;
}

int main()
{
    string orgin;
    cin>>orgin;
    cout<<realese(orgin);
    return 0;
}
