//1072] 게임 (Binary Search)
#include<iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
  freopen("input.txt","rt",stdin);
  long long x, y, z, num1, num2;
  scanf("%lld %lld", &x, &y);
    
  z = 100*y/x;

  if(z>=99){
    printf("-1");
  }else{
    num1 = 100*y - x*z - x; //분자
    num2 = z-99; //분모

    //printf("%lld, %lld\n", num1,num2);
    //printf("%f\n", (double)num1/num2);

    //게임을 최소 몇 판 더 해야하는지
    int ans=ceil((double)num1/num2);
    printf("%d", ans);
  }
  return 0;
}