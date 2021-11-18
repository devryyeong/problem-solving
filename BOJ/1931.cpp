//1931] 회의실 배정
/* <그리디 알고리즘>
[1]회의 시간이 끝나는 시간을 기준으로 정렬하고,
[2]현재 기준에서 가능한 회의 중 가장 빨리 끝나는 회의를 선택
*/
#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

//회의 정렬을 위한 구조체
struct Conf{
  int x,y;
  Conf(int a, int b){
    x=a;
    y=b;
  }
  bool operator<(const Conf &b)const{
    if(y!=b.y) return y<b.y;
    if(x!=b.x) return x<b.x;
  }
};

int main(){
  freopen("input.txt","rt",stdin);
  int n, start, end, cnt=0, cur=0;
  vector<Conf> v;

  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d %d", &start, &end);
    v.push_back(Conf(start, end));
  }

  sort(v.begin(), v.end());

  /* 정렬 확인을 위한 출력
  for(const auto& pos: v){
		cout<<pos.x<<" "<<pos.y<<endl;
	}
	cout<<"ㅡㅡㅡ\n";
  */

  for(int i=0; i<n; i++){
    if(i==0){
      cnt++;
      cur=v[i].y;
      //printf("*%d\n", cur);
    }else{
      if(v[i].x>=cur){
        cnt++;
        cur=v[i].y;
        //printf("%d\n", cur);
      }
    }
  }
  
  printf("%d", cnt);
  return 0;
}
