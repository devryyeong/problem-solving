//알리바바와 40인의 도둑(DP: Top-Down)
#include <iostream>
#include <algorithm>
using namespace std;

int dp[21][21], arr[21][21];

int R(int x, int y){ //메모이제이션!!
  if(x==0 && y==0) return arr[0][0];
  else{
    if(y==0) return dp[x][y] = R(x-1, y)+arr[x][y]; //위쪽으로만 호출
    else if(x==0) return dp[x][y] = R(x, y-1)+arr[x][y]; //왼쪽으로만 호출
    else return dp[x][y] = min(R(x-1, y), R(x, y-1))+arr[x][y];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt","rt", stdin);
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>arr[i][j];
    }
  }
  
  cout<<R(n-1, n-1);
	return 0;
}