//���� ���ϱ� 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, r;
int ch[20]; //������ ���ҵ��� ���� �迭 

void DFS(int s, int L){
	if(L==r){ //������ ���� 
		for(int j=0; j<L; j++){
			printf("%d ",ch[j]);
		}
		puts("");
	}else{ //���� ����� 
		for(int i=s; i<n; i++){
			ch[L]=i;
			DFS(i+1, L+1);
		} 
	}
	
}
int main() {
	freopen("input.txt","rt", stdin);
	scanf("%d %d", &n, &r);
	DFS(0,0);
	return 0;
}
