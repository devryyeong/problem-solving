#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; //L:binary tree level
int n, ch[11];
void DFS(int L){ //������ȸ��! 
	if(L==n+1){
		for(int i=1; i<=n; i++){
			if(ch[i]==1){
				printf("%d ", i); //üũ�� �ε�����ȣ(���ҹ�ȣ)��� 
			}
		}
		puts(""); //\n
	}else {
		ch[L]=1; //(ó����)�����ڽ����� ������ üũ 
		DFS(L+1); //Level 1 ���� 
		ch[L]=0; //�������ڽ����� ������ üũX 
		DFS(L+1); //Level 1 ���� 
	}
}

int main(){
	//freopen("input.txt","rt",stdin);
	scanf("%d", &n);
	DFS(1);
	
	return 0;
}


