//1012] 유기농 베추 (BFS)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int dX[4]={0,0,1,-1};
int dY[4]={1,-1,0,0};
int map[51][51];
struct Loc{
	int x;
	int y;
	Loc(int a, int b){
		x=a;
		y=b;
	}
};
queue<Loc> Q;

int main() {
	freopen("input.txt","rt", stdin);
	int t, m, n, k, x, y;
	scanf("%d", &t);
	
	while(t--){
		//변수 초기화 && 입력 
		int res=0;
		memset(map, 0, sizeof(map));
		scanf("%d %d %d", &m, &n, &k);
		for(int i=0; i<k; i++){
			scanf("%d %d", &x, &y);
			map[x][y]=1;
		}
		
		//BFS
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(map[i][j]==1){
					Q.push(Loc(i,j));
					map[i][j]=0;
					
					while(!Q.empty()){
						Loc tmp=Q.front();
						Q.pop();
						
						//상하좌우 탐색
						for(int l=0; l<4; l++){
							int xx=tmp.x+dX[l];
							int yy=tmp.y+dY[l];
							
							if(xx<0 || xx>=m || yy<0 || yy>=n || map[xx][yy]==0) continue;
							if(map[xx][yy]==1){
								Q.push(Loc(xx, yy));
								map[xx][yy]=0;
							}
						}
					}
					res++;
				}
			}
		}
		
		printf("%d\n", res);
	}
	return 0;
}

