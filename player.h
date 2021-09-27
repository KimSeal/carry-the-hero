#include <iostream>
using namespace std;

struct character{
	int Y;
	int X;
	int hp;
};

void playerMove(character * player, int (*newmap)[7]){
	int m=7;
	int n=7;
	int input;
	cin >> input;
	if(input==1){
		if((player->Y-1)>=0&&newmap[player->Y-1][player->X]==0){
			newmap[player->Y][player->X]=0;
			player->Y-=1;
			newmap[player->Y][player->X]=2;
			cout<<"go up\n";
		}
	}
	else if(input==2){
		if((player->X+1)<m && newmap[player->Y][player->X+1]==0){
			newmap[player->Y][player->X]=0;
			player->X+=1;
			newmap[player->Y][player->X]=2;
			cout<<"go right\n";
		}
	}
	else if(input==3){
		if((player->Y+1)<n&&newmap[player->Y+1][player->X]==0){
			newmap[player->Y][player->X]=0;
			player->Y+=1;
			newmap[player->Y][player->X]=2;
			cout<<"go down\n";
		}
	}
	else if(input==4){
		if((player->X-1)>=0 && newmap[player->Y][player->X-1]==0){
			newmap[player->Y][player->X]=0;
			player->X-=1;
			newmap[player->Y][player->X]=2;
			cout<<"go left\n";
		}
	}
}
