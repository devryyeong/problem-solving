//60] 합이 같은 부분집합(DFS: Amazon Interview) 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; //L:binary tree level
int n, total=0, a[11];
bool flag=false;
void DFS(int L, int sum){
	if(flag==true || sum> total/2){ //sum을 누적해가다가 (2/total)보다 커지면 어처피 합이 같은 부분집합이 나올 수 없으므로 더이상 가지치기를 해볼 필요가 없음
		return;
	}
	
	if(L==n+1){ ////더이상 재귀호출 하지 않아도 되는 조건
		if(sum==(total-sum)){
			flag=true;
		}
	}else { //두가지로 가지치기
		DFS(L+1, sum+a[L]); //가지 뻗어간 그 원소를 사용할거면 sum이 계속 누적됨
		DFS(L+1, sum); //사용하지 않을거면 sum은 두고 레벨만+1
	}
}

int main(){
	freopen("input.txt","rt",stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		total+=a[i];
	}
	DFS(1, 0); //(레벨, 원소의 합)
	
	if(flag){
		printf("YES");
	}else{
		printf("NO");
	}
	return 0;
}

