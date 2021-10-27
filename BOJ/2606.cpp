//2606] ���̷��� 
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int visited[110]; //�湮���� check 
int map[110][110]; //�������
int n, m, x, y, res=-1; //res: 1�� ��ǻ�ʹ� ī��Ʈ���� ����. 

queue<int> Q;

void BFS(int v){
	visited[v]=1; //BFS ���������� �湮üũ 
	Q.push(v); //ť�� �ְ�
	
	while(!Q.empty()){
		v=Q.front(); //v: ť�� �Ǿ�. ������ġ
		Q.pop(); //ť���� ���� ����
		for(int i=1; i<=n; i++){
			//�̹� �湮�߰ų� ����Ǿ����� ������ continue 
			if(visited[i]==1 || map[v][i]==0) continue;
			
			//���� ��찡 �ƴ϶�� �湮üũ ���ְ� ť�� Ǫ�� 
			visited[i]=1;
			Q.push(i);
		}
		res++;
	}
}

int main() {
	//freopen("input.txt","rt", stdin);
	scanf("%d %d", &n, &m); //����, ������ 
	
	for(int i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		map[x][y]=1; //������� �ʱⰪ 
		map[y][x]=1;
	}
	
	BFS(1); //���۳�� 
	printf("%d", res);
	
	return 0;
}
