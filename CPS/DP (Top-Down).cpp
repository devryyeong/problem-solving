//네트워크 선 자르기(DP: Top-Down)
#include <iostream>
using namespace std;

int dy[101];

int recursion(int n){
  //이전에 구했었던 값이면 그걸 그냥 가져오자
  if(dy[n]>0) return dy[n];
  if(n==1 || n==2) return n;
  else return dy[n]=recursion(n-1)+recursion(n-2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt","rt", stdin);
  int num;
  cin>>num;
  
  cout<<recursion(num);
  
	return 0;
}