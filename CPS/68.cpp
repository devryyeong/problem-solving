//68] �ּҺ�� (DFS: ��������Ʈ) 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, minn=2147000000, ch[21];
vector<pair<int, int> > map[30]; //">> operator"�� �νĵ��� �ʵ��� ���� ���� 
void DFS(int v, int sum){
	if(v==n){
		if(sum<minn){
			minn=sum;
		}
	}else{ //�� �� �ִ��� ������, ��� ������ 
		for(int i=0; i<map[v].size(); i++){
			if(ch[map[v][i].first]==0){ //�湮���� ������ 
				ch[map[v][i].first]=1;
				DFS(map[v][i].first, sum+map[v][i].second); //sum�� ����ġ(map[v][i]) ���ؼ� ���ȣ��
				ch[map[v][i].first]=0;
			}
		}
	}
}
int main(){
	freopen("input.txt", "rt", stdin);
	int a, b, c, m;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c); //a���� b�� ���� ����ġ�� c 
		map[a].push_back(make_pair(b,c));
	}
	
	ch[1]=1;
	DFS(1,0); //1������ ���, sum=0���� ���� ���� 
	printf("%d", minn);
	
	return 0;
}
