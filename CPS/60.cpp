//60] 합이 같은 부분집합(DFS: Amazon Interview) 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; //L:binary tree level
int n, total=0, a[11];
bool flag=false;
void DFS(int L, int sum){
	if(flag==true || sum> total/2){
		return;
	}
	
	if(L==n+1){
		if(sum==(total-sum)){
			flag=true;
		}
	}else {
		DFS(L+1, sum+a[L]); //가지 뻗어간 그 원소를 사용할거면 sum이 계속 누적됨
		DFS(L+1, sum); //사용하지 않을거면 sum만
		/*
		ch[L]=1; //(처음엔)왼쪽자식으로 갈때는 체크 
		DFS(L+1); //Level 1 증가 
		ch[L]=0; //오른쪽자식으로 갈때는 체크X 
		DFS(L+1); //Level 1 증가
		*/
	}
}

int main(){
	freopen("input.txt","rt",stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		total+=a[i];
	}
	DFS(1, 0); //레벨, 원소의 합
	
	if(flag){
		printf("YES");
	}else{
		printf("NO");
	}
	return 0;
}

