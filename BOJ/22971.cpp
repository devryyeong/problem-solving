//22971] 증가하는 부분 수열의 개수
#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  vector <int> nums(n);
  vector <long long> res(n, 1);

  for(int i=0; i<n; i++){
    scanf("%d", &nums[i]);
  }

  for(int i=0; i<n; i++){
    for(int j=i; j>0; j--){
      if(nums[j-1]<nums[j]){
        res[i]+=res[j-1];
        res[i]=res[i]%998244353;
      }
    }
    printf("%lld ",res[i]);
  }
  
  return 0;
}
//특정 값의 이전 숫자들을 하나씩 훑으면서
//작다면 1로 초기화된 배열에 누적으로 더함.