//#49] ����� �ִ�
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
	for(int i=n; i>=1; i--){ //�Ųٷ� �Է¹޾Ƽ� ���� 
		scanf("%d", &right[i]);
	}
	
	//������ �� ���� �ִ밳���� 2���� ���Ϳ� ���� 
	vector<vector<int> > up(n+1, vector<int>(n+1));
	
	//�����ʿ��� �� ������ �� �࿡ ���� 
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
	
	//�� ��� 
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
