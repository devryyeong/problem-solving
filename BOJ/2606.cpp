//2606] 바이러스 
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int visited[110]; //방문여부 check 
int map[110][110]; //인접행렬
int n, m, x, y, res=-1; //res: 1번 컴퓨터는 카운트하지 않음. 

queue<int> Q;

void BFS(int v){
	visited[v]=1; //BFS 시작정점에 방문체크 
	Q.push(v); //큐에 넣고
	
	while(!Q.empty()){
		v=Q.front(); //v: 큐의 맨앞. 현재위치
		Q.pop(); //큐에서 꺼낸 다음
		for(int i=1; i<=n; i++){
			//이미 방문했거나 연결되어있지 않으면 continue 
			if(visited[i]==1 || map[v][i]==0) continue;
			
			//위의 경우가 아니라면 방문체크 해주고 큐에 푸시 
			visited[i]=1;
			Q.push(i);
		}
		res++;
	}
}

int main() {
	//freopen("input.txt","rt", stdin);
	scanf("%d %d", &n, &m); //정점, 간선수 
	
	for(int i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		map[x][y]=1; //인접행렬 초기값 
		map[y][x]=1;
	}
	
	BFS(1); //시작노드 
	printf("%d", res);
	
	return 0;
}
