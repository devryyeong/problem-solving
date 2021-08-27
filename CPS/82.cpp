//82]순열 구하기
//Brute force를 이용한 완전탐색
//DFS, 체크배열, stack구조 생각하자
#include <iostream>
#include <algorithm>
using namespace std;

int n, r, cnt=0;
int a[20], res[20], ch[20];

void DFS(int L){
  if(L==r){
    for(int i=0; i<L; i++){
      printf("%d ", res[i]);
    }
    puts("");
    cnt++;
  }else{
    for(int i=1; i<=n; i++){
      if(ch[i]==0){
        res[L]=a[i];
        ch[i]=1;
        DFS(L+1);
        ch[i]=0;
      }
    }
  }
}

int main(){
  freopen("input.txt", "rt", stdin);
  scanf("%d %d", &n, &r);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }

  DFS(0);
  printf("%d", cnt);
  return 0;
}