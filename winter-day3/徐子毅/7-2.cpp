#include <iostream>
#include <map>
using namespace std;
map<int,map<int,int>> tablet;
int main(){
    int point,line,needdelete;
    cin >> point >> line;
    for(int i=0;i<line;i++){
        int n1,n2,n3;
        cin >> n1 >> n2 >> n3;
        tablet[n1][n2]=n3;
    }
    cin >> needdelete;
    for(int i=0;i<needdelete;i++){
        int n1,n2;
        cin >> n1 >> n2;
        tablet[n1].erase(n2);
    }
    map<int,map<int,int>>::iterator Iter1;
    map<int,int>::iterator Iter2;
    for(Iter1=tablet.begin();Iter1!=tablet.end();Iter1++){
        bool first=true;
        bool have=false;
        for(Iter2=Iter1->second.begin();Iter2!=Iter1->second.end();Iter2++){
            if(Iter2->second!=0){
                if(first){
                    cout << Iter1->first << ":(" << Iter1->first << "," << Iter2->first << "," << Iter2->second << ")";
                    first=false;
                }else cout << "(" << Iter1->first << "," << Iter2->first << "," << Iter2->second << ")";
                have=true;
            }
        }
        if(have) cout << endl;
    }
    return 0;
}