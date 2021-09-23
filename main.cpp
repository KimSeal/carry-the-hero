#include <iostream>
#include <vector>
#include <queue>
#include "shortcut.h"
using namespace std;
//finish!

int main(){
	int n=7;//n은 방 세로사이즈
	int m=7;//m은 방 가로사이즈
	int meY=0;//개체 세로축
	int meX=0;//개체 가로축
	int juY=0;//주인공 세로축
	int juX=0;//주인공 가로축
	int catched=0;//주인공과 적 접촉 여부
	int input;
	int speed=1;
	int future[30];//몬스터의 이동경로(현재 플레이어의 바로 옆까지)
	vector<int> hello;//[1]부터 이동해야하는 방향을 나타냄.1,2,3,4 순으로 북동남서
	int hello1=0;
	int newmap[7][7]={{0,0,0,0,0,0,1},
				      {0,1,1,1,1,0,1},
				      {0,1,0,0,1,0,1},
				      {0,1,0,2,1,0,1},
				      {0,1,1,0,1,0,1},
				      {0,1,1,0,1,3,1},
				      {0,0,0,0,1,1,1}};
	
	while(catched==0){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<newmap[i][j];
				if(newmap[i][j]==2){ //플레이어 찾기
					juY=i;
					juX=j;
				}
				if(newmap[i][j]==3){ //몬스터 찾기
					meY=i;
					meX=j;
				}
			}
			cout<<"\n";
		}
		cout<<"input moving";
		cin>>input;//주인공 움직임
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
		for(int i=0;i<30;i++){
			future[i]=0;
		}
		bfs(7,7,meY,meX,juY,juX,newmap,3,future);
		for(int i=0;future[i]!=0;i++){
			cout<<future[i];
		}
		cout<<"\n";
		for(int i=0;i<speed;i++){                     //speed 만들어야됨 09.12 
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(newmap[i][j]==2){ //플레이어 찾기
						juY=i;
						juX=j;
					}
					if(newmap[i][j]==3){ //몬스터 찾기
						meY=i;
						meX=j;
					}
				}
			}
			hello1=future[i];
			if(hello1==0){
				break;
			}
			else if(hello1==1){
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
		}
	}
	return 0;
}
