//2667] 단지번호붙이기 (BFS)
#include <iostream>
#include <algorithm>
#include <vector> 
#include <queue>
using namespace std;

int dX[4]={0,0,1,-1};
int dY[4]={1,-1,0,0};
int map[31][31];
int res, n, houseCnt;
struct Loc{
  int x;
  int y;
  Loc(int a, int b){
    x=a;
    y=b;
  }
};
queue<Loc> Q;
vector<int> house;

int main(){
  ios_base::sync_with_stdio(false);
  freopen("input.txt", "rt", stdin);
  cin>>n;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      char tmp;
      cin>>tmp;
      map[i][j]=tmp-48;
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      //집을 만나면
      if(map[i][j]==1){
        Q.push(Loc(i,j));
        map[i][j]=0;

        while(!Q.empty()){
          Loc tmp=Q.front();
          Q.pop();

          //상하좌우 탐색
          for(int k=0; k<4; k++){
            int xx=tmp.x+dX[k];
            int yy=tmp.y+dY[k];

            if(map[xx][yy]==0 || xx<0 || xx>n || yy<0 || yy>n) continue;
            if(map[xx][yy]==1){
              Q.push(Loc(xx, yy));
              map[xx][yy]=0;
              
            }
          }
          houseCnt++;
        }
        house.push_back(houseCnt);
        houseCnt=0;
        res++;
      }
    }
  }
  sort(house.begin(), house.end());
  cout<<res<<"\n";
  for(int i=0; i<res; i++){
    cout<<house[i]<<"\n";
  }
  return 0;
}
