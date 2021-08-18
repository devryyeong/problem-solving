//79]  ��������(Prim MST �˰��� : priority_queue Ȱ��)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int ch[30]; //�̹� MST�� �߰��� �������� Ȯ���ϱ� ���� �迭 
struct Edge {
	int e, val; //�߰��ϰ��� �ϴ� ���� ��ȣ, ����ġ 
	Edge(int a, int b){
		e=a;
		val=b;
	}
	bool operator<(const Edge &b) const{
		return val>b.val; //"�ּ���"���� ���� 
	}
};

int main() {
	freopen("input.txt","rt",stdin);
	
	priority_queue<Edge> Q;
	vector<pair<int, int> > map[30]; //����ġ ��������Ʈ 
	int n, m, a, b, c, res=0;
	
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b,c));
		map[b].push_back(make_pair(a,c));
	}
	
	Q.push(Edge(1, 0)); //���������� 1��, Q�� push 
	while(!Q.empty()){ //Q�� �� ������ �ݺ� 
		Edge tmp=Q.top(); //�ּ����̹Ƿ� top�� �ּڰ� 
		Q.pop(); //���� ������ �ٷ� MST�� �߰�, �� �ּڰ� pop 
		
		int v=tmp.e; //Q.top�� ���� 
		int cost=tmp.val; //Q.top�� ����ġ 
		if(ch[v]==0){ //MST�� �߰����� ���ٸ� 
			res+=cost; //����ġ ���� 
			ch[v]=1; //�߰��ߴٰ� üũ 
			
			//����� �� �ִ� ��� ������ �ݺ� 
			for(int i=0; i<map[v].size(); i++){
				//���� ����(v)���� ����� ������ȣ(first), ����ġ(second)�� Edge �����ڸ� �̿��� Q�� push 
				Q.push(Edge(map[v][i].first, map[v][i].second));
			}
		}
	}
	cout<<res;
    return 0;
}
