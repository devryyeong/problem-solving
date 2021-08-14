//78]  원더랜드(Kruskal MST 알고리즘 : Union&Find 활용)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int unf[10001];
struct Edge {
	int v1, v2, val; //정점1, 정점2, 가중치 
	Edge(int a, int b, int c){
		v1=a;
		v2=b;
		val=c;
	}
	bool operator<(Edge &b){ //연산자 오버로딩 
		return val<b.val; //val 기준 오름차순 정렬 
	}
};

int Find(int v){
	if(v==unf[v]) return v;
	else return unf[v]=Find(unf[v]);
}

void Union(int a, int b){ 
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	int n, m, a, b, c, res=0;
	vector<Edge> Ed;
	
	cin>>n>>m; //정점, 간선 개수 

	for(int i=1; i<=n; i++){  
		unf[i]=i; 
	}
	for(int i=1; i<=m; i++){
		cin>>a>>b>>c;
		Ed.push_back(Edge(a, b, c));
	} 
	sort(Ed.begin(), Ed.end()); //가중치 기준 오름차순 
	
	//0번부터 간선을 선택할건지, 안할건지
	//Union&Find Algorithm으로 사이클 생성 여부 체크
	//추가하고자 하는 간선의 양끝 정점이 같은 집합에 속해 있는지 
	for(int i=0; i<m; i++){
		int fa=Find(Ed[i].v1);
		int fb=Find(Ed[i].v2);
		
		if(fa!=fb){ //이어져있지 않고 사이클도 안되면 
			res+=Ed[i].val; //가중치 누적하고 
			Union(Ed[i].v1, Ed[i].v2); //Union화 해줌 
		}
	} 
	
	
	cout<<res;
    return 0;
}
