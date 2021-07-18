//70] 그래프 최단거리(BFS)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dis[30]; //최소 간선의 개수 저장
int ch[30]; //방문했었는지 check 

int main(){
	freopen("input.txt", "rt", stdin);
	int n, m, a, b, x;
	vector<int> map[30];
	queue<int> Q;
	
	scanf("%d %d", &n, &m); //n=6, m=9
	for(int i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		map[a].push_back(b); //인접리스트 
	}
	
	//BFS 탐색
	Q.push(1); 
	ch[1]=1;
	while(!Q.empty()){ //front가 더 작으면 값이 들어있음.
		x=Q.front();
		Q.pop(); 
		//printf("%d ", x);
		
		for(int i=0; i<map[x].size(); i++){
			if(ch[map[x][i]]==0){
				ch[map[x][i]]=1;
				Q.push(map[x][i]); //Q에 넣음. 
				dis[map[x][i]]=dis[x]+1; 
			}
		}
	}
	
	for(int j=2; j<=n; j++){
		printf("%d : %d\n", j, dis[j]);
	}
	return 0;
}
