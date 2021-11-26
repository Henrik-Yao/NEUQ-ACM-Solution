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
        	bool other=false;//这里面是不是还有别的[号
			int flo=1;//遇见的单独[号次数，遇见]时-1 
			int fir=0;//中途遇到的第一个另外[号的下标 
			int j=i+1;
			//先找到匹配的]号的位置 
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
