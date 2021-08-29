//84] 휴가(삼성 SW역량평가 기출문제 : DFS활용)
#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int n, res=-2147000000;
int a[20], ch[20];
vector<int> T, P;
void DFS(int L, int sum){
  if(L==n+1){ //상담을 한다
    if(sum>res) res=sum;
  }else{ //상담을 안한다
    if(L+T[L]<=n+1){
      DFS(L+T[L], sum+P[L]);
    }else{
      DFS(L+1, sum);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  freopen("input.txt", "rt", stdin);
  int t, p;
  scanf("%d", &n);
  T.push_back(0);
  P.push_back(0);

  for(int i=1; i<=n; i++){
    scanf("%d %d", &t, &p);
    T.push_back(t);
    P.push_back(p);
  }
  DFS(1,0); //날짜, 이익
  printf("%d", res);
  return 0;
}