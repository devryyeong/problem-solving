//10655] 마라톤1
//최대로 줄일 수 있는 체크포인트를 찾아야 함. 
//체크포인트 건너뛰고 전 후로 가는 거리가 작을수록 좋음. 
//건너뛰지 않은 전체 거리 합-체크포인트 건너뛰고 더해진 거리 최대값 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int dist(pair<int,int> a, pair<int,int> b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}

int main() {
	freopen("input.txt","rt", stdin);
	int n, x, y, res, skip=0, xx, yy;
	int total=0;
	
	scanf("%d", &n);
	vector<pair<int,int> > dis;
	
	for(int i=0; i<n; i++){
		scanf("%d %d", &x, &y);
		dis.push_back(pair<int,int>(x, y));
	}
	
	//건너뛰지 않은 전체 거리 합
	for(int i=0; i<n-1; i++){
		xx=abs(dis[i+1].first-dis[i].first);
		yy=abs(dis[i+1].second-dis[i].second);
		
		total+=xx+yy;	
	}
	
	//skip 인덱스 번호 제외하고 계산
	pair<int, int> pre, cur, next;
	
	for(int i=1; i<n-1; i++){
		pre=dis[i-1];
		cur=dis[i];
		next=dis[i+1];
		
		int df=dist(pre,cur) + dist(cur, next);
		int straight=dist(pre, next); //건너뛰었을 때 

		//최대로 줄일 수 있는 체크포인트
		skip=max(skip, df-straight);
		
		//건너뛰지 않은 전체 거리 합-체크포인트 건너뛰고 더해진 거리 최대값 
		res=total-skip;
	}
	
	printf("%d", res);
	return 0;
}
