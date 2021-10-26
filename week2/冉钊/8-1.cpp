#include<iostream>
using namespace std;
int dfs(int n,char from,char temp,char to){

	if(n==1){
        printf("%c->%c\n",from,to);
	}
    else{
         dfs(n-1,from,to,temp);
		 printf("%c->%c\n",from,to);
		 dfs(n-1,temp,from,to);
	}


}
int main(){
    int n;
	char from,temp,to;
	cin>>n>>from>>temp>>to;
	dfs(n,from,temp,to);

	return 0;
}