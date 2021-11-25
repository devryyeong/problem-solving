//11068] 회문인 수
#include<iostream>
#include <algorithm>
using namespace std;

int main(){
  freopen("input.txt","rt",stdin);
  int t, n, num;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &num);
    string original, reversed;
      
    for(int b=2; b<=64; b++){
      //입력받은 num을 n에 옮겨서 계산
      int n=num;
      original=""; reversed="";

      //b진법 변환 
      while(n!=0){
        original.push_back(n%b);
        n/=b;
      }

      //회문인 수를 판별하기 위해 original을 거꾸로 reversed에 넣음
      for(int i=original.length()-1; i>=0; i--){
        reversed+=original[i];
      }

      //같다면 회문인 수
      if(original==reversed){
        printf("1\n"); break;
      }
    }
    
    if(original!=reversed){
        printf("0\n");
      }
  }
  return 0;
}
