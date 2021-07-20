//#49] 블록의 최댓값
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	freopen("input.txt","rt",stdin);
	int n, row, col, sum=0;
	scanf("%d", &n); 
	vector<int> front(n+1), right(n+1);
	for(int i=1; i<=n; i++){
		scanf("%d", &front[i]);
	}
	for(int i=n; i>=1; i--){ //거꾸로 입력받아서 저장 
		scanf("%d", &right[i]);
	}
	
	//위에서 본 높이 최대개수를 2차원 벡터에 저장 
	vector<vector<int> > up(n+1, vector<int>(n+1));
	
	//오른쪽에서 본 개수를 각 행에 저장 
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			up[i][j]=right[i];
		}
	}
	
	for(int col=1; col<=n; col++){
		for(row=1; row<=n; row++){
			if(front[col] < up[row][col]){
				up[row][col]=front[col];
			}
		}		
	}
	
	//합 계산 
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			sum+=up[i][j];
			//printf("%d ", up[i][j]);
		}
		//printf("\n");
	} 
	printf("%d", sum);
	return 0;
}
