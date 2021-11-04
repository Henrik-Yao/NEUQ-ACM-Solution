#include<iostream>
using namespace std;

int side_hang, side_lie;

enum returner{
	die,
	accept,
	error
};

int map[50][20];//周围有雷的个数，如果是雷就是-1 
bool o_map[50][20];

returner click(int hang, int lie)
{
	if(o_map[hang][lie])	return error;
	if(map[hang][lie]==-1)	return die;
	
	o_map[hang][lie]=true;
	for(int b_h=hang-1; b_h<=hang+1; b_h++)
	{
		if(b_h<0)	continue;
		if(b_h>=side_hang)	break;
		
		for(int b_l=lie-1; b_l<=lie+1; b_l++)
		{
			if(b_l<0)	continue;
			if(b_l>=side_lie)	break;
			
			if(b_h==hang)
			if(b_l==lie)	continue;
			
			if(map[b_h][b_l]==-1)	map[hang][lie]+=1;
		}
	}
	if(map[hang][lie]!=0)	return accept;
	for(int b_h=hang-1; b_h<=hang+1; b_h++)
	{
		if(b_h<0)	continue;
		if(b_h>=side_hang)	break;
		
		for(int b_l=lie-1; b_l<=lie+1; b_l++)
		{
			if(b_l<0)	continue;
			if(b_l>=side_lie)	break;
			
			if(b_h==hang)
			if(b_l==lie)	continue;
			
			if(map[b_h][b_l]!=-1)
			if(!o_map[b_h][b_l])	click(b_h, b_l);
		}
	}
	return accept;
}

void draw(int time)
{
	for(int i=0; i<side_hang; i++)
	{
		for(int j=0; j<side_lie; j++)
		{
			if(o_map[i][j])	cout<<map[i][j]<<" ";
			else	cout<<"-1 ";
		}
		cout<<endl;
	}
	return;
}

bool check_win(int num_of_lei)
{
	int didnt_see=0;
	for(int i=0; i<side_hang; i++)
	for(int j=0; j<side_lie; j++)
	if(o_map[i][j]);
	else	didnt_see+=1;
	if(didnt_see==num_of_lei)	return true;
	else	return false;
	
}

int main()
{
	cin>>side_hang>>side_lie;
	int k, l;
	int time=0;
	bool lost=false;
	cin>>k>>l;
	for(int i=0; i<k; i++)
	{
		int a, b;
		cin>>a>>b;
		map[a][b]=-1;
	}
	int *a, *b;
	a=new int[l];
	b=new int[l];
	for(int i=0; i<l; i++)	cin>>a[i]>>b[i];
    int acc=0;
	for(int i=0; i<l; i++)
	{
		//if(lost)	continue;
		returner it=click(a[i], b[i]);
		if(it==error)	continue;
		else if(it==die)
		{
			cout<<"You lose"<<endl;
			lost=true;
		}
		else if(it==accept)
		{
			time++;
            //if(acc) cout<<endl;
            //else    acc++;
			draw(time);
			if(check_win(k))	
            {
                cout<<"You win"<<endl;
                lost=true;
            }
		}
		if(lost)	continue;
		else	cout<<endl;
	}
	delete a;
	delete b;
	return 0;
}
