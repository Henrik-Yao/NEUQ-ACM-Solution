#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void F(char* a, int num, char* step, int* book,int l){
	int i,j;
	for(i=0; i<l; i++){
		if(book[i]==0){
			step[num] = a[i];
			book[i] = 1;
			if(num<l-1)
				F(a, num+1, step, book, l);
			else{
				for(j=0; j<l; j++){
					cout << step[j];
				}
				cout << endl;
			}
			book[i] = 0;
		}
		
		
	}
	
}

int main(){
	char a[10]={0},step[10]={0};
	int book[10]={0};
	int l,num=0;
	scanf("%s",a);
	l = strlen(a);
	sort(a,a+l);
	F(a, 0, step, book, l);
	
	return 0;
}
