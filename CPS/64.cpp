//63] ��� Ž��(DFS)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//ch[21] : �湮�ߴ� ������ üũ 
int n, m, cnt=0, map[21][21], ch[21];

void DFS(int vertex){ //vertex: ���� ��ġ�� ���� 
	if(vertex==n){
		cnt++; 
	}else{ //�� �� �ִ��� ������
		for(int i=1; i<=n; i++){
			if(map[vertex][i]==1 && ch[i]==0){ //�� �� �ִ� ���� �ְ�, �湮���� ���ٸ� 
				ch[i]=1; //���� ���� �Ѿ
				DFS(i); //�� ȣ���ϰ� �ٽ� �ڷ�(���ڸ���)��.
				ch[i]=0; //ch�迭(���) �ʱ�ȭ.(�ѹ� N���� ���� üũ�� ������ �ʱ�ȭ�� �ؾ� �ٽ� ���� ��θ� �� �� ����)
			}
		} 
	}
}

int main(){
	//freopen("input.txt","rt",stdin);
	int a, b;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		map[a][b]=1;
	}
	ch[1]=1; 
	DFS(1);
	printf("%d", cnt);
	return 0;
}
