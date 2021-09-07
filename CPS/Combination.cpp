//조합 구하기 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, r;
int ch[20]; //조합의 원소들을 넣을 배열 

void DFS(int s, int L){
	if(L==r){ //종착점 조건 
		for(int j=0; j<L; j++){
			printf("%d ",ch[j]);
		}
		puts("");
	}else{ //가지 뻗어나감 
		for(int i=s; i<n; i++){
			ch[L]=i;
			DFS(i+1, L+1);
		} 
	}
	
}
int main() {
	freopen("input.txt","rt", stdin);
	scanf("%d %d", &n, &r);
	DFS(0,0);
	return 0;
}
