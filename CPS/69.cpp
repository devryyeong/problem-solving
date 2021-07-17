//69] ����Ʈ�� ���̿켱Ž��(BFS) (QUEUE ��������) 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int Q[100];
int front=-1; //Q���� �� ���� front 
int rear=-1; //Q���� ���� ���� rear(back) 
int ch[10]; //�������̹Ƿ� ch[] �ʿ�. 
vector<int> map[10];

int main(){
	freopen("input.txt", "rt", stdin);
	int a, b, x;
	for(int i=1; i<=6; i++){
		scanf("%d %d", &a, &b);
		map[a].push_back(b); //������ 
		map[b].push_back(a); //������ 
	}
	
	Q[++rear]=1;
	ch[1]=1;
	
	while(front<rear){ //front�� �� ������ ���� �������.
		x=Q[++front]; //x��� ������ Q�� �ڷḦ �ϳ� ������ ����. 
		printf("%d ", x);
		for(int i=0; i<map[x].size(); i++){
			if(ch[map[x][i]]==0){
				ch[map[x][i]]=1;
				Q[++rear]=map[x][i]; //Q�� ����. 
			}
		}
	}
	
	return 0;
}
