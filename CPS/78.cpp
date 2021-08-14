//78]  ��������(Kruskal MST �˰��� : Union&Find Ȱ��)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int unf[10001];
struct Edge {
	int v1, v2, val; //����1, ����2, ����ġ 
	Edge(int a, int b, int c){
		v1=a;
		v2=b;
		val=c;
	}
	bool operator<(Edge &b){ //������ �����ε� 
		return val<b.val; //val ���� �������� ���� 
	}
};

int Find(int v){
	if(v==unf[v]) return v;
	else return unf[v]=Find(unf[v]);
}

void Union(int a, int b){ 
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	int n, m, a, b, c, res=0;
	vector<Edge> Ed;
	
	cin>>n>>m; //����, ���� ���� 

	for(int i=1; i<=n; i++){  
		unf[i]=i; 
	}
	for(int i=1; i<=m; i++){
		cin>>a>>b>>c;
		Ed.push_back(Edge(a, b, c));
	} 
	sort(Ed.begin(), Ed.end()); //����ġ ���� �������� 
	
	//0������ ������ �����Ұ���, ���Ұ���
	//Union&Find Algorithm���� ����Ŭ ���� ���� üũ
	//�߰��ϰ��� �ϴ� ������ �糡 ������ ���� ���տ� ���� �ִ��� 
	for(int i=0; i<m; i++){
		int fa=Find(Ed[i].v1);
		int fb=Find(Ed[i].v2);
		
		if(fa!=fb){ //�̾������� �ʰ� ����Ŭ�� �ȵǸ� 
			res+=Ed[i].val; //����ġ �����ϰ� 
			Union(Ed[i].v1, Ed[i].v2); //Unionȭ ���� 
		}
	} 
	
	
	cout<<res;
    return 0;
}
