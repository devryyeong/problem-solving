//알리바바와 40인의 도둑(DP: Bottom-Up)
#include <iostream>
#include <algorithm>
using namespace std;

int dp[21][21];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  freopen("input.txt","rt", stdin);
  int n, res=0;
  int arr[21][21];
  cin>>n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>arr[i][j];
    }
  }

  dp[0][0]=arr[0][0];
  for(int i=0; i<n; i++){
    dp[0][i]=dp[0][i-1]+arr[0][i];
    dp[i][0]=dp[i-1][0]+arr[i][0];
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      dp[i][j]=min(dp[i-1][j], dp[i][j-1])+arr[i][j];
    }
  }
  cout<<dp[n-1][n-1];
	return 0;
}