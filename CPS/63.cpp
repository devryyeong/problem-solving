//63] �������(����ġ ����׷���)  
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int map[51][51]; //�ε���1���� ����� 
int main(){
	freopen("input.txt","rt",stdin);
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a][b]=c;
	}
	
	for(int j=1; j<=n; j++){
		for(int k=1; k<=n; k++){
			printf("%d ", map[j][k]);
		}
		printf("\n");
	}
	return 0;
}

