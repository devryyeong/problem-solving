//80]  ���ͽ�Ʈ�� �˰��� (Dijkstra Algorithm) 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
 
struct Edge {
	int vex, dis; //vertax(������ȣ), distance(����ġ) 
	Edge(int a, int b){
		vex=a;
		dis=b;
	}
	bool operator<(const Edge &b) const{
		return dis>b.dis; //"�ּ���"
	}
};

int main() {
	freopen("input.txt","rt",stdin);
	
	priority_queue<Edge> Q;
	vector<pair<int, int> > graph[30]; //����ġ ��������Ʈ 
	int n, m, a, b, c;
	
	scanf("%d %d", &n, &m);
	vector<int> dist(n+1, 2147000000); //infinite(int���� �ִ�뷮�� 2^31-1)�� �ʱ�ȭ
	 
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(make_pair(b,c));
	}
	
	Q.push(Edge(1, 0)); //���������� 1��, Q�� push
	dist[1]=0;
	while(!Q.empty()){ //Q�� �� ������ �ݺ� 
		int now=Q.top().vex; //top�� ������ȣ (�ּ����̹Ƿ� top�� ������ �ּڰ�) 
		int cost=Q.top().dis; //top�� ����ġ 
		Q.pop();
		
		if(cost>dist[now]) continue; //����� cost�� �� ũ�� continue 
		for(int i=0; i<graph[now].size(); i++){ //now������ ����� ��������Ʈ Ž�� 
			int nextVex=graph[now][i].first; //now������ ����� ���� 
			int nextDis=cost+graph[now][i].second; //����ġ ��� 
			
			if(dist[nextVex]>nextDis){ //����� nextDis�� ���� dist�迭������ ������ 
				dist[nextVex]=nextDis; //dist�迭 ���� �ٲ��ְ� 
				Q.push(Edge(nextVex, nextDis)); //Q�� push 
			}
		}
	}
	
	//���
	for(int j=2; j<=n; j++){
		if(dist[j]!=2147000000){
			printf("%d : %d\n", j, dist[j]);
		}else{
			printf("%d : impossible\n", j);
		}
	} 
	
    return 0;
}
