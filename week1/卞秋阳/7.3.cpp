#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x1,y1,x2,y2,x3,y3;double d,k,h,a,b,c;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	if(x1==x2){
		if(y3>=min(y1,y2)&&y3<=max(y1,y2)) {
		d=(x3-x1)*(x3-x1);d=sqrt(d);
		}
		
		else if(y3<min(y1,y2)){
			d=(min(y1,y2)-y3)*(min(y1,y2)-y3)+(x1-x3)*(x1-x3);
			d=sqrt(d);}
		else if(y3>max(y1,y2)){
			d=(max(y1,y2)-y3)*(max(y1,y2)-y3)+(x1-x3)*(x1-x3);
			d=sqrt(d);}
	}
	
	if(x1!=x2){
		k=(y1-y2)/(x1-x2);
		if(k==(y1-y3)/(x1-x3)&&x3>min(x1,x2)&&x3<min(x1,x2)){d=0;}
		else { }
	}
	
	
	
	
	
	
}
