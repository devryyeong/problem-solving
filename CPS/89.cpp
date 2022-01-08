//89] 토마토 (BFS)
#include <iostream>
#include <algorithm>
#include <vector> 
#include <queue>
using namespace std;

int dX[4]={0,0,1,-1};
int dY[4]={1,-1,0,0};
int map[1001][1001];
int day[1001][1001]; //걸리는 날짜
int m, n, res=-2147000000, mapStatus=1;

struct Loc{
  int x, y;
  Loc(int a, int b){
    x=a;
    y=b;
  }
};
queue<Loc> Q;

int main(){
  ios_base::sync_with_stdio(false);
  freopen("input.txt", "rt", stdin);
  cin>>m>>n;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      cin>>map[i][j];
      //익은 토마토를 만나면
      if(map[i][j]==1){
        Q.push(Loc(i,j));
      }
    }
  }


  while(!Q.empty()){
    Loc tmp=Q.front();
    Q.pop();

    //상하좌우 탐색
    for(int k=0; k<4; k++){
      int xx=tmp.x+dX[k];
      int yy=tmp.y+dY[k];
      
      if(xx<=0 || xx>n || yy<=0 || yy>m) continue;
      //안익은 토마토일때만
      if(map[xx][yy]==0){
        Q.push(Loc(xx, yy));
        map[xx][yy]=1;
        //퍼져나가는 날짜 계산: 현재 지점까지의 날짜+1
        day[xx][yy]=day[tmp.x][tmp.y]+1;
        
      }
    }
  }
  
  
  //map이 모두 1이 되었는지 검사
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(map[i][j]==0) mapStatus=0;
    }
  }
  //map이 모두 1이거나(토마토가 다 익었거나) 
  //0이면(저장될 때부터 모든 토마토가 익어있는 상태면) day배열의 최댓값 출력
  if(mapStatus==1){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        if(res<day[i][j]) res=day[i][j];
      }
    }
    cout<<res<<endl;
  }
  //map에 0이 남아있으면(토마토가 모두 익지는 못하는 상황)
  else cout<<"-1"<<endl;
  return 0;
}
