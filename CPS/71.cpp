//71] 송아지 찾기 (BFS) 
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int ch[10001]; //방문했었는지 check 
int jump[10001]; //jump 횟수
int move[]={1, 5, -1};// 3가지의 경우의 수가 존재 

int main(){
	freopen("input.txt", "rt", stdin);
	int s, e, x, pos, cnt=0;
	queue<int> Q;
	scanf("%d %d", &s, &e); //5, 14
	
	//BFS 탐색
	Q.push(s); 
	ch[s]=1; //ch[5]=1
	while(!Q.empty()){ //Q가 비어있지 않으면 
		x=Q.front(); //x에 Q에서 꺼낸 수를 넣음 
		Q.pop();

		for(int i=0; i<3; i++){
			pos = x + move[i]; //6
			
			//좌표 범위(1~10000)를 벗어났을 때 처리
			if(pos<=0 || pos>10000){
				continue;
			}
			
			if(pos==e){
				printf("%d", jump[x]+1);
				return 0;
			}
			if(ch[pos]==0){
				ch[pos]=1; //방문했었다고 check 
				jump[pos]=jump[x]+1; //s에서 x까지 가는데에 최소횟수
				
				Q.push(pos);
			}
		}
		
	}
	return 0;
}
