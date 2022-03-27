#include <iostream>
#include <map>
using namespace std;
int main(){
    int point,line;
    map<int,map<int,int>> tablet;
    cin >> point >> line;
    for(int i=0;i<line;i++){
        int n1,n2,n3;
        cin >> n1 >> n2 >> n3;
        if(n1==n2) continue;
        tablet[n1][n2]=n3;
    }
    map<int,map<int,int>>::iterator Iter1;
    map<int,int>::iterator Iter2;
    for(Iter1=tablet.begin();Iter1!=tablet.end();Iter1++){
        string str="";
        for(Iter2=Iter1->second.begin();Iter2!=Iter1->second.end();Iter2++){
            str+="("+to_string(Iter1->first)+","+to_string(Iter2->first)+","+to_string(Iter2->second)+")";
        }
        cout <<Iter1->first<< ":" << str <<endl;
    }
    return 0;
}