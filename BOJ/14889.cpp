//14889] 스타트와 링크 
//start팀에 넣거나, link팀에 넣거나. ->재귀  
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ability[21][21];
int startSum, linkSum;
int start_first, start_second, link_first, link_second;
int n, res=2147000000;
vector<int> start, link;

void DFS(int x){
	if(x==n+1){ //모든 선수들의 팀을 배치했을 때 
		if(start.size()==n/2 && link.size()==n/2){ //두 팀의 크기가 각각 n/2일 때 
			
			//합을 저장할 변수 초기화 
			startSum=0;
			linkSum=0;
			
			//2중 반복문으로 각 팀의 선수 고르기
			for(int i=0; i<n/2; i++){
				for(int j=i+1; j<n/2; j++){
					if(i==j) continue;
					
					//start팀 2명 골라서 
					start_first=start[i];
					start_second=start[j];
					//start팀 점수 계산
					startSum+=ability[start_first][start_second] + ability[start_second][start_first];
				
					//link팀 2명 골라서 
					link_first=link[i];
					link_second=link[j];
					//link팀 점수 계산
					linkSum+=ability[link_first][link_second] + ability[link_second][link_first];
				}
			}
			
			//절댓값 취해서 최솟값 갱신 
			res=min(res, abs(startSum-linkSum));
		}
		return;
	}
	
	//x번 선수에 대해
	//1) start팀이거나
	start.push_back(x);
	DFS(x+1);
	start.pop_back();
	
	//2) link팀이거나
	link.push_back(x);
	DFS(x+1);
	link.pop_back();
}

int main() {
	freopen("input.txt","rt", stdin);
	scanf("%d", &n); //(4<=n<=20)
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", &ability[i][j]);
		}
	}
	
	DFS(1);
	printf("%d", res);	
	return 0;
}
