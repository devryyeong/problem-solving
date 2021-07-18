//71] �۾��� ã�� (BFS) 
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int ch[10001]; //�湮�߾����� check 
int jump[10001]; //jump Ƚ��
int move[]={1, 5, -1};// 3������ ����� ���� ���� 

int main(){
	freopen("input.txt", "rt", stdin);
	int s, e, x, pos, cnt=0;
	queue<int> Q;
	scanf("%d %d", &s, &e); //5, 14
	
	//BFS Ž��
	Q.push(s); 
	ch[s]=1; //ch[5]=1
	while(!Q.empty()){ //Q�� ������� ������ 
		x=Q.front(); //x�� Q���� ���� ���� ���� 
		Q.pop();

		for(int i=0; i<3; i++){
			pos = x + move[i]; //6
			
			//��ǥ ����(1~10000)�� ����� �� ó��
			if(pos<=0 || pos>10000){
				continue;
			}
			
			if(pos==e){
				printf("%d", jump[x]+1);
				return 0;
			}
			if(ch[pos]==0){
				ch[pos]=1; //�湮�߾��ٰ� check 
				jump[pos]=jump[x]+1; //s���� x���� ���µ��� �ּ�Ƚ��
				
				Q.push(pos);
			}
		}
		
	}
	return 0;
}
