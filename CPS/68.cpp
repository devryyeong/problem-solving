//68] 최소비용 (DFS: 인접리스트) 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, minn=2147000000, ch[21];
vector<pair<int, int> > map[30]; //">> operator"로 인식되지 않도록 띄어쓰기 주의 
void DFS(int v, int sum){
	if(v==n){
		if(sum<minn){
			minn=sum;
		}
	}else{ //갈 수 있는지 없는지, 비용 누적합 
		for(int i=0; i<map[v].size(); i++){
			if(ch[map[v][i].first]==0){ //방문한적 없으면 
				ch[map[v][i].first]=1;
				DFS(map[v][i].first, sum+map[v][i].second); //sum에 가중치(map[v][i]) 더해서 재귀호출
				ch[map[v][i].first]=0;
			}
		}
	}
}
int main(){
	freopen("input.txt", "rt", stdin);
	int a, b, c, m;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c); //a에서 b로 갈때 가중치값 c 
		map[a].push_back(make_pair(b,c));
	}
	
	ch[1]=1;
	DFS(1,0); //1번부터 출발, sum=0으로 누적 시작 
	printf("%d", minn);
	
	return 0;
}
