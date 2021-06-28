//61] Ư�� �� �����(DFS: Microsoft ���ͺ�) 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, cnt=0, a[11];
bool flag=false;
void DFS(int L, int sum){
	if(L==n+1){ //���̻� ���ȣ�� ���� �ʾƵ� �Ǵ� ���� 
		if(sum==m){
			cnt++;
		}
	}else { //�������� ����ġ�� 
		DFS(L+1, sum+a[L]); //����1: ���Խ�Ű�鼭 + 
		DFS(L+1, sum-a[L]); //����2: ���Խ�Ű�鼭 - 
		DFS(L+1, sum); //����3: ���Խ�Ű�� ���� 
	}
}

int main(){
	//freopen("input.txt","rt",stdin);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	DFS(1, 0); //(����, ������ ��)
	printf("%d", cnt);
	return 0;
}

