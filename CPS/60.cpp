//60] ���� ���� �κ�����(DFS: Amazon Interview) 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; //L:binary tree level
int n, total=0, a[11];
bool flag=false;
void DFS(int L, int sum){
	if(flag==true || sum> total/2){
		return;
	}
	
	if(L==n+1){
		if(sum==(total-sum)){
			flag=true;
		}
	}else {
		DFS(L+1, sum+a[L]); //���� ��� �� ���Ҹ� ����ҰŸ� sum�� ��� ������
		DFS(L+1, sum); //������� �����Ÿ� sum��
		/*
		ch[L]=1; //(ó����)�����ڽ����� ������ üũ 
		DFS(L+1); //Level 1 ���� 
		ch[L]=0; //�������ڽ����� ������ üũX 
		DFS(L+1); //Level 1 ����
		*/
	}
}

int main(){
	freopen("input.txt","rt",stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		total+=a[i];
	}
	DFS(1, 0); //����, ������ ��
	
	if(flag){
		printf("YES");
	}else{
		printf("NO");
	}
	return 0;
}

