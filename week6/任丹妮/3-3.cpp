#include <bits/stdc++.h>
#define maxn 1001
using namespace  std;
void str_bin(char *str1,char *str2,int len1,int len2){
	char str[maxn];
	int i=0,j=0,k=0;
	while(i<len1&&j<len2){
		if(str1[i]<str2[j])
			{
				str[k]=str1[i];
				k++;
				i++;
			}
		else {
			str[k]=str2[j];
			k++;
			j++;
		}
	}
	while(i<len1){
		str[k]=str1[i];
		k++;
		i++;
	}
	while(j<len2){
		str[k]=str2[j];
		k++;
		j++;
	}
	for(int i=0;i<k;i++)
	cout<<str[i];
	cout<<endl;
}
int main()
{
	char str1[maxn],str2[maxn];
	cin>>str1>>str2;
	int len1=strlen(str1);
	int len2=strlen(str2);
	str_bin(str1,str2,len1,len2);
	printf("姓名：任丹妮 学号：202010014\n");
	return 0;
}
