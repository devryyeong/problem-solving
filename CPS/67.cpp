//67] �ּҺ�� (DFS: �������) 
#include <iostream>
#include <algorithm>
using namespace std;
int map[21][21], ch[21]; 
int n, minn=2147000000;

void DFS(int v, int sum){
	if(v==n){
		if(sum<minn){
			minn=sum;
		}
	}else{ //�� �� �ִ��� ������, ��� ������ 
		for(int i=1; i<=n; i++){
			if(map[v][i]>0 && ch[i]==0){ //�� �� �ְ� �湮���� ������ 
				ch[i]=1;
				DFS(i, sum+map[v][i]); //sum�� ����ġ(map[v][i]) ���ؼ� ���ȣ��
				ch[i]=0;
			}
		}
	}
}
int main(){
	freopen("input.txt", "rt", stdin);
	int a, b, c, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a][b]=c;
	}
	
	ch[1]=1;
	DFS(1,0); //1������ ���, sum=0���� ���� ���� 
	printf("%d", minn);
	
	return 0;
}
