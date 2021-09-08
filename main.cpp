#include <iostream>
#include <vector>
#include <queue>
#include "shortcut.h"
using namespace std;
//finish!

int main(){
	int n=7;//n은 방 세로사이즈
	int m=7;//m은 방 가로사이즈
	int meY=5;//개체 세로축
	int meX=5;//개체 가로축
	int juY=1;//주인공 세로축
	int juX=1;//주인공 가로축
	int catched=0;//주인공과 적 접촉 여부
	int input;
	int speed=1;
	vector<int> hello;//[1]부터 이동해야하는 방향을 나타냄.1,2,3,4 순으로 북동남서
	int newmap[7][7]={{0,0,0,0,0,0,0},
				      {0,1,1,1,1,1,0},
				      {0,1,0,0,0,1,0},
				      {0,1,0,1,0,1,0},
				      {0,1,0,1,0,1,0},
				      {0,1,1,1,0,1,0},
				      {0,0,0,0,0,0,0}};
	/*while(catched==0){
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
		cout<<"errorcheck";
		/*hello=bfs(7,7,meY,meX,juY,juX,newmap);
		cout<<"errorcheck2"<<hello[0];
		for(int i=0;i<speed;i++){
			if(hello[i]==5){
				break;
			}
			if(hello[i]==1){
				if((meY-1)>=0&&newmap[meY-1][meX]==0){
					newmap[meY][meX]=0;
					meY-=1;
					newmap[meY][meX]=3;
					cout<<"go up\n";
				}
			}
			else if(hello[i]==2){
				if((meX+1)<m && newmap[meY][meX+1]==0){
					newmap[meY][meX]=0;
					meX+=1;
					newmap[meY][meX]=3;
					cout<<"go right\n";
				}
			}
			else if(hello[i]==3){
				if((meY+1)<n&&newmap[meY+1][meX]==0){
					newmap[meY][meX]=0;
					meY+=1;
					newmap[meY][meX]=3;
					cout<<"go down\n";
				}
			}
			else if(hello[i]==4){
				if((meX-1)>=0 && newmap[meY][meX-1]==0){
					newmap[meY][meX]=0;
					meX-=1;
					newmap[meY][meX]=3;
					cout<<"go left\n";
				}
			}
		}
	}*/
	hello=bfs(7,7,3,3,5,5,newmap);
	for(int i=0;hello[i]!=5;i++){
		cout << "(" << hello[i]<<")";
	}
	return 0;
}
