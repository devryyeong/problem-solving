//88] 미로의 최단거리 통로 (BFS 활용)
#include <iostream>
#include <algorithm>
#include <queue>
#define SIZE 7
using namespace std;

//상하좌우
int disX[4]={0,0,1,-1};
int disY[4]={1,-1,0,0};
int map[10][10], dist[10][10];
struct Loc{
  int x;
  int y;
  Loc(int a, int b){
    x=a;
    y=b;
  }
}; //pair대신 구조체
queue<Loc> Q; //Loc라는 구조체형 queue

int main() {
	freopen("input.txt","rt", stdin);
  
  //입력
  for(int i=1; i<=SIZE; i++){
    for(int j=1; j<=SIZE; j++){
      scanf("%d", &map[i][j]);
    }
  }

  //출발점(1,1)
  Q.push(Loc(1,1));
  map[1][1]=1;

  while(!Q.empty()){
    //Q의 front꺼내고
    Loc tmp=Q.front();
    Q.pop();

    //상하좌우 탐색
    for(int k=0; k<4; k++){
      //탐색해볼 임시 x,y좌표
      int xx=tmp.x+disX[k];
      int yy=tmp.y+disY[k];

      if(map[xx][yy]==0 && xx>=1 && xx<=SIZE && yy>=1 && yy<=SIZE){
        Q.push(Loc(xx, yy));
        map[xx][yy]=1;
        dist[xx][yy]=dist[tmp.x][tmp.y]+1;
      }
    }
  }

  printf("%d", dist[SIZE][SIZE]);
	return 0;
}