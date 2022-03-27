#include <bits/stdc++.h>
using namespace std;
struct student{
    int grade;
    string name;
};
int main(){
    int n;
    cin>>n;
    student std[22];
    for(int i=0;i<n;i++){
        cin>>std[i].name;
        cin>>std[i].grade;
    }
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++){
            if(std[j].grade<std[j+1].grade)
                swap(std[j],std[j+1]);
            else if(std[j].grade==std[j+1].grade)
            {
                if(std[j].name>std[j+1].name)
                    swap(std[j],std[j+1]);
            }
        }
      for(int i=0;i<n;i++){
          cout<<std[i].name<<" "<<std[i].grade<<endl;
      }
    return 0;
}
