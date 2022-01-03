//2865] 나는 위대한 슈퍼스타K
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

double arr[101];
int main(){
  //freopen("input.txt","rt",stdin);
  int n, m, k, pnum;
  double ability, ans=0;

  scanf("%d %d %d", &n, &m, &k);

  for(int i=1; i<=m; i++){
    for(int j=0; j<n; j++){
      scanf("%d %lf", &pnum, &ability);
      if(arr[pnum]<ability) arr[pnum]=ability;
    }
  }
  sort(arr+1, arr+n+1);
  for(int i=n; i>n-k;i--){
    ans+=arr[i];
  }

  printf("%.1lf",ans);
  return 0;
}