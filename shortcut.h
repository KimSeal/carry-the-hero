#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//finish!

class Node{
	public:
	int row, col, dist;
	vector<int>row2;
	vector<int>col2;
	vector<int>move;
	void node_Make(int oldrow, int oldcol, int olddist){
		this->row=oldrow;
		this->col=oldcol;
		this->dist=olddist;
	}
	void node_vec(int row1, int col1){
		row2.push_back(row1);
		col2.push_back(col1);
	}
	void node_del(){
		row2.pop_back();
		col2.pop_back();
	}
	void node_move(int a){
		move.push_back(a);
	}
	void node_move_del(){
		move.pop_back();
	}
};

vector<int> bfs(int n,int m,int meY,int meX,int juY, int juX,int oldmap[7][7]){
	int n1=n;
	int m1=m;
	int curRow=0;
	int curCol=0;
	int curDist=0;
	vector<int>curRows;
	vector<int>curCols;
	
	vector<vector<int>> map;
	vector<int>map2;
	for(int i=0;i<n;i++){
		map.push_back(map2);
		for(int j=0;j<m;j++){
			map[i].push_back(oldmap[i][j]);
			//cout<<map[i][j]<<" ";
		}
		//cout<<"\n";
	}
	//외부 2차원 맵 복사
	
	queue<Node> q;
	Node mainnode, mainnode2;
	mainnode.node_Make(meY,meX,0);
	mainnode.node_vec(meY,meX);
	mainnode.node_move(7);
	q.push(mainnode);
	mainnode.row2.clear();
	mainnode.col2.clear();
	mainnode.move.clear();
	while(!q.empty()){
		mainnode.node_Make(q.front().row, q.front().col, q.front().dist);
		//cout << q.front().row << q.front().col << q.front().dist;
		mainnode.row2.clear();
		mainnode.col2.clear();
		mainnode.move.clear();
		mainnode2.row2.clear();
		mainnode2.col2.clear();
		mainnode2.move.clear();
		curRow = mainnode.row;
        curCol = mainnode.col;
        curDist = mainnode.dist;
		for(int i=0;i<=curDist;i++){
			mainnode2.node_vec(q.front().row2[i],q.front().col2[i]); 
			mainnode2.node_move(q.front().move[i]);
			//cout << "(" <<q.front().row2[i]<<"," << q.front().col2[i]<<") \n";
		}
		//cout<<"//";
		//for(int i=0;i<=curDist;i++){
	//		cout << "(" <<mainnode2.row2[i]<<"," << mainnode2.col2[i]<<") ";
	//	}
		//cout<<"\n";
		 if(curRow == juY && curCol == juX) {
            break;
        }
		q.pop();
		
        map[curRow][curCol] = 0;
        //cout <<"("<< curRow << " "<<curCol<<" "<<curDist<<")\n";
        // 목적지에 도착하면 루핑 종료
       
        // 위로 갈수 있으면
        if(curRow-1 >= 0 && map[curRow-1][curCol] == 0) {
			mainnode2.node_Make(curRow-1, curCol, curDist+1);
			mainnode2.node_vec(curRow-1,curCol);
			mainnode2.node_move(1);
            q.push(mainnode2);
			mainnode2.node_del();
			mainnode2.node_move_del();
        }
        // 아래로 갈수 있으면
        if(curRow+1 < n1 && map[curRow+1][curCol] == 0) {
            mainnode2.node_Make(curRow+1, curCol, curDist+1);
			mainnode2.node_vec(curRow+1,curCol);
			mainnode2.node_move(3);
			q.push(mainnode2);
			mainnode2.node_del();
			mainnode2.node_move_del();
        }
        // 왼쪽으로 갈수 있으면
        if(curCol-1 >= 0 && map[curRow][curCol-1] == 0) {
            mainnode2.node_Make(curRow, curCol-1, curDist+1);
			mainnode2.node_vec(curRow,curCol-1);
			mainnode2.node_move(4);
			q.push(mainnode2);
			mainnode2.node_del();
			mainnode2.node_move_del();
        }
    	// 오른쪽으로 갈수 있으면
        if(curCol+1 < m1 && map[curRow][curCol+1] == 0) {
            mainnode2.node_Make(curRow, curCol+1, curDist+1);
			mainnode2.node_vec(curRow,curCol+1);
			mainnode2.node_move(2);
        	q.push(mainnode2);
			mainnode2.node_del();
			mainnode2.node_move_del();
		}
	}
	cout <<" clear!";
	//만들어진 가로, 세로 배열 복사
	if(q.empty()){
		mainnode2.move.clear();
		mainnode2.move.push_back(0);
		mainnode2.move.push_back(5);
		return mainnode2.move;
	}
	for(int i=0;i<=curDist;i++){
		cout << "(" << mainnode2.row2[i]<<","<< mainnode2.col2[i]<<")";
	}
	 while(!q.empty()){
        q.pop();
    }
	mainnode2.move.push_back(5);
	return mainnode2.move;
}
