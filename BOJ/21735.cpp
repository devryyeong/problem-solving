//21735] ������ ������ 
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, res=-2147000000;
int map[101];

void DFS(int l, int val, int mv){
	if(l==m){ //�ð��Ǹ� ������ ũ�� ���ؼ� �ִ� ���� 
		res=max(res, val);
		return;
	}else{
	 //������(+1) �״�� ���ϰų�, ������(+2) ���� �������� ���ϰų� 
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
	
	DFS(0, 1, 0); //level, value, move(m��ŭ) 
	printf("%d", res);
	return 0;
}
