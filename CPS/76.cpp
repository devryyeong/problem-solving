//76] ���װ��(�޸������̼�, ���� ��ȹ��) 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dy[21][21];
int DFS(int n, int r){
	if(dy[n][r]>0) return dy[n][r]; //���� ����Ǿ� ������ 
	if(n==r || r==0) return 1; //���� �׸� ���� 
	else return dy[n][r]=DFS(n-1, r-1) + DFS(n-1, r); //������ ����� ���� ������ dy�� ���� �����ص�. 
}

int main() {
	freopen("input.txt","rt",stdin);
	int n, r,res;
	scanf("%d %d", &n, &r); 
	res=DFS(n,r);
	printf("%d", res);
		
    return 0;
}
