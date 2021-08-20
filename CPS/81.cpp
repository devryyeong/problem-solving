//81] ����-���� �˰��� (Bellman-Ford Algorithm)
#include <bits/stdc++.h> 
using namespace std;

int dist[101];

struct Edge{
	int s, e, val;
	Edge(int a, int b, int c){
		s=a;
		e=b;
		val=c;
	}
};

int main(){
	freopen("input.txt","rt", stdin);
	vector<Edge> Ed;
	int n, m, a, b, c, start, end;
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a,b,c));
	}
	for(int i=1; i<=n; i++){
		dist[i]=2147000000; //���� ����Ŭ�� �����Ƿ� �������迭.	 
	}
	scanf("%d %d", &start, &end);
	dist[start]=0;
	
	for(int i=1; i<n; i++){ //n-1�� ���鼭 1������/2������ 
		for(int j=0; j<Ed.size(); j++){ //������ ���� 
			int u=Ed[j].s; //��� 
			int v=Ed[j].e; //���� 
			int w=Ed[j].val; //����ġ
			
			//������� ���Ѵ�ų�, (�������+����ġ)<���������� 
			if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
				dist[v]=dist[u]+w; //�� ���� 
			}
		}
	}
	
	//������ ����n���϶� Ȯ��(=���� ����Ŭ�� ���� ��) 
	for(int j=0; j<Ed.size(); j++){
		int u=Ed[j].s; //��� 
		int v=Ed[j].e; //���� 
		int w=Ed[j].val; //����ġ
		
		//������� ���Ѵ�ų�, (�������+����ġ)<���������� 
		if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
			printf("-1");
			exit(0); 
		}
	}
	
	printf("%d", dist[end]);
	return 0;
} 
