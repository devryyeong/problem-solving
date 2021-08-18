//80]  다익스트라 알고리즘 (Dijkstra Algorithm) 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
 
struct Edge {
	int vex, dis; //vertax(정점번호), distance(가중치) 
	Edge(int a, int b){
		vex=a;
		dis=b;
	}
	bool operator<(const Edge &b) const{
		return dis>b.dis; //"최소힙"
	}
};

int main() {
	freopen("input.txt","rt",stdin);
	
	priority_queue<Edge> Q;
	vector<pair<int, int> > graph[30]; //가중치 인접리스트 
	int n, m, a, b, c;
	
	scanf("%d %d", &n, &m);
	vector<int> dist(n+1, 2147000000); //infinite(int형의 최대용량인 2^31-1)로 초기화
	 
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(make_pair(b,c));
	}
	
	Q.push(Edge(1, 0)); //시작정점은 1번, Q에 push
	dist[1]=0;
	while(!Q.empty()){ //Q가 빌 때까지 반복 
		int now=Q.top().vex; //top의 정점번호 (최소힙이므로 top이 무조건 최솟값) 
		int cost=Q.top().dis; //top의 가중치 
		Q.pop();
		
		if(cost>dist[now]) continue; //계산한 cost가 더 크면 continue 
		for(int i=0; i<graph[now].size(); i++){ //now정점과 연결된 인접리스트 탐색 
			int nextVex=graph[now][i].first; //now정점과 연결된 정점 
			int nextDis=cost+graph[now][i].second; //가중치 계산 
			
			if(dist[nextVex]>nextDis){ //계산한 nextDis가 기존 dist배열값보다 작으면 
				dist[nextVex]=nextDis; //dist배열 값을 바꿔주고 
				Q.push(Edge(nextVex, nextDis)); //Q에 push 
			}
		}
	}
	
	//출력
	for(int j=2; j<=n; j++){
		if(dist[j]!=2147000000){
			printf("%d : %d\n", j, dist[j]);
		}else{
			printf("%d : impossible\n", j);
		}
	} 
	
    return 0;
}
