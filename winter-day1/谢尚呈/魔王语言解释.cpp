#include<iostream>
#include<cstring>
using namespace std;
string org;//ԭ��δ�����ַ���
string fir;//ȥС���ź���ַ���
string sec;//ȥB֮����ַ���

void fir_step(void)
{
	for(int i=0; org[i]!='#'; i++)
	if(org[i]!='(')	fir+=org[i];
	else
	{
		int j=i+1;
		while(org[j]!=')')	j++;
		int k=j;
		j-=1;
		for(j; j>i+1; j--)
		{
			fir+=org[i+1];
			fir+=org[j];
		}
		fir+=org[i+1];
		i=k;
	}
	return;
}
void sec_step(void)
{
	for(int i=0; fir[i]!='\0'; i++)
	if(fir[i]=='B')	sec+="tAdA";
	else	sec+=fir[i];
	return;
}
 
int main()
{
	getline(cin, org);
	fir_step();
	sec_step();
	for(int i=0; sec[i]!='\0'; i++)
	if(sec[i]=='A')	cout<<"sae";
	else	cout<<sec[i];
	return 0;
}
