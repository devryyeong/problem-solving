//85] 수식만들기(삼성 SW역량평가 기출문제 : DFS활용)
#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int n, maxIdx=-2147000000, minIdx=2147000000;
int a[11], op[5];

void DFS(int L, int res){
  if(L==n){
    if(res>maxIdx) maxIdx=res;
    if(res<minIdx) minIdx=res;
  }else{
    if(op[0]>0){ // +
      op[0]--;
      DFS(L+1, res+a[L]);
      op[0]++;
    }
    if(op[1]>0){ // -
      op[1]--;
      DFS(L+1, res-a[L]);
      op[1]++;
    }
    if(op[2]>0){ // *
      op[2]--;
      DFS(L+1, res*a[L]);
      op[2]++;
    }
    if(op[3]>0){ // /
      op[3]--;
      DFS(L+1, res/a[L]);
      op[3]++;
    }
  }
}

int main(){
  freopen("input.txt", "rt", stdin);
  scanf("%d", &n);
  //피연산자 값
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  //연산자의 개수
  for(int i=0; i<4; i++){
    scanf("%d", &op[i]);
  }
  DFS(1, a[0]); //level, 첫번째 피연산자
  printf("%d\n%d", maxIdx, minIdx);
  return 0;

}