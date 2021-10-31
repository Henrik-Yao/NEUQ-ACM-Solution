#include <iostream>
#include <string>
using namespace std;
void movedish(int level,string from,string inter,string to){
    if(level==1){
        cout<<from<<"->"<<to<<endl;
    }
    else {
        movedish(level-1,from,to,inter);
        cout<<from<<"->"<<to<<endl;
        movedish(level-1,inter,from,to);
    }
}
int main(){
    int n;
    cin>>n;
    string from,inter,to;
    cin>>from>>inter>>to;
    movedish(n,from,inter,to);
    return 0;
}
