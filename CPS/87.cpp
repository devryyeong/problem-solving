//87] 섬나라 아일랜드 (BFS 활용)
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//상하좌우+왼위,오위,왼아,오아 대각선
int disX[8]={0,0,1,-1,-1,1,-1,1,};
int disY[8]={1,-1,0,0,1,1,-1,-1};
int map[21][21];
int n, res;
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
	scanf("%d", &n);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      scanf("%d", &map[i][j]);
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      //섬(1)을 만나면
      if(map[i][j]==1){
        Q.push(Loc(i,j));
        map[i][j]=0;

        while(!Q.empty()){
          //Q의 front꺼내고
          Loc tmp=Q.front();
          Q.pop();

          //상하좌우,대각선 8곳 탐색
          for(int k=0; k<8; k++){
            //탐색해볼 임시 x,y좌표
            int xx=tmp.x+disX[k];
            int yy=tmp.y+disY[k];

            if(map[xx][yy]==1){
              Q.push(Loc(xx, yy));
              map[xx][yy]=0;
            }
          }
        }

        res++;
      }
    }
  }

  printf("%d", res);
	return 0;
}