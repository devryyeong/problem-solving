//3040] 백설 공주와 일곱 난쟁이
#include<iostream>
using namespace std;

int main(){
  freopen("input.txt","rt",stdin);
  int sum=0, a, b;
  int arr[9];

  // 9개의 숫자를 입력받고 총합 구하기
  for(int i=0; i<9; i++){
    scanf("%d", &arr[i]);
    sum+=arr[i];
  }
  // 총합에서 100 빼기
  sum-=100;

  // 2명의 합이 sum과 같은지 확인 후 인덱스 저장해두기
  for(int i=0; i<9; i++){
    for(int j=i+1; j<9; j++){
      if(sum == arr[i]+arr[j]){
        a=i;
        b=j;
      }
    }
  }
  // a,b번째 제외하고 출력하기
  for(int k=0; k<9; k++){
    if(k!=a && k!=b){
      printf("%d\n", arr[k]);
    }
  }
  return 0;
}