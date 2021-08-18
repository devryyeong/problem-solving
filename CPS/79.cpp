//79]  원더랜드(Prim MST 알고리즘 : priority_queue 활용)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int ch[30]; //이미 MST에 추가한 정점인지 확인하기 위한 배열 
struct Edge {
	int e, val; //추가하고자 하는 정점 번호, 가중치 
	Edge(int a, int b){
		e=a;
		val=b;
	}
	bool operator<(const Edge &b) const{
		return val>b.val; //"최소힙"으로 리턴 
	}
};

int main() {
	freopen("input.txt","rt",stdin);
	
	priority_queue<Edge> Q;
	vector<pair<int, int> > map[30]; //가중치 인접리스트 
	int n, m, a, b, c, res=0;
	
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b,c));
		map[b].push_back(make_pair(a,c));
	}
	
	Q.push(Edge(1, 0)); //시작정점은 1번, Q에 push 
	while(!Q.empty()){ //Q가 빌 때까지 반복 
		Edge tmp=Q.top(); //최소힙이므로 top이 최솟값 
		Q.pop(); //시작 정점은 바로 MST에 추가, 그 최솟값 pop 
		
		int v=tmp.e; //Q.top의 정점 
		int cost=tmp.val; //Q.top의 가중치 
		if(ch[v]==0){ //MST에 추가된적 없다면 
			res+=cost; //가중치 누적 
			ch[v]=1; //추가했다고 체크 
			
			//뻗어나갈 수 있는 모든 정점을 반복 
			for(int i=0; i<map[v].size(); i++){
				//현재 정점(v)에서 연결된 정점번호(first), 가중치(second)를 Edge 생성자를 이용해 Q에 push 
				Q.push(Edge(map[v][i].first, map[v][i].second));
			}
		}
	}
	cout<<res;
    return 0;
}
