//61] 특정 수 만들기(DFS: Microsoft 인터뷰) 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, cnt=0, a[11], path[11];

void DFS(int L, int sum){
	if(L==n+1){ //더이상 재귀호출 하지 않아도 되는 조건 
		if(sum==m){
			cnt++;
			for(int i=1; i<L; i++){
				printf("%d ", path[i]);
			}
			puts("");
		}
	}else { //세가지로 가지치기
		path[L]=a[L]; //경로 저장 
		DFS(L+1, sum+a[L]); //가지1: 포함시키면서 + 
		path[L]=-a[L];
		DFS(L+1, sum-a[L]); //가지2: 포함시키면서 - 
		path[L]=0;
		DFS(L+1, sum); //가지3: 포함시키지 않음 
	}
}

int main(){
	freopen("input.txt","rt",stdin);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	DFS(1, 0); //(레벨, 원소의 합)
	if(cnt==0){
		printf("-1");
	}
	printf("%d", cnt);
	return 0;
}

