//1789] 수들의 합
#include <iostream>

int main(){
  //freopen("iput.txt","rt",stdin);
  long long s, sum=0, cnt=0;
  scanf("%lld", &s); //200
  for(int i=1; sum<=s; i++){
    sum+=i;
    cnt++;
  }
  printf("%lld", cnt-1);
  return 0;
}

