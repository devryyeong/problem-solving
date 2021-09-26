//1463] 1로 만들기
#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int arr[MAX];
int n;

void DP(int n){
  arr[1]=0;
  for(int i=2; i<=n; i++){
    arr[i]=arr[i-1]+1; //3번규칙
    if(i%2==0){
      arr[i]=min(arr[i], arr[i/2]+1); //2번규칙
    }
    if(i%3==0){
      arr[i]=min(arr[i], arr[i/3]+1); //1번규칙
    }
  }
}

int main(){
  scanf("%d", &n);
  DP(n);
  printf("%d", arr[n]);
  return 0;
}

//1) X가 3으로 나누어 떨어지면, 3으로 나눈다.
//2) X가 2로 나누어 떨어지면, 2로 나눈다.
//3) 1을 뺀다.

//Dynamic Programming
//bottom up
  //1을 뺴는 계산부터 시작해서 작은 계산을 통해 미리 arr[i]에 (최대)값을 메모이제이션을 합니다.
  //2로 나누어 떨어지는지 3으로 나누어 떨어지는 경우에 앞에 계산한 arr[i/2]와 arr[i/3]과  현재의 arr[i]와 비교를 하여
  //그 중 최소 값을 arr[i]에 다시 저장(메모이제이션)합니다.

