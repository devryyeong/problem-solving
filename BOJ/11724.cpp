//11724] 연결 요소의 개수
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, cnt;
int map[1001][1001], ch[1001]; //인접행렬

void DFS(int v){
  for(int i=1; i<=n; i++){
    ch[v]=1;
    //이어져있다면
    if(map[v][i]==1 && ch[i]==0){
      DFS(i);
    }
  }
}

int main(){
  freopen("input.txt","rt",stdin);
  int a, b;
  
  scanf("%d %d",&n, &m);
  for(int i=0; i<m; i++){
    scanf("%d %d", &a, &b);
    map[a][b]=1;
    map[b][a]=1;
  }
  
  for(int i=1; i<=n; i++){
    if(ch[i]==0){
      cnt++; //시작하면서 count
      DFS(i);
    }
  }

  printf("%d", cnt);
  return 0;
}
