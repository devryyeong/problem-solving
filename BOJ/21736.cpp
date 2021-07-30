//21736] 헌내기는 친구가 필요해 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[601];
int ch[601][601];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int n, m, res;

void DFS(int x, int y){
	int nx, ny; //앞으로 이동할 좌표
	
	if(s[x][y]=='P'){
		res++;
	}
	for(int i=0; i<4; i++){
		nx=x+dx[i];
		ny=y+dy[i];
		
		if(nx<0 || ny<0 || nx>=n || ny>=m){ //캠퍼스의 끝이면 
			continue;	
		}
		if(s[nx][ny]!='X' && ch[nx][ny]==0){ //벽이 아니고, 방문한적이 없다면 
			ch[nx][ny]=1;
			DFS(nx, ny);
		}
		
		/*
		if(nx>=0 && ny>=0 && nx<n && ny<m && ch[nx][ny]==0){
			if(s[nx][ny]!='X'){
				ch[nx][ny]=1;
				DFS(nx, ny);
			}
		}
		*/	
	}
			
}

int main() {
	freopen("input.txt","rt", stdin);
	
	int ii, jj; //DFS() 호출을 위한 임시변수 
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(s[i][j]=='I'){
				ch[i][j]=1; //방문체크 
				ii=i;
				jj=j;
			}
		}
	}
	
	DFS(ii, jj);
	
	if(res==0){
		printf("TT");
	}else{
		printf("%d", res);
	}
	
	return 0;
}
