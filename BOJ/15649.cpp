//15649] N�� M (1) 
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ch[9], res[9];

void DFS(int L){
	if(L==m+1){
		for(int i=1; i<=m; i++){
			printf("%d ", res[i]); 
		}
		puts("");
	}else{
		for(int i=1; i<=n; i++){
			if(!ch[i]){
				ch[i]=1; //(ó����)�����ڽ����� ������ üũ
				res[L]=i; //res�� ������ �� ���� 
				DFS(L+1); //Level 1 ���� 
				ch[i]=0; //�������ڽ����� ������ üũX
			}	
		}	
	}
}

int main() {
	//freopen("input.txt","rt", stdin);
	scanf("%d %d", &n, &m);
	DFS(1);
	
	return 0;
}
