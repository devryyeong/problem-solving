//15649] N과 M (1) 
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ch[9], res[9];

void DFS(int L){
	if(L==m+1){
		for(int i=1; i<=m; i++){
			printf("%d ", res[i]); 
		}
		puts("");
	}else{
		for(int i=1; i<=n; i++){
			if(!ch[i]){
				ch[i]=1; //(처음엔)왼쪽자식으로 갈때는 체크
				res[L]=i; //res에 선택한 수 저장 
				DFS(L+1); //Level 1 증가 
				ch[i]=0; //오른쪽자식으로 갈때는 체크X
			}	
		}	
	}
}

int main() {
	//freopen("input.txt","rt", stdin);
	scanf("%d %d", &n, &m);
	DFS(1);
	
	return 0;
}
