//63] 경로 탐색(DFS)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//ch[21] : 방문했던 곳인지 체크 
int n, m, cnt=0, map[21][21], ch[21];

void DFS(int vertex){ //vertex: 현재 위치의 정점 
	if(vertex==n){
		cnt++; 
	}else{ //갈 수 있는지 없는지
		for(int i=1; i<=n; i++){
			if(map[vertex][i]==1 && ch[i]==0){ //갈 수 있는 길이 있고, 방문한적 없다면 
				ch[i]=1; //다음 노드로 넘어감
				DFS(i); //다 호출하고 다시 뒤로(제자리로)옴.
				ch[i]=0; //ch배열(경로) 초기화.(한번 N으로 가서 체크가 됐으면 초기화를 해야 다시 다음 경로를 셀 수 있음)
			}
		} 
	}
}

int main(){
	//freopen("input.txt","rt",stdin);
	int a, b;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		map[a][b]=1;
	}
	ch[1]=1; 
	DFS(1);
	printf("%d", cnt);
	return 0;
}
