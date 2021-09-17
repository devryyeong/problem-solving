//20206] 푸앙이가 길을 건너간 이유
#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int main(){
  freopen("input.txt", "rt", stdin);
  int a, b, c, ch1=0, ch2=0;
  double x1, x2, y1, y2;
  double sx1, sx2, sy1, sy2;
  scanf("%d %d %d", &a, &b, &c);
  scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);

  //직사각형의 네 점 위치 저장
  vector<pair<int,int> > v;
  v.push_back({x1, y1});
  v.push_back({x1, y2});
  v.push_back({x2, y1});
  v.push_back({x2, y2});

  for(int i=0; i<4; i++){
    if(v[i].first*a + v[i].second*b >= -c) ch1++;
    if(v[i].first*a + v[i].second*b <= -c) ch2++;
  }
  
  if(ch1==4 || ch2==4) printf("Lucky");
  else printf("Poor");
  return 0;
}

//점과 직선의 위치관계를 이용하는 것인데, 
//ax+by+c=0의 직선과 점 (p,q)가 있을 때, ap+bq>c인지, ap+bq<c인지가 직선의 위와 아래를 구분한다. 
//따라서 직사각형을 이루는 네 점이 모두 한쪽에 몰려있으면 직선이 직사각형을 지나지 않는다.