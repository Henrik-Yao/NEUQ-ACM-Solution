#include <iostream>
#include <vector>
using namespace std;
vector<int> city[100];
int flag=0,startcity,endcity;
int Gone[100],safe[100];
void Find(int n){
//	cout << "Here is " << n << endl;
    Gone[n]=1;
//    if(safe[n]==0) return;
     if(n==endcity){flag=1;return;}
    else if(city[n].empty()==true){return;}
    else{
        for(int i=0;i<city[n].size();i++){
//        		printf("Here is city %d , and I am going to city %d . \n",n,i);
           		if(Gone[city[n][i]]!=1) Find(city[n][i]);
        }
    }
}
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int safecitynu;
    int r1,r2;

    for(int abc=1;abc<=m;abc++){
        cin >> safecitynu;
        safe[safecitynu]=1;
    }
    for(int abc=1;abc<=k;abc++){
        cin >> r1 >> r2;
        city[r1].push_back(r2);
        city[r2].push_back(r1);
    }
/*    for(int i=0;i<5;i++){
    	printf("city %d has %d\n",i,city[i].size());
    	for(int j=0;j<city[i].size();j++) printf("     city %d connect city %d\n",i,city[i][j]);
	}*/
    cin >> startcity >> endcity;
    if(safe[endcity]==0){printf("The city %d is not safe!",endcity);return 0;}
    else{
        Find(startcity);
        if(flag==1) printf("The city %d can arrive safely!",endcity);
        else printf("The city %d can not arrive safely!",endcity);
    }
    return 0;
}