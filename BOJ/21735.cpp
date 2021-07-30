//21735] 눈덩이 굴리기 
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, res=-2147000000;
int map[101];

void DFS(int l, int val, int mv){
	if(l==m){ //시간되면 눈덩이 크기 비교해서 최댓값 저장 
		res=max(res, val);
		return;
	}else{
	 //굴리고(+1) 그대로 더하거나, 던지고(+2) 절반 깎은다음 더하거나 
		DFS(l+1, val+map[mv+1], mv+1);
		DFS(l+1, val/2+map[mv+2], mv+2);
	}		
}

int main() {
	freopen("input.txt","rt", stdin);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &map[i]);
	}
	
	DFS(0, 1, 0); //level, value, move(m만큼) 
	printf("%d", res);
	return 0;
}
