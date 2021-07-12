//66] 경로탐색(DFS: 인접리스트) 경로까지 출력해보기 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cnt=0, n, ch[30], path[30];
vector<int> map[30];

void DFS(int v, int p){
	if(v==n){
		cnt++;
		for(int j=0; j<p; j++){
			printf("%d ", path[j]);
		}
		puts("");
	}else{
		for(int i=0; i<map[v].size(); i++){
			if(ch[map[v][i]]==0){
				ch[map[v][i]]=1;
				path[p]=map[v][i];
				DFS(map[v][i], p+1);
				ch[map[v][i]]=0;
			}
		}
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
	int m,a,b;
	scanf("%d %d", &n, &m); //5, 9
	for(int i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		map[a].push_back(b); //인접리스트 
	}
	ch[1]=1;
	path[0]=1;
	DFS(1,1);
	printf("%d", cnt);
	return 0;
}
