#include <iostream>
#include <vector>
#include <queue>
#include "shortcut.h"
using namespace std;
//finish!

int main(){
	int n=7;//n은 방 세로사이즈
	int m=7;//m은 방 가로사이즈
	int meY=4;//개체 세로축
	int meX=4;//개체 가로축
	int juY=2;//주인공 세로축
	int juX=2;//주인공 가로축
	int catched=0;//주인공과 적 접촉 여부
	int input;
	int speed=1;
	vector<int> hello;//[1]부터 이동해야하는 방향을 나타냄.1,2,3,4 순으로 북동남서
	int hello1=0;
	int hello2=0;
	int newmap[7][7]={{0,0,0,0,0,0,0},
				      {0,0,0,0,0,0,0},
				      {0,0,2,0,0,0,0},
				      {0,0,0,0,0,0,0},
				      {0,0,0,0,3,0,0},
				      {0,0,0,0,0,0,0},
				      {0,0,0,0,0,0,0}};
	while(catched==0){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<newmap[i][j];
			}
			cout<<"\n";
		}
		cout<<"input moving";
		cin>>input;//주인공 움직임
		if(input==5){
			break;
		}
		if(input==1){
			if((juY-1)>=0&&newmap[juY-1][juX]==0){
				newmap[juY][juX]=0;
				juY-=1;
				newmap[juY][juX]=2;
				cout<<"go up\n";
			}
		}
		else if(input==2){
			if((juX+1)<m && newmap[juY][juX+1]==0){
				newmap[juY][juX]=0;
				juX+=1;
				newmap[juY][juX]=2;
				cout<<"go right\n";
			}
		}
		else if(input==3){
			if((juY+1)<n&&newmap[juY+1][juX]==0){
				newmap[juY][juX]=0;
				juY+=1;
				newmap[juY][juX]=2;
				cout<<"go down\n";
			}
		}
		else if(input==4){
			if((juX-1)>=0 && newmap[juY][juX-1]==0){
				newmap[juY][juX]=0;
				juX-=1;
				newmap[juY][juX]=2;
				cout<<"go left\n";
			}
		}
		cout<<"juY:"<<juY<<"juX:"<<juX<<"\n";

		hello2= bfs(7,7,meY,meX,juY,juX,newmap,3);
		//hello2=test(1);
		//cout<<hello2;
		//return 0;
		cout<<"errorcheck2";
		
		for(int i=0;i<speed;i++){                     //speed 만들어야됨 09.12 
			hello1=hello2%5;
			cout<<hello1;
			if(hello1==0){
				break;
			}
			if(hello1==1){
				if((meY-1)>=0&&newmap[meY-1][meX]==0){
					newmap[meY][meX]=0;
					meY-=1;
					newmap[meY][meX]=3;
					cout<<"go up\n";
				}
			}
			else if(hello1==2){
				if((meX+1)<m && newmap[meY][meX+1]==0){
					newmap[meY][meX]=0;
					meX+=1;
					newmap[meY][meX]=3;
					cout<<"go right\n";
				}
			}
			else if(hello1==3){
				if((meY+1)<n&&newmap[meY+1][meX]==0){
					newmap[meY][meX]=0;
					meY+=1;
					newmap[meY][meX]=3;
					cout<<"go down\n";
				}
			}
			else if(hello1==4){
				if((meX-1)>=0 && newmap[meY][meX-1]==0){
					newmap[meY][meX]=0;
					meX-=1;
					newmap[meY][meX]=3;
					cout<<"go left\n";
				}
			}
			hello2=hello2/5;
		}
		
		//hello.clear();
	}
	//hello=bfs(7,7,3,3,5,5,newmap,3);
	for(int i=0;hello[i]!=5;i++){
		cout << "(" << hello[i]<<")";
	}
	return 0;
}
