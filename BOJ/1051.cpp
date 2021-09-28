//1051] 숫자 정사각형 
#include <iostream>
#include <algorithm>
#define MAX 51
using namespace std;

int map[MAX][MAX];
int main() {
	freopen("input.txt","rt", stdin);
	
	int n, m, min;
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%1d", &map[i][j]);
		}
	}
	
	//정사각형 한변의 길이 범위 
	if(n<m) min=n;
	else min=m;
	
	while(min){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				//map범위를 벗어남. 
				if(i+min-1>n || j+min-1>m){
					break;
				}
				if(map[i][j]==map[i+min-1][j+min-1] &&
					map[i][j]==map[i][j+min-1] &&
					map[i][j]==map[i+min-1][j]){
						printf("%d", min*min);
						return 0;
				}
			}
		}
		min--;
	}
	
	return 0;
}

