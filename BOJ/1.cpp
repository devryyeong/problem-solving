//11403] 경로 찾기
#include<iostream>
using namespace std;
int n, m;
int map[101][101], ch[101]; //인접행렬

void DFS(int v){
  for(int i=0; i<n; i++){
    //ch[v]=1;
    //이어져있다면
    if(map[v][i]==1){
      map[v][i]=1;
      DFS(i);
    }
  }
}

int main(){
  freopen("input.txt","rt",stdin);
  int a, b;
  
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &map[i][j]);
    }
  }
  
  for(int i=0; i<n; i++){
    DFS(i);
  }

  //출력
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%d ", map[i][j]);
    }
    printf("\n");
  }
   return 0;
}
