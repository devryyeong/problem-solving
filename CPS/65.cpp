//65] 미로 탐색(DFS)
#include <iostream>
#include <algorithm>
using namespace std;
int cnt=0;
int map[10][10], ch[10][10]; //ch:방문했는지 check
int dx[4]={-1,0,1,0}; //12시-3시-6시-9시 방향 순으로 탐색 
int dy[4]={0,1,0,-1};

void DFS(int x, int y){ 
	int xx, yy; //앞으로 이동할 좌표 
	if(x==7 && y==7){
		cnt++;
	}else{ //갈 수 있는지 없는지
		for(int i=0; i<4; i++){
			xx=x+dx[i];
			yy=y+dy[i];
			if(xx<1 || xx>7 || yy<1 || yy>7){ //격자판의 끝 
				continue;
			}
			if(map[xx][yy]==0 && ch[xx][yy]==0){ //길이 있고, 방문한적 없다면 
				ch[xx][yy]=1;
				DFS(xx, yy);
				ch[xx][yy]=0;
			}
		}
				
	}
}

int main(){
	freopen("input.txt","rt",stdin);
	
	for(int i=1; i<=7; i++){
		for(int j=1; j<=7; j++){
			scanf("%d", &map[i][j]);
		}	
	}
	
	ch[1][1]=1; 
	DFS(1,1);
	printf("%d", cnt);
	return 0;
}
