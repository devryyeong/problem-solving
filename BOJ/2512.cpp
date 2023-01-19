// 2512] 예산
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  freopen("input.txt", "rt", stdin);
  
  int n, tmp, m, sum=0;
  vector<int> req; // 각 지방의 예산요청
  
	cin >> n; // 지방의 수

  // 요청들을 배열에 모두 입력받음
	for(int i=0; i<n; i++) {
    cin >> tmp;
    req.push_back(tmp);
    sum += tmp; // 예산요청들의 총합을 미리 구함
  }
  
  cin >> m; // 총 예산
  
  sort(req.begin(), req.end()); // 오름차순 정렬
  
  int start = 0;
  int end = req[n-1]; // 예산 요청중 최댓값
  int res;

  while(start <= end) {
    sum = 0;
    int mid = (start+end) / 2;

    // 이분 탐색을 진행하되 min(i번째 요청, 상한)을 다 더한 값이 m 이하일 경우 결과 업데이트
    for(int i=0; i<n; i++) {
      sum += min(req[i], mid);
    }
    if(sum <= m) {
      res = mid;
      start = mid+1;
    } else {
      end = mid-1;
    }
  }

  cout << res;
}