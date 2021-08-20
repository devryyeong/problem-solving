//81] 벨만-포드 알고리즘 (Bellman-Ford Algorithm)
#include <bits/stdc++.h> 
using namespace std;

int dist[101];

struct Edge{
	int s, e, val;
	Edge(int a, int b, int c){
		s=a;
		e=b;
		val=c;
	}
};

int main(){
	freopen("input.txt","rt", stdin);
	vector<Edge> Ed;
	int n, m, a, b, c, start, end;
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a,b,c));
	}
	for(int i=1; i<=n; i++){
		dist[i]=2147000000; //음의 사이클은 없으므로 일차원배열.	 
	}
	scanf("%d %d", &start, &end);
	dist[start]=0;
	
	for(int i=1; i<n; i++){ //n-1번 돌면서 1번만에/2번만에 
		for(int j=0; j<Ed.size(); j++){ //간선의 개수 
			int u=Ed[j].s; //출발 
			int v=Ed[j].e; //도착 
			int w=Ed[j].val; //가중치
			
			//출발지가 무한대거나, (출발정점+가중치)<기존도착값 
			if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
				dist[v]=dist[u]+w; //값 갱신 
			}
		}
	}
	
	//간선의 개수n개일때 확인(=음의 사이클이 있을 때) 
	for(int j=0; j<Ed.size(); j++){
		int u=Ed[j].s; //출발 
		int v=Ed[j].e; //도착 
		int w=Ed[j].val; //가중치
		
		//출발지가 무한대거나, (출발정점+가중치)<기존도착값 
		if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
			printf("-1");
			exit(0); 
		}
	}
	
	printf("%d", dist[end]);
	return 0;
} 
