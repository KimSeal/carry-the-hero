#include <iostream>
#include <vector>
#include <queue>
#include "shortcut.h"
using namespace std;
//finish!
struct character{
	int Y;
	int X;
	int hp;
};
struct monster{
	int Y;
	int X;
	int movement[30];
};
int main(){
	character player;
	player.hp=5;
	monster mon1;
	int n=7;//n은 방 세로사이즈
	int m=7;//m은 방 가로사이즈
	mon1.Y=0;//개체 세로축
	mon1.X=0;//개체 가로축
	player.Y=0;//주인공 세로축
	player.X=0;//주인공 가로축
	int catched=0;//주인공과 적 접촉 여부
	int input;
	int speed=1;
	//int future[30];//몬스터의 이동경로(현재 플레이어의 바로 옆까지)
	vector<int> hello;//[1]부터 이동해야하는 방향을 나타냄.1,2,3,4 순으로 북동남서
	int hello1=0;
	int newmap[7][7]={{1,1,1,1,1,1,1},
				      {1,2,0,0,0,0,1},
				      {1,0,1,0,1,0,1},
				      {1,0,0,0,0,0,1},
				      {1,0,1,0,1,0,1},
				      {1,0,0,0,0,3,1},
				      {1,1,1,1,1,1,1}};
	
	while(player.hp>0){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<newmap[i][j];
				if(newmap[i][j]==2){ //플레이어 찾기
					player.Y=i;
					player.X=j;
				}
				if(newmap[i][j]==3){ //몬스터 찾기
					mon1.Y=i;
					mon1.X=j;
				}
			}
			cout<<"\n";
		}
		cout<<"input moving";
		cin>>input;//주인공 움직임
		if(input==1){
			if((player.Y-1)>=0&&newmap[player.Y-1][player.X]==0){
				newmap[player.Y][player.X]=0;
				player.Y-=1;
				newmap[player.Y][player.X]=2;
				cout<<"go up\n";
			}
		}
		else if(input==2){
			if((player.X+1)<m && newmap[player.Y][player.X+1]==0){
				newmap[player.Y][player.X]=0;
				player.X+=1;
				newmap[player.Y][player.X]=2;
				cout<<"go right\n";
			}
		}
		else if(input==3){
			if((player.Y+1)<n&&newmap[player.Y+1][player.X]==0){
				newmap[player.Y][player.X]=0;
				player.Y+=1;
				newmap[player.Y][player.X]=2;
				cout<<"go down\n";
			}
		}
		else if(input==4){
			if((player.X-1)>=0 && newmap[player.Y][player.X-1]==0){
				newmap[player.Y][player.X]=0;
				player.X-=1;
				newmap[player.Y][player.X]=2;
				cout<<"go left\n";
			}
		}
		for(int i=0;i<30;i++){
			mon1.movement[i]=0;
		}
		bfs(7,7,mon1.Y,mon1.X,player.Y,player.X,newmap,3,mon1.movement);
		for(int i=0;mon1.movement[i]!=0;i++){
			cout<<mon1.movement[i];
		}
		cout<<"\n";
		for(int i=0;i<1/*speed*/;i++){                     //speed 만들어야됨 09.12 
			for(int k=0;k<n;k++){
				for(int j=0;j<n;j++){
					if(newmap[k][j]==2){ //플레이어 찾기
						player.Y=k;
						player.X=j;
					}
					if(newmap[k][j]==3){ //몬스터 찾기
						mon1.Y=k;
						mon1.X=j;
					}
				}
			}
			if(catched==1){
				catched=0;
				player.hp-=1;
			}
			else if(mon1.movement[i]==0){
				break;
			}
			else if(mon1.movement[i]==1){
				if((mon1.Y-1)>=0&&newmap[mon1.Y-1][mon1.X]==0){
					newmap[mon1.Y][mon1.X]=0;
					mon1.Y-=1;
					newmap[mon1.Y][mon1.X]=3;
					cout<<"go up\n";
				}
			}
			else if(mon1.movement[i]==2){
				if((mon1.X+1)<m && newmap[mon1.Y][mon1.X+1]==0){
					newmap[mon1.Y][mon1.X]=0;
					mon1.X+=1;
					newmap[mon1.Y][mon1.X]=3;
					cout<<"go right\n";
				}
			}
			else if(mon1.movement[i]==3){
				if((mon1.Y+1)<n&&newmap[mon1.Y+1][mon1.X]==0){
					newmap[mon1.Y][mon1.X]=0;
					mon1.Y+=1;
					newmap[mon1.Y][mon1.X]=3;
					cout<<"go down\n";
				}
			}
			else if(mon1.movement[i]==4){
				if((mon1.X-1)>=0 && newmap[mon1.Y][mon1.X-1]==0){
					newmap[mon1.Y][mon1.X]=0;
					mon1.X-=1;
					newmap[mon1.Y][mon1.X]=3;
					cout<<"go left\n";
				}
			}
		}
		if(mon1.Y == player.Y){
			if(mon1.X == player.X-1 || mon1.X == player.X+1){
				cout<<"monster attacked!\n";
				catched=1;
			}
		}
		if(mon1.X == player.X) {
            if(mon1.Y==player.Y-1||mon1.Y==player.Y+1){
				cout<<"monster attacked!\n";
				catched=1;
			}
        }
	}
	cout<<"you dead! game over";
	return 0;
}
