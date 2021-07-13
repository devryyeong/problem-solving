//67] 최소비용 (DFS: 인접행렬) 
#include <iostream>
#include <algorithm>
using namespace std;
int map[21][21], ch[21]; 
int n, minn=2147000000;

void DFS(int v, int sum){
	if(v==n){
		if(sum<minn){
			minn=sum;
		}
	}else{ //갈 수 있는지 없는지, 비용 누적합 
		for(int i=1; i<=n; i++){
			if(map[v][i]>0 && ch[i]==0){ //갈 수 있고 방문한적 없으면 
				ch[i]=1;
				DFS(i, sum+map[v][i]); //sum에 가중치(map[v][i]) 더해서 재귀호출
				ch[i]=0;
			}
		}
	}
}
int main(){
	freopen("input.txt", "rt", stdin);
	int a, b, c, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a][b]=c;
	}
	
	ch[1]=1;
	DFS(1,0); //1번부터 출발, sum=0으로 누적 시작 
	printf("%d", minn);
	
	return 0;
}
