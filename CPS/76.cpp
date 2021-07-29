//76] 이항계수(메모이제이션, 동적 계획법) 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dy[21][21];
int DFS(int n, int r){
	if(dy[n][r]>0) return dy[n][r]; //값이 저장되어 있으면 
	if(n==r || r==0) return 1; //조합 그림 참고 
	else return dy[n][r]=DFS(n-1, r-1) + DFS(n-1, r); //이전에 계산한 적이 없으면 dy에 값을 저장해둠. 
}

int main() {
	freopen("input.txt","rt",stdin);
	int n, r,res;
	scanf("%d %d", &n, &r); 
	res=DFS(n,r);
	printf("%d", res);
		
    return 0;
}
