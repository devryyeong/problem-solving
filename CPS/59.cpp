#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; //L:binary tree level
int n, ch[11];
void DFS(int L){ //전위순회로! 
	if(L==n+1){
		for(int i=1; i<=n; i++){
			if(ch[i]==1){
				printf("%d ", i); //체크된 인덱스번호(원소번호)출력 
			}
		}
		puts(""); //\n
	}else {
		ch[L]=1; //(처음엔)왼쪽자식으로 갈때는 체크 
		DFS(L+1); //Level 1 증가 
		ch[L]=0; //오른쪽자식으로 갈때는 체크X 
		DFS(L+1); //Level 1 증가 
	}
}

int main(){
	//freopen("input.txt","rt",stdin);
	scanf("%d", &n);
	DFS(1);
	
	return 0;
}


